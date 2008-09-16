/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)
Copyright (C) 2007       Simon Stienen    (s.stienen@slashlife.org)

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


#ifndef SGE_OPENGL_GLSL_IMPL_HPP_INCLUDED
#define SGE_OPENGL_GLSL_IMPL_HPP_INCLUDED

#include <sge/renderer/glsl/program.hpp>
#include <string>

namespace sge
{
namespace ogl
{
namespace glsl
{

sge::renderer::glsl::program_ptr const
create_program_impl(
	renderer::glsl::string const &vs_source,
	renderer::glsl::string const &ps_source);

void set_program_impl(
	sge::renderer::glsl::program_ptr);

}
}
}

#endif
