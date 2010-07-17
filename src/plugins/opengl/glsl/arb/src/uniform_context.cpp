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


#include "../uniform_context.hpp"
#include "../../../common.hpp"

sge::opengl::glsl::arb::uniform_context::uniform_context()
:
	get_uniform_location_(
		glGetUniformLocationARB
	),
	get_uniform_iv_(
		glGetUniformivARB
	),
	get_uniform_fv_(
		glGetUniformfvARB
	),
	uniform_1iv_(
		glUniform1ivARB
	),
	uniform_2iv_(
		glUniform2ivARB
	),
	uniform_3iv_(
		glUniform3ivARB
	),
	uniform_4iv_(
		glUniform4ivARB
	),
	uniform_1fv_(
		glUniform1fvARB
	),
	uniform_2fv_(
		glUniform2fvARB
	),
	uniform_3fv_(
		glUniform3fvARB
	),
	uniform_4fv_(
		glUniform4fvARB
	),
	uniform_matrix_2fv_(
		glUniformMatrix2fvARB
	),
	uniform_matrix_3fv_(
		glUniformMatrix3fvARB
	),
	uniform_matrix_4fv_(
		glUniformMatrix4fvARB
	)
{}
