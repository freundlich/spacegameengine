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


#include <sge/scenic/render_context/cg/manager.hpp>
#include <sge/scenic/render_context/cg/object.hpp>
#include <fcppt/math/matrix/arithmetic.hpp>
#include <fcppt/math/matrix/inverse.hpp>
#include <fcppt/math/matrix/transpose.hpp>


sge::scenic::render_context::cg::object::object(
	sge::scenic::render_context::cg::manager &_manager,
	sge::renderer::context::object &_context)
:
	sge::scenic::render_context::base(),
	manager_(
		_manager),
	context_(
		_context),
	current_world_(),
	current_projection_(),
	current_vertex_buffer_()
{
}

void
sge::scenic::render_context::cg::object::transform(
	sge::renderer::matrix_mode::type const _matrix_mode,
	sge::renderer::matrix4 const &_matrix)
{
	switch(_matrix_mode)
	{
	case sge::renderer::matrix_mode::world:
		current_world_ =
			_matrix;

		manager_.world_matrix_.set(
			current_world_);

		manager_.world_inverse_transpose_matrix_.set(
			fcppt::math::matrix::inverse(
				fcppt::math::matrix::transpose(
					current_world_)));

		manager_.world_projection_matrix_.set(
			current_projection_ * current_world_);
		break;
	case sge::renderer::matrix_mode::projection:
		current_projection_ =
			_matrix;

		manager_.world_projection_matrix_.set(
			current_projection_ * current_world_);
		break;
	case sge::renderer::matrix_mode::size:
		break;
	}
}

void
sge::scenic::render_context::cg::object::material(
	sge::renderer::material const &_material)
{
}

void
sge::scenic::render_context::cg::object::diffuse_texture(
	sge::scenic::render_context::optional_planar_texture const &_texture)
{
	manager_.diffuse_texture_.set(
		_texture
		?
			sge::shader::parameter::planar_texture::optional_value(
				*_texture)
		:
			sge::shader::parameter::planar_texture::optional_value());
}

void
sge::scenic::render_context::cg::object::lights(
	sge::scenic::render_context::light_sequence const &)
{
}

void
sge::scenic::render_context::cg::object::vertex_buffer(
	sge::renderer::vertex_buffer const &_vertex_buffer)
{
	current_vertex_buffer_ =
		optional_vertex_buffer(
			_vertex_buffer);
}

sge::scenic::render_context::cg::object::~object()
{
}
