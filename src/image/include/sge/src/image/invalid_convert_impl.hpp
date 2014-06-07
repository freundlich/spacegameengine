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


#ifndef SGE_SRC_IMAGE_INVALID_CONVERT_IMPL_HPP_INCLUDED
#define SGE_SRC_IMAGE_INVALID_CONVERT_IMPL_HPP_INCLUDED

#include <sge/image/exception.hpp>
#include <sge/image/invalid_convert.hpp>
#include <sge/image/traits/format_to_string.hpp>
#include <fcppt/text.hpp>


template<
	typename Tag
>
sge::image::invalid_convert<
	Tag
>::invalid_convert(
	format const _source,
	format const _dest
)
:
	sge::image::exception(
		FCPPT_TEXT("Invalid image convert from ")
		+
		sge::image::traits::format_to_string<
			Tag
		>::execute(
			_source
		)
		+
		FCPPT_TEXT(" to ")
		+
		sge::image::traits::format_to_string<
			Tag
		>::execute(
			_dest
		)
		+
		// FIXME
		FCPPT_TEXT(". The two formats should only differ in alpha or channel order!")
	)
{
}

#endif
