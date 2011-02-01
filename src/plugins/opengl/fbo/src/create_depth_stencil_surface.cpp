/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include "../create_depth_stencil_surface.hpp"
#include "../context.hpp"
#include "../depth_stencil_surface.hpp"
#include "../../context/use.hpp"
#include "../../convert/depth_stencil_to_internal_format.hpp"
#include <fcppt/make_shared_ptr.hpp>

sge::renderer::depth_stencil_surface_ptr const
sge::opengl::fbo::create_depth_stencil_surface(
	opengl::context::object &_context,
	renderer::dim2 const &_dim,
	renderer::depth_stencil_format::type const _type
)
{
	return
		fcppt::make_shared_ptr<
			fbo::depth_stencil_surface
		>(
			opengl::context::use<
				fbo::context
			>(
				_context
			),
			opengl::convert::depth_stencil_to_internal_format(
				_type
			),
			_dim
		);
}
