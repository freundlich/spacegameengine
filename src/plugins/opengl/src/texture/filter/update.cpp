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


#include <sge/opengl/context/use.hpp>
#include <sge/opengl/context/device/object_fwd.hpp>
#include <sge/opengl/context/system/object_fwd.hpp>
#include <sge/opengl/texture/active_level.hpp>
#include <sge/opengl/texture/get_stage_type.hpp>
#include <sge/opengl/texture/optional_type.hpp>
#include <sge/opengl/texture/render_binding.hpp>
#include <sge/opengl/texture/filter/context.hpp>
#include <sge/opengl/texture/filter/set.hpp>
#include <sge/opengl/texture/filter/update.hpp>
#include <sge/renderer/texture/stage.hpp>
#include <sge/renderer/texture/filter/object_fwd.hpp>


void
sge::opengl::texture::filter::update(
	sge::opengl::context::system::object &_system_context,
	sge::opengl::context::device::object &_device_context,
	sge::renderer::texture::stage const _stage,
	sge::renderer::texture::filter::object const &_filter
)
{
	if(
		!sge::opengl::context::use<
			opengl::texture::filter::context
		>(
			_device_context
		).set(
			_stage,
			_filter
		)
	)
		return;

	sge::opengl::texture::optional_type const bound_type(
		sge::opengl::texture::get_stage_type(
			_device_context,
			_stage
		)
	);

	if(
		!bound_type
	)
		return;

	sge::opengl::texture::active_level const active_level(
		_system_context,
		_stage
	);

	sge::opengl::texture::render_binding const render_binding(
		active_level
	);

	sge::opengl::texture::filter::set(
		render_binding,
		_system_context,
		_device_context,
		*bound_type
	);
}
