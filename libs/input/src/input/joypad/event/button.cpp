//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/input/joypad/button_id.hpp>
#include <sge/input/joypad/button_pressed.hpp>
#include <sge/input/joypad/shared_ptr.hpp>
#include <sge/input/joypad/event/base.hpp>
#include <sge/input/joypad/event/button.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


sge::input::joypad::event::button::button(
	sge::input::joypad::shared_ptr _joypad,
	sge::input::joypad::button_id const _button_id,
	sge::input::joypad::button_pressed const _pressed
)
:
	sge::input::joypad::event::base{
		std::move(
			_joypad
		)
	},
	button_id_{
		_button_id
	},
	pressed_{
		_pressed
	}
{
}

sge::input::joypad::event::button::~button()
= default;

sge::input::joypad::button_id
sge::input::joypad::event::button::button_id() const
{
	return
		button_id_;
}

bool
sge::input::joypad::event::button::pressed() const
{
	return
		pressed_.get();
}
