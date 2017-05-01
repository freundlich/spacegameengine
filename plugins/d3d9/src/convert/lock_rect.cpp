/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2016 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#include <sge/d3d9/d3dinclude.hpp>
#include <sge/d3d9/convert/lock_rect.hpp>
#include <sge/renderer/lock_rect.hpp>
#include <fcppt/cast/size.hpp>
#include <fcppt/cast/to_signed.hpp>


RECT
sge::d3d9::convert::lock_rect(
	sge::renderer::lock_rect const &_rect
)
{
	return
		RECT{
			fcppt::cast::size<
				LONG
			>(
				fcppt::cast::to_signed(
					_rect.left()
				)
			),
			fcppt::cast::size<
				LONG
			>(
				fcppt::cast::to_signed(
					_rect.top()
				)
			),
			fcppt::cast::size<
				LONG
			>(
				fcppt::cast::to_signed(
					_rect.right()
				)
			),
			fcppt::cast::size<
				LONG
			>(
				fcppt::cast::to_signed(
					_rect.bottom()
				)
			)
		};
}