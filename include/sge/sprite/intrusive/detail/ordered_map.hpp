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


#ifndef SGE_SPRITE_INTRUSIVE_DETAIL_ORDERED_MAP_HPP_INCLUDED
#define SGE_SPRITE_INTRUSIVE_DETAIL_ORDERED_MAP_HPP_INCLUDED

#include <sge/sprite/config/is_choices.hpp>
#include <sge/sprite/intrusive/collection_fwd.hpp>
#include <fcppt/static_assert_statement.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/ptr_container/ptr_map.hpp>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace sprite
{
namespace intrusive
{
namespace detail
{

template<
	typename Order,
	typename Choices
>
struct ordered_map
{
	FCPPT_STATIC_ASSERT_STATEMENT(
		sge::sprite::config::is_choices<
			Choices
		>::value
	);

	typedef boost::ptr_map<
		Order,
		sge::sprite::intrusive::collection<
			Choices
		>
	> type;
};

}
}
}
}

#endif
