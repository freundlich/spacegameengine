/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

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
#include <sge/systems/instance.hpp>
#include <sge/systems/list.hpp>
#include <sge/sprite/system.hpp>
#include <sge/sprite/object.hpp>
#include <sge/sprite/parameters.hpp>
#include <sge/renderer/filter/linear.hpp>
#include <sge/renderer/state/list.hpp>
#include <sge/renderer/state/var.hpp>
#include <sge/renderer/state/states.hpp>
#include <sge/renderer/scoped_block.hpp>
#include <sge/renderer/device.hpp>
#include <sge/renderer/colors.hpp>
#include <sge/renderer/texture.hpp>
#include <sge/input/key_type.hpp>
#include <sge/input/key_pair.hpp>
#include <sge/input/system.hpp>
#include <sge/image/object.hpp>
#include <sge/image/loader.hpp>
#include <sge/texture/part_raw.hpp>
#include <sge/signal/scoped_connection.hpp>
#include <sge/mainloop/dispatch.hpp>
#include <sge/window/parameters.hpp>
#include <sge/config/media_path.hpp>
#include <sge/exception.hpp>
#include <sge/cerr.hpp>
#include <sge/text.hpp>
#include <sge/make_shared_ptr.hpp>
#include <exception>
#include <iostream>
#include <ostream>
#include <cstdlib>

namespace
{
class input_functor
{
public:
	explicit input_functor(bool &running)
	:
		running(running)
	{}

	void operator()(sge::input::key_pair const &k) const
	{
		if (k.key().code() == sge::input::kc::key_escape)
			running = false;
	}
private:
	bool &running;
};

class sprite_functor
{
public:
	explicit sprite_functor(sge::sprite::object &s)
	:
		s(s) 
	{}

	void operator()(sge::input::key_pair const &k) const
	{
		switch (k.key().code())
		{
			case sge::input::kc::mouse_x_axis:
			s.pos().x() += k.value();
			break;
			case sge::input::kc::mouse_y_axis:
			s.pos().y() += k.value();
			break;
			default: break;
		}
	}
private:
	sge::sprite::object &s;
};
}

int main()
try
{
	sge::systems::instance const sys(
		sge::systems::list()
		(sge::window::parameters(
			SGE_TEXT("sge tutorial02")
		))
		(sge::renderer::parameters(
			sge::renderer::display_mode(
				sge::renderer::screen_size(
					640,
					480),
				sge::renderer::bit_depth::depth32,
				sge::renderer::refresh_rate_dont_care),
			sge::renderer::depth_buffer::off,
			sge::renderer::stencil_buffer::off,
			sge::renderer::window_mode::windowed))
		(sge::systems::parameterless::input)
		(sge::systems::parameterless::image));

	sge::sprite::system ss(sys.renderer());

	sge::image::object_ptr const image(
		sys.image_loader()->load(
			sge::config::media_path() / SGE_TEXT("tux.png")
		)
	);

	sge::renderer::texture_ptr const image_texture =
		sys.renderer()->create_texture(
			image->view(),
			sge::renderer::filter::linear,
			sge::renderer::resource_flags::readable);

	sge::sprite::object my_object(
		sge::sprite::parameters()
		.texture(
			sge::make_shared_ptr<
				sge::texture::part_raw
			>(
				image_texture
			)
		)
	);

	bool running = true;

	sge::signal::scoped_connection const conn(
		sys.input_system()->register_callback(
			input_functor(
				running
			)
		)
	);

	sge::signal::scoped_connection const conn_other(
		sys.input_system()->register_callback(
			sprite_functor(
				my_object
			)
		)
	);

	sys.renderer()->state(
		sge::renderer::state::list
			(sge::renderer::state::bool_::clear_backbuffer = true)
			(sge::renderer::state::color_::clear_color = sge::renderer::colors::black())
	);

	while (running)
	{
		sge::mainloop::dispatch();
		sge::renderer::scoped_block const block_(sys.renderer());
		ss.render(my_object);
	}
}
catch (sge::exception const &e)
{
	sge::cerr << SGE_TEXT("caught sge exception: ") << e.what() << SGE_TEXT('\n');
	return EXIT_FAILURE;
}
catch (std::exception const &e)
{
	std::cerr << "caught std exception: " << e.what() << '\n';
	return EXIT_FAILURE;
}
