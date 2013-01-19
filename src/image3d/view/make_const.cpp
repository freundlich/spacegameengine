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


#include <sge/image/const_raw_pointer.hpp>
#include <sge/image/color/format.hpp>
#include <sge/image/color/traits/format_fwd.hpp>
#include <sge/image3d/dim.hpp>
#include <sge/image3d/pitch.hpp>
#include <sge/image3d/tag.hpp>
#include <sge/image3d/traits/color_tag.hpp>
#include <sge/image3d/traits/const_view_fwd.hpp>
#include <sge/image3d/traits/dim_fwd.hpp>
#include <sge/image3d/traits/pitch_fwd.hpp>
#include <sge/image3d/traits/view_fwd.hpp>
#include <sge/image3d/view/const_object.hpp>
#include <sge/image3d/view/make_const.hpp>
#include <sge/image3d/view/object.hpp>
#include <sge/src/image/view/instantiate_make_const.hpp>
#include <sge/src/image/view/make_const_impl.hpp>


sge::image3d::view::const_object const
sge::image3d::view::make_const(
	sge::image::const_raw_pointer const _data,
	sge::image3d::dim const &_dim,
	sge::image::color::format const _format,
	sge::image3d::pitch const &_pitch
)
{
	return
		sge::image::view::make_const<
			sge::image3d::tag
		>(
			_data,
			_dim,
			_format,
			_pitch
		);
}

SGE_SRC_IMAGE_VIEW_INSTANTIATE_MAKE_CONST(
	sge::image3d::tag
);
