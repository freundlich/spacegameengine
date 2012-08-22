/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2012 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <sge/console/exception.hpp>
#include <sge/console/gfx.hpp>
#include <sge/console/object.hpp>
#include <sge/console/output_line_limit.hpp>
#include <sge/console/sprite_object.hpp>
#include <sge/font/align_h.hpp>
#include <sge/font/lit.hpp>
#include <sge/font/object_fwd.hpp>
#include <sge/font/rect.hpp>
#include <sge/font/string.hpp>
#include <sge/font/text_parameters.hpp>
#include <sge/font/unit.hpp>
#include <sge/font/vector.hpp>
#include <sge/font/draw/static_text.hpp>
#include <sge/image/color/any/object.hpp>
#include <sge/input/keyboard/char_event.hpp>
#include <sge/input/keyboard/device.hpp>
#include <sge/input/keyboard/key_event.hpp>
#include <sge/input/keyboard/key_repeat_event.hpp>
#include <sge/renderer/context/object_fwd.hpp>
#include <sge/sprite/buffers/option.hpp>
#include <sge/sprite/buffers/single_impl.hpp>
#include <sge/sprite/buffers/with_declaration_impl.hpp>
#include <sge/sprite/process/one.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <locale>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

sge::console::gfx::gfx(
	sge::console::object &_object,
	sge::renderer::device &_renderer,
	sge::image::color::any::object const &_font_color,
	sge::font::object &_font_object,
	sge::input::keyboard::device &_keyboard,
	sge::console::sprite_object const &_background,
	sge::console::output_line_limit const _line_limit
)
:
	object_(
		_object
	),
	renderer_(
		_renderer
	),
	font_color_(
		_font_color
	),
	font_object_(
		_font_object
	),
	keyboard_(
		_keyboard
	),
	key_connection_(
		keyboard_.key_callback(
			std::tr1::bind(
				&gfx::key_callback,
				this,
				std::tr1::placeholders::_1
			)
		)
	),
	key_repeat_connection_(
		keyboard_.key_repeat_callback(
			std::tr1::bind(
				&gfx::key_action,
				this,
				std::tr1::placeholders::_1
			)
		)
	),
	char_connection_(
		_keyboard.char_callback(
			std::tr1::bind(
				&gfx::char_callback,
				this,
				std::tr1::placeholders::_1
			)
		)
	),
	error_conn_(
		object_.register_error_callback(
			std::tr1::bind(
				&gfx::error,
				this,
				std::tr1::placeholders::_1
			)
		)
	),
	message_conn_(
		object_.register_message_callback(
			std::tr1::bind(
				&gfx::print,
				this,
				std::tr1::placeholders::_1
			)
		)
	),
	sprite_buffers_(
		_renderer,
		sge::sprite::buffers::option::dynamic
	),
	background_(
		_background
	),
	active_(
		false
	),
	input_line_(),
	input_history_(),
	current_input_(
		input_history_.begin()
	),
	output_lines_(
		_line_limit
	)
{
}

FCPPT_PP_POP_WARNING

sge::console::gfx::~gfx()
{
}

void
sge::console::gfx::render(
	sge::renderer::context::object &_render_context
)
{
	sge::sprite::process::one(
		_render_context,
		background_,
		sprite_buffers_
	);

	sge::font::unit current_y(
		background_.h()
	);


	// TODO: wrap drawing of a line in a function!
/*
	font::text::string const il(
		input_line_.edited(
			// This used to be "bool cursor_active" which was controlled by
			// a timer, but due to the unneccessary timer depenceny, this
			// was removed
			true
		)
	);

	font::text::draw(
		_render_context,
		font_metrics_,
		font_drawer_,
		il,
		font::rect(
			font::pos(
				static_cast<font::unit>(
					background_.x()),
				static_cast<font::unit>(
					background_.y()+background_.h()-font::text::height(font_metrics_))),
			font::dim(
				static_cast<font::unit>(
					background_.w()),
				static_cast<font::unit>(
					font::text::height(font_metrics_)))),
		font::text::align_h::left,
		font::text::align_v::top,
		font::text::flags::none);
*/
	for(
		output_line_sequence::const_iterator
			iter(
				output_lines_.point()
			),
			end(
				output_lines_.end()
			);
		iter != end;
		++iter
	)
	{
		sge::font::draw::static_text static_text(
			renderer_,
			font_object_,
			*iter,
			sge::font::text_parameters(
				sge::font::align_h::left
			)
			.max_width(
				background_.w()
			),
			sge::font::vector::null(),
			font_color_
		);

		sge::font::vector const pos(
			0,
			current_y
			-
			static_text.rect().size().h()
		);

		if(
			pos.y() < 0
		)
			break;

		static_text.pos(
			pos
		);

		static_text.draw(
			_render_context
		);
	}
}

