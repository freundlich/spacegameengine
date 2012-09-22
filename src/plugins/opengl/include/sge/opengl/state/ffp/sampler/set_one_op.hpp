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


#ifndef SGE_OPENGL_STATE_FFP_SAMPLER_SET_ONE_OP_HPP_INCLUDED
#define SGE_OPENGL_STATE_FFP_SAMPLER_SET_ONE_OP_HPP_INCLUDED

#include <sge/opengl/state/convert/sampler_op.hpp>
#include <sge/opengl/state/convert/sampler_op_type.hpp>
#include <sge/opengl/state/ffp/sampler/actor.hpp>
#include <sge/opengl/state/ffp/sampler/set_one.hpp>
#include <sge/opengl/texture/funcs/env_arg.hpp>
#include <sge/opengl/texture/funcs/env_int_value.hpp>
#include <fcppt/strong_typedef_construct_cast.hpp>


namespace sge
{
namespace opengl
{
namespace state
{
namespace ffp
{
namespace sampler
{

template<
	typename OpType,
	typename Op
>
sge::opengl::state::ffp::sampler::actor const
set_one_op(
	Op const _op
)
{
	return
		sge::opengl::state::ffp::sampler::set_one(
			fcppt::strong_typedef_construct_cast<
				sge::opengl::texture::funcs::env_arg
			>(
				sge::opengl::state::convert::sampler_op_type<
					OpType
				>::get()
			),
			fcppt::strong_typedef_construct_cast<
				sge::opengl::texture::funcs::env_int_value
			>(
				sge::opengl::state::convert::sampler_op(
					_op
				)
			)
		);
}

}
}
}
}
}

#endif