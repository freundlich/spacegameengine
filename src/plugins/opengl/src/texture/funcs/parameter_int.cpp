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


#include <sge/opengl/check_state.hpp>
#include <sge/opengl/common.hpp>
#include <sge/opengl/texture/binding.hpp>
#include <sge/opengl/texture/funcs/parameter_int.hpp>
#include <sge/renderer/exception.hpp>
#include <fcppt/text.hpp>


void
sge::opengl::texture::funcs::parameter_int(
	sge::opengl::texture::binding const &_binding,
	GLenum const _name,
	GLint const _value
)
{
	::glTexParameteri(
		_binding.type().get(),
		_name,
		_value
	);

	SGE_OPENGL_CHECK_STATE(
		FCPPT_TEXT("glTexParameteri failed"),
		sge::renderer::exception
	)
}
