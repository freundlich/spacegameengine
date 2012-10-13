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


#include <sge/audio/loader_fwd.hpp>
#include <sge/audio/player_fwd.hpp>
#include <sge/charconv/system_fwd.hpp>
#include <sge/font/system_fwd.hpp>
#include <sge/image2d/system_fwd.hpp>
#include <sge/input/processor_fwd.hpp>
#include <sge/input/system_fwd.hpp>
#include <sge/input/cursor/object_fwd.hpp>
#include <sge/input/keyboard/device_fwd.hpp>
#include <sge/input/mouse/device_fwd.hpp>
#include <sge/plugin/manager_fwd.hpp>
#include <sge/renderer/system_fwd.hpp>
#include <sge/renderer/device/core_fwd.hpp>
#include <sge/renderer/device/ffp_fwd.hpp>
#include <sge/src/systems/any_visitor.hpp>
#include <sge/src/systems/extract_plugin_path.hpp>
#include <sge/src/systems/detail/instance_impl.hpp>
#include <sge/systems/detail/any_key.hpp>
#include <sge/systems/detail/any_map.hpp>
#include <sge/systems/detail/instance.hpp>
#include <sge/systems/detail/list.hpp>
#include <sge/systems/detail/renderer.hpp>
#include <sge/viewport/manager_fwd.hpp>
#include <sge/window/object_fwd.hpp>
#include <sge/window/system_fwd.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>


sge::systems::detail::instance::instance(
	sge::systems::detail::list const &_list
)
:
	impl_(
		fcppt::make_unique_ptr<
			sge::systems::detail::instance_impl
		>(
			sge::systems::extract_plugin_path(
				_list.get()
			)
		)
	)
{
	sge::systems::detail::any_map const &map(
		_list.get()
	);

	// Special case:
	// The renderer system must be initialized before the window,
	// but the window must be initialized before a renderer device
	{
		sge::systems::detail::any_map::const_iterator const it(
			map.find(
				sge::systems::detail::any_key::renderer
			)
		);

		if(
			it != map.end()
		)
			impl_->init_renderer_system(
				it->second.get<
					sge::systems::detail::renderer
				>()
			);
	}

	for(
		sge::systems::detail::any_map::const_iterator it(
			map.begin()
		);
		it != map.end();
		++it
	)
		fcppt::variant::apply_unary(
			sge::systems::any_visitor(
				*impl_
			),
			it->second
		);

	impl_->post_init();
}

sge::systems::detail::instance::~instance()
{
}

sge::plugin::manager &
sge::systems::detail::instance::plugin_manager()
{
	return impl_->plugin_manager();
}

sge::renderer::system &
sge::systems::detail::instance::renderer_system() const
{
	return impl_->renderer_system();
}

sge::renderer::device::ffp &
sge::systems::detail::instance::renderer_ffp() const
{
	return impl_->renderer_device_ffp();
}

sge::renderer::device::core &
sge::systems::detail::instance::renderer_core() const
{
	return impl_->renderer_device_core();
}

sge::input::system &
sge::systems::detail::instance::input_system() const
{
	return impl_->input_system();
}

sge::input::processor &
sge::systems::detail::instance::input_processor() const
{
	return impl_->input_processor();
}

sge::input::cursor::object &
sge::systems::detail::instance::cursor_demuxer() const
{
	return impl_->cursor_demuxer();
}

sge::input::keyboard::device &
sge::systems::detail::instance::keyboard_collector() const
{
	return impl_->keyboard_collector();
}

sge::input::mouse::device &
sge::systems::detail::instance::mouse_collector() const
{
	return impl_->mouse_collector();
}

sge::image2d::system &
sge::systems::detail::instance::image_system() const
{
	return impl_->image_system();
}

sge::audio::loader &
sge::systems::detail::instance::audio_loader() const
{
	return impl_->audio_loader();
}

sge::audio::player &
sge::systems::detail::instance::audio_player() const
{
	return impl_->audio_player();
}

sge::charconv::system &
sge::systems::detail::instance::charconv_system() const
{
	return impl_->charconv_system();
}

sge::font::system &
sge::systems::detail::instance::font_system() const
{
	return impl_->font_system();
}

sge::window::object &
sge::systems::detail::instance::window() const
{
	return impl_->window();
}

sge::window::system &
sge::systems::detail::instance::window_system() const
{
	return impl_->window_system();
}

sge::viewport::manager &
sge::systems::detail::instance::viewport_manager() const
{
	return impl_->viewport_manager();
}