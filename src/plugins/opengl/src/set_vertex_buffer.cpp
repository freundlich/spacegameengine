/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2013 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include <sge/opengl/set_vertex_buffer.hpp>
#include <sge/opengl/unset_vertex_buffer.hpp>
#include <sge/opengl/vertex_buffer.hpp>
#include <sge/opengl/vertex_context.hpp>
#include <sge/opengl/vertex_declaration.hpp>
#include <sge/opengl/context/use.hpp>
#include <sge/opengl/context/device/object_fwd.hpp>
#include <sge/renderer/vertex/buffer.hpp>
#include <sge/renderer/vf/dynamic/part_index.hpp>
#include <fcppt/dynamic_pointer_cast.hpp>


void
sge::opengl::set_vertex_buffer(
	sge::opengl::context::device::object &_context,
	sge::renderer::vertex::buffer const &_buffer
)
{
	sge::opengl::vertex_context &context(
		sge::opengl::context::use<
			sge::opengl::vertex_context
		>(
			_context
		)
	);

	sge::renderer::vf::dynamic::part_index const index(
		_buffer.format_part_index()
	);

	{
		sge::opengl::vertex_buffer const *const old_buffer(
			context.vertex_buffer(
				index
			)
		);

		if(
			old_buffer
		)
			sge::opengl::unset_vertex_buffer(
				_context,
				*old_buffer
			);
	}

	sge::opengl::vertex_buffer const &gl_buffer(
		dynamic_cast<
			sge::opengl::vertex_buffer const &
		>(
			_buffer
		)
	);

	context.vertex_buffer(
		index,
		&gl_buffer
	);

	gl_buffer.use(
		context.vertex_declaration()->gl_format_part(
			index
		)
	);
}
