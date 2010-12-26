/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2010 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_SPRITE_DETAIL_FILL_GEOMETRY_HPP_INCLUDED
#define SGE_SPRITE_DETAIL_FILL_GEOMETRY_HPP_INCLUDED

#include <sge/sprite/detail/vertex_format_from_object.hpp>
#include <sge/sprite/detail/indices_per_sprite.hpp>
#include <sge/sprite/detail/vertices_per_sprite.hpp>
#include <sge/sprite/detail/index_generator.hpp>
#include <sge/sprite/detail/fill_position.hpp>
#include <sge/sprite/detail/fill_color.hpp>
#include <sge/sprite/detail/fill_tex_coordinates.hpp>
#include <sge/sprite/detail/optional_size.hpp>
#include <sge/sprite/detail/visible.hpp>
#include <sge/renderer/vertex_buffer.hpp>
#include <sge/renderer/index_buffer.hpp>
#include <sge/renderer/scoped_index_lock.hpp>
#include <sge/renderer/scoped_vertex_lock.hpp>
#include <sge/renderer/size_type.hpp>
#include <sge/renderer/index/dynamic/generate.hpp>
#include <sge/renderer/vf/view.hpp>
#include <sge/renderer/vf/iterator.hpp>
#include <sge/renderer/vf/vertex.hpp>
#include <fcppt/optional_impl.hpp>
#include <iterator>

namespace sge
{
namespace sprite
{
namespace detail
{

template<
	typename It
>
void
fill_geometry(
	It _begin,
	It const _end,
	renderer::vertex_buffer_ptr const _vb,
	renderer::index_buffer_ptr const _ib,
	optional_size const &_num_sprites
)
{
	renderer::size_type const sprites_to_lock(
		_num_sprites
		?
			*_num_sprites
		:
			renderer::vertex_buffer::npos
	);

	renderer::scoped_vertex_lock const vblock(
		_vb,
		renderer::lock_mode::writeonly,
		0,
		sprites_to_lock
		* detail::vertices_per_sprite
	);

	typedef typename std::iterator_traits<
		It
	>::value_type object_type;

	typedef renderer::vf::view<
		typename vertex_format_from_object<
			object_type
		>::type
	> vertex_view;

	vertex_view const vertices(
		vblock.value()
	);

	typename vertex_view::iterator vb_it(
		vertices.begin()
	);

	renderer::size_type count(0);

	for(
		It it(
			_begin
		);
		it != _end;
		++it
	)
	{
		object_type const &spr(
			*it
		);

		if(
			!detail::visible(
				spr
			)
		)
			continue;

		sprite::detail::fill_position(
			vb_it,
			spr
		);

		sprite::detail::fill_tex_coordinates(
			vb_it,
			spr
		);

		sprite::detail::fill_color(
			vb_it,
			spr
		);

		vb_it += detail::vertices_per_sprite;

		++count;
	}

	renderer::index::dynamic::generate(
		renderer::scoped_index_lock(
			_ib,
			renderer::lock_mode::writeonly,
			0,
			count * detail::indices_per_sprite
		).value(),
		index_generator()
	);
}

}
}
}

#endif
