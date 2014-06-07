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


#include <sge/image/ds/traits/format_stride.hpp>
#include <sge/imageds2d/traits/box_fwd.hpp>
#include <sge/imageds2d/traits/color_tag.hpp>
#include <sge/imageds2d/traits/const_view_fwd.hpp>
#include <sge/imageds2d/traits/dim_fwd.hpp>
#include <sge/imageds2d/traits/pitch_fwd.hpp>
#include <sge/imageds2d/traits/view_fwd.hpp>
#include <sge/imageds2d/view/const_object.hpp>
#include <sge/imageds2d/view/object.hpp>
#include <sge/opengl/texture/basic_buffer_impl.hpp>
#include <sge/opengl/texture/buffer_surface_types.hpp>
#include <sge/opengl/texture/depth_stencil_surface.hpp>
#include <sge/opengl/texture/depth_stencil_surface_types.hpp>


template
class
sge::opengl::texture::basic_buffer<
	sge::opengl::texture::depth_stencil_surface_types
>;
