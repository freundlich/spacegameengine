/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2013 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_SPRITE_DETAIL_GEOMETRY_FILL_HPP_INCLUDED
#define SGE_SPRITE_DETAIL_GEOMETRY_FILL_HPP_INCLUDED

#include <sge/sprite/buffers/slice_fwd.hpp>
#include <sge/sprite/detail/config/needs_index_buffer.hpp>
#include <sge/sprite/detail/geometry/fill_indices.hpp>
#include <sge/sprite/detail/geometry/fill_vertices.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace sprite
{
namespace detail
{
namespace geometry
{

template<
	typename Range,
	typename Compare,
	typename Choices
>
typename boost::enable_if<
	sge::sprite::detail::config::needs_index_buffer<
		Choices
	>,
	sge::sprite::render::range<
		Choices
	>
>::type const
fill(
	Range const &_range,
	Compare const &_compare,
	sge::sprite::buffers::slice<
		Choices
	> &_slice
)
{
	sge::sprite::detail::geometry::fill_indices<
		Choices
	>(
		_range.size(),
		_slice
	);

	return
		sge::sprite::detail::geometry::fill_vertices(
			_range,
			_compare,
			_slice
		);
}

template<
	typename Range,
	typename Compare,
	typename Choices
>
typename boost::disable_if<
	sge::sprite::detail::config::needs_index_buffer<
		Choices
	>,
	sge::sprite::render::range<
		Choices
	>
>::type const
fill(
	Range const &_range,
	Compare const &_compare,
	sge::sprite::buffers::slice<
		Choices
	> &_slice
)
{
	return
		sge::sprite::detail::geometry::fill_vertices(
			_range,
			_compare,
			_slice
		);
}

}
}
}
}

#endif
