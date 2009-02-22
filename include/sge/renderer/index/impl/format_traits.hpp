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


#ifndef SGE_RENDERER_INDEX_IMPL_FORMAT_TRAITS_HPP_INCLUDED
#define SGE_RENDERER_INDEX_IMPL_FORMAT_TRAITS_HPP_INCLUDED

#include <sge/renderer/index/format.hpp>
#include <sge/typeswitch.hpp>
#include <boost/mpl/integral_c.hpp>

namespace sge
{
namespace renderer
{
namespace index
{
namespace detail
{

template<
	typename
>
struct format_traits;

template<>
struct format_traits<
	uint16	
>
:
boost::mpl::integral_c<
	format::type,
	format::i16
>
{};

template<>
struct format_traits<
	uint16 const
>
:
format_traits<
	uint16
>
{};

template<>
struct format_traits<
	uint32	
>
:
boost::mpl::integral_c<
	format::type,
	format::i32
>
{};

template<>
struct format_traits<
	uint32 const
>
:
format_traits<
	uint32
>
{};

}
}
}
}

#endif


