/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include "../../image/view/flipped_impl.hpp"
#include "../../image/view/instantiate_flipped.hpp"
#include <sge/image3d/tag.hpp>
#include <sge/image3d/view/const_object.hpp>
#include <sge/image3d/view/flipped.hpp>
#include <sge/image3d/view/object.hpp>


sge::image3d::view::object const
sge::image3d::view::flipped(
	view::object const &_view
)
{
	return
		sge::image::view::flipped<
			sge::image3d::tag
		>(
			_view
		);
}

sge::image3d::view::const_object const
sge::image3d::view::flipped(
	view::const_object const &_view
)
{
	return
		sge::image::view::flipped<
			sge::image3d::tag
		>(
			_view
		);
}

SGE_IMAGE_VIEW_INSTANTIATE_FLIPPED(
	sge::image3d::tag
)
