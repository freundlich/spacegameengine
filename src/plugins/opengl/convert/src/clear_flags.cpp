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


#include "../clear_flags.hpp"
#include <sge/renderer/exception.hpp>
#include <fcppt/text.hpp>

GLenum
sge::opengl::convert::clear_flags(
	sge::renderer::clear_flags::type const _flag
)
{
	switch(
		_flag
	)
	{
	case sge::renderer::clear_flags::back_buffer:
		return GL_COLOR_BUFFER_BIT;
	case sge::renderer::clear_flags::depth_buffer:
		return GL_DEPTH_BUFFER_BIT;
	case sge::renderer::clear_flags::stencil_buffer:
		return GL_STENCIL_BUFFER_BIT;
	case sge::renderer::clear_flags::size:
		break;
	}

	throw sge::renderer::exception(
		FCPPT_TEXT("Invalid clear_flag in convert::clear_flags()!")
	);
}