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


#include <sge/opengl/context/device/object_fwd.hpp>
#include <sge/opengl/context/system/object_fwd.hpp>
#include <sge/opengl/state/core/set_defaults.hpp>
#include <sge/opengl/state/core/blend/set.hpp>
#include <sge/opengl/state/core/depth_stencil/set.hpp>
#include <sge/opengl/state/core/rasterizer/set.hpp>
#include <sge/opengl/state/core/sampler/set.hpp>
#include <sge/renderer/state/core/blend/const_optional_object_ref.hpp>
#include <sge/renderer/state/core/depth_stencil/const_optional_object_ref.hpp>
#include <sge/renderer/state/core/rasterizer/const_optional_object_ref.hpp>
#include <sge/renderer/state/core/sampler/const_object_ref_vector.hpp>


void
sge::opengl::state::core::set_defaults(
	sge::opengl::context::system::object &_system_context,
	sge::opengl::context::device::object &_device_context
)
{
	sge::opengl::state::core::blend::set(
		_system_context,
		sge::renderer::state::core::blend::const_optional_object_ref()
	);

	sge::opengl::state::core::depth_stencil::set(
		_system_context,
		sge::renderer::state::core::depth_stencil::const_optional_object_ref()
	);

	sge::opengl::state::core::rasterizer::set(
		_system_context,
		sge::renderer::state::core::rasterizer::const_optional_object_ref()
	);

	sge::opengl::state::core::sampler::set(
		_system_context,
		_device_context,
		sge::renderer::state::core::sampler::const_object_ref_vector()
	);
}