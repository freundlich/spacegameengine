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


#include <sge/image/impl/algorithm/clone_impl.hpp>
#include <sge/image/impl/algorithm/instantiate_clone.hpp>
#include <sge/image2d/tag.hpp>
#include <sge/image2d/algorithm/clone.hpp>
#include <sge/image2d/store/object.hpp>
#include <sge/image2d/view/const_object.hpp>


sge::image2d::store::object
sge::image2d::algorithm::clone(
	sge::image2d::view::const_object const &_view
)
{
	return
		sge::image::algorithm::clone<
			sge::image2d::tag
		>(
			_view
		);
}


SGE_IMAGE_IMPL_ALGORITHM_INSTANTIATE_CLONE(
	sge::image2d::tag
);