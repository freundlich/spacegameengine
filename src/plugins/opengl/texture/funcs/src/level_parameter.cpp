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


#include "../level_parameter.hpp"
#include "../../../check_state.hpp"
#include "../../../common.hpp"
#include <sge/renderer/exception.hpp>
#include <fcppt/text.hpp>

GLint
sge::opengl::texture::funcs::level_parameter(
	texture::scoped_work_bind const &,
	texture::type const _type,
	renderer::stage const _stage,
	GLenum const _what
)
{
	GLint ret;

	::glGetTexLevelParameteriv(
		_type.get(),
		static_cast<
			GLint
		>(
			_stage.get()
		),
		_what,
		&ret
	);

	SGE_OPENGL_CHECK_STATE(
		FCPPT_TEXT("glGetTexLevelParameteriv() failed!"),
		sge::renderer::exception
	);

	return ret;
}
