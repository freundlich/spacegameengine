/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2014 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#ifndef SGE_SRC_IMAGE_ALGORITHM_INSTANTIATE_COPY_AND_CONVERT_HPP_INCLUDED
#define SGE_SRC_IMAGE_ALGORITHM_INSTANTIATE_COPY_AND_CONVERT_HPP_INCLUDED

#include <sge/image/algorithm/may_overlap.hpp>
#include <sge/image/traits/const_view_fwd.hpp>
#include <sge/image/traits/view_fwd.hpp>
#include <sge/src/export_function_instantiation.hpp>
#include <sge/src/image/algorithm/copy_and_convert_impl.hpp>


#define SGE_SRC_IMAGE_ALGORITHM_INSTANTIATE_COPY_AND_CONVERT(\
	tag\
)\
template \
SGE_EXPORT_FUNCTION_INSTANTIATION \
void \
sge::image::algorithm::copy_and_convert< \
	tag \
>( \
	sge::image::traits::const_view<\
		tag\
	>::type const &, \
	sge::image::traits::view<\
		tag\
	>::type const &, \
	sge::image::algorithm::may_overlap \
)

#endif
