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


#include <sge/image2d/dim.hpp>
#include <sge/image2d/tag.hpp>
#include <sge/image2d/view/const_object.hpp>
#include <sge/image2d/view/object.hpp>
#include <sge/image2d/view/size.hpp>
#include <sge/src/image/view/instantiate_size.hpp>
#include <sge/src/image/view/size_impl.hpp>


sge::image2d::dim const
sge::image2d::view::size(
	image2d::view::object const &_view
)
{
	return
		sge::image::view::size<
			sge::image2d::tag
		>(
			_view
		);
}

sge::image2d::dim const
sge::image2d::view::size(
	image2d::view::const_object const &_view
)
{
	return
		sge::image::view::size<
			sge::image2d::tag
		>(
			_view
		);
}

SGE_SRC_IMAGE_VIEW_INSTANTIATE_SIZE(
	sge::image2d::tag
)