bool
sge::console::gfx::active() const
{
	return
		active_;
}

void
sge::console::gfx::active(
	bool const _active
)
{
	active_ =
		_active;
}

void
sge::console::gfx::print(
	sge::font::string const &_string
)
{
	output_lines_.push_front(
		_string
	);
}

sge::console::object &
sge::console::gfx::object()
{
	return
		object_;
}

sge::console::object const &
sge::console::gfx::object() const
{
	return
		object_;
}

sge::console::sprite_object &
sge::console::gfx::background_sprite()
{
	return background_;
}

sge::console::sprite_object const &
sge::console::gfx::background_sprite() const
{
	return background_;
}

void
sge::console::gfx::key_callback(
	sge::input::keyboard::key_event const &_key
)
{
	if(
		active_
		&&
		_key.pressed()
	)
		this->key_action(
			sge::input::keyboard::key_repeat_event(
				_key.key_code()
			)
		);
}

void
sge::console::gfx::char_callback(
	sge::input::keyboard::char_event const &_event
)
{
	if(
		!active_
	)
		return;

	// is a printable character? then append to input
	if(
		std::isprint(
			_event.character(),
			std::locale()
		)
	)
	{
		input_line_.insert(
			_event.character()
		);

		return;
	}
}

void
sge::console::gfx::key_action(
	sge::input::keyboard::key_repeat_event const &_event
)
{
	if(
		!active_
	)
		return;

	switch(
		_event.key_code()
	)
	{
		case input::keyboard::key_code::w:
			if(
				keyboard_.mod_state()
				& input::keyboard::modifier::control
			)
				input_line_.erase_word();
		break;
		case input::keyboard::key_code::delete_:
			input_line_.erase_char();
		break;
		case input::keyboard::key_code::backspace:
			if (input_line_.at_start())
				return;
			input_line_.left();
			input_line_.erase_char();
		break;
		case input::keyboard::key_code::tab:
			input_line_.complete_word(object_.functions());
		break;
		case input::keyboard::key_code::pageup:
			output_lines_.up();
		break;
		case input::keyboard::key_code::pagedown:
			output_lines_.down();
		break;
		case input::keyboard::key_code::up:
			if (input_history_.empty())
				return;
			input_line_.string(
				*current_input_);
			if (current_input_ != --input_history_.end())
				++current_input_;
		break;
		case input::keyboard::key_code::down:
			if (current_input_ != input_history_.begin())
			{
				--current_input_;
				input_line_.string(
					*current_input_);
			}
		break;
		case input::keyboard::key_code::left:
			input_line_.left();
		break;
		case input::keyboard::key_code::right:
			input_line_.right();
		break;
		case input::keyboard::key_code::home:
			input_line_.to_start();
		break;
		case input::keyboard::key_code::end:
			input_line_.to_end();
		break;
		case input::keyboard::key_code::return_:
			if (input_line_.empty())
				return;

			try
			{
				object_.eval(
					input_line_.string());
			}
			catch(
				sge::console::exception const &_error
			)
			{
				this->print(
					SGE_FONT_LIT("console error: ")
					+
					_error.console_string()
				);
			}

			// add executed command to each history (at the front)...
			input_history_.push_front(
				input_line_.string());

			current_input_ =
				input_history_.begin();

			// clear input line
			input_line_.string(
				SGE_FONT_LIT("")
			);
		break;
		// else we get a million warnings about unhandled enumeration values
		default: break;
	}
}

void
sge::console::gfx::error(
	sge::font::string const &_string
)
{
	this->print(
		SGE_FONT_LIT("command error: ")
		+
		_string
	);
}
