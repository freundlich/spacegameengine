/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_OPENGL_CONVERSION_HPP_INCLUDED
#define SGE_OPENGL_CONVERSION_HPP_INCLUDED

#include "common.hpp"
#include "cube_texture.hpp"
#include <sge/renderer/types.hpp>
#include <sge/renderer/renderer.hpp>
#include <sge/renderer/cube_texture.hpp>
#include <boost/variant/static_visitor.hpp>

namespace sge
{
namespace ogl
{

// TODO: put some of them in their appropriate locations

GLenum convert_cast(bool_state::type);
GLenum convert_cast(cull_mode::type);
GLenum convert_cast(depth_func::type);
GLenum convert_cast(stencil_func::type);
GLenum convert_cast(fog_mode::type);
GLenum convert_cast(source_blend_func::type);
GLenum convert_cast(dest_blend_func::type);
GLenum convert_cast(draw_mode::type);

GLuint convert_cast(const lock_flag_t&);
GLenum convert_cast(const indexed_primitive_type::type&);
GLenum convert_cast(const nonindexed_primitive_type::type&);
GLenum convert_cast(const min_filter::type&);
GLenum convert_cast(const mag_filter::type&);
GLenum convert_cast(const texture_stage_op::type&);
GLenum convert_cast(const texture_stage_op_value::type&);
GLenum convert_cast(const texture_stage_arg::type&);
GLenum convert_cast(const texture_stage_arg_value::type&);

GLuint convert_resource_flags(resource_flag_t);
GLenum convert_fog_float_state(float_state::type);
GLenum convert_clear_bit(bool_state::type);

}
}

#endif
