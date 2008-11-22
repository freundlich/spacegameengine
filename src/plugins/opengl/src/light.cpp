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


#include "../light.hpp"
#include "../error.hpp"
#include "../vector4f.hpp"
#include "../vector3f.hpp"
#include <sge/renderer/raw_color.hpp>
#include <sge/renderer/any_color_convert.hpp>
#include <sge/renderer/vector_convert.hpp>
#include <sge/renderer/arithmetic_convert.hpp>
#include <sge/renderer/light.hpp>

namespace
{

void light_float_ptr(
	GLenum index,
	GLenum name,
	GLfloat const *data);

void light_float(
	GLenum index,
	GLenum name,
	GLfloat value);

void light_arithmetic(
	GLenum index,
	GLenum name,
	sge::renderer::any_arithmetic const &);

void light_pos(
	GLenum index,
	sge::renderer::any_vector3 const &);

void light_dir(
	GLenum index,
	sge::renderer::any_vector3 const &);

void light_color(
	GLenum index,
	GLenum name,
	sge::renderer::any_color const &color);
}

void sge::ogl::set_light(
	renderer::light_index const index,
	renderer::light const &l)
{
	GLenum const glindex = convert_light_index(index);

	light_color(glindex, GL_AMBIENT, l.ambient());
	light_color(glindex, GL_DIFFUSE, l.diffuse());
	light_color(glindex, GL_SPECULAR, l.specular());

	light_pos(glindex, l.position());

	light_dir(glindex, l.direction());

	light_arithmetic(glindex, GL_CONSTANT_ATTENUATION, l.const_attenuation());
	light_arithmetic(glindex, GL_LINEAR_ATTENUATION, l.linear_attenuation());
	light_arithmetic(glindex, GL_QUADRATIC_ATTENUATION, l.quadratic_attenuation());

	light_arithmetic(glindex, GL_SPOT_EXPONENT, l.distribution_exponent());
	light_arithmetic(glindex, GL_SPOT_CUTOFF, l.cutoff_angle());

}

GLenum sge::ogl::convert_light_index(
	renderer::light_index const index)
{
	return GL_LIGHT0 + index;
}

namespace
{

void light_float_ptr(
	GLenum const index,
	GLenum const name,
	GLfloat const *const data)
{
	SGE_OPENGL_SENTRY
	
	glLightfv(index, name, data);
}

void light_float(
	GLenum const index,
	GLenum const name,
	GLfloat const value)
{
	SGE_OPENGL_SENTRY
	
	glLightf(index, name, value);
}

void light_arithmetic(
	GLenum const index,
	GLenum const name,
	sge::renderer::any_arithmetic const &value)
{
	light_float(
		index,
		name,
		sge::renderer::arithmetic_convert<
			GLfloat
		>(
			value));
}

void light_pos(
	GLenum const index,
	sge::renderer::any_vector3 const &pos)
{
	sge::ogl::vector4f const pos4(
		sge::renderer::vector_convert<
			sge::ogl::vector3f
		>(
			pos),
		static_cast<GLfloat>(1));
	
	light_float_ptr(
		index,
		GL_POSITION,
		pos4.data());
}

void light_dir(
	GLenum const index,
	sge::renderer::any_vector3 const &dir)
{
	light_float_ptr(
		index,
		GL_SPOT_DIRECTION,
		sge::renderer::vector_convert<
			sge::ogl::vector3f
		>(
			dir).data());
}

void light_color(
	GLenum const index,
	GLenum const name,
	sge::renderer::any_color const &color)
{
	light_float_ptr(
		index,
		name,
		sge::renderer::raw_color(
			sge::renderer::any_color_convert<sge::renderer::rgba32f_color>(
				color)).data());
}

}
