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


#include <sge/image/size_type.hpp>
#include <sge/image/ds/format.hpp>
#include <sge/image/ds/format_stride.hpp>
#include <fcppt/assert/unreachable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdint>
#include <fcppt/config/external_end.hpp>


sge::image::size_type
sge::image::ds::format_stride(
	sge::image::ds::format const _format
)
{
	switch(
		_format
	)
	{
	case sge::image::ds::format::d16:
		return sizeof(std::uint16_t);
	case sge::image::ds::format::d32:
	case sge::image::ds::format::d24s8:
		return sizeof(std::uint32_t);
	case sge::image::ds::format::size:
		break;
	}

	FCPPT_ASSERT_UNREACHABLE;
}