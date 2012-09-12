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


#include <sge/opengl/common.hpp>
#include <sge/opengl/context/system/object_fwd.hpp>
#include <sge/opengl/state/actor_vector.hpp>
#include <sge/opengl/state/core/blend/alpha_variant.hpp>
#include <sge/opengl/state/core/blend/make_actors.hpp>
#include <sge/renderer/state/core/blend/parameters.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/variant/apply_unary.hpp>


sge::opengl::state::actor_vector const
sge::opengl::state::core::blend::make_actors(
	sge::opengl::context::system::object &_system_context,
	sge::renderer::state::core::blend::parameters const &_parameters
)
{
	return
		fcppt::assign::make_container<
			sge::opengl::state::actor_vector
		>(
			fcppt::variant::apply_unary(
				sge::opengl::state::core::blend::alpha_visitor(
					_system_context
				),
				_parameters.alpha_variant()
			)
		)(
			std::tr1::bind(
				::glColorMask,
				_parameters.write_mask().write_red().get(),
				_parameters.write_mask().write_green().get(),
				_parameters.write_mask().write_blue().get(),
				_parameters.write_mask().write_alpha().get()
			)
		);
}