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


#include <sge/image/color/format.hpp>
#include <sge/opengl/color_format.hpp>
#include <sge/opengl/texture/best_color_format.hpp>
#include <fcppt/assert/unreachable.hpp>


sge::opengl::color_format
sge::opengl::texture::best_color_format(
	sge::image::color::format const _format
)
{
#define SGE_OPENGL_CONVERT_FORMAT(\
	name\
)\
case sge::image::color::format::name: \
	return \
		sge::opengl::color_format::name

	switch(
		_format
	)
	{
	SGE_OPENGL_CONVERT_FORMAT(
		a8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		l8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		r32f
	);
	SGE_OPENGL_CONVERT_FORMAT(
		la8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		rgb8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		bgr8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		rgba8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		bgra8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		rgb32f
	);
	SGE_OPENGL_CONVERT_FORMAT(
		bgr32f
	);
	SGE_OPENGL_CONVERT_FORMAT(
		rgba32f
	);
	SGE_OPENGL_CONVERT_FORMAT(
		bgra32f
	);
	SGE_OPENGL_CONVERT_FORMAT(
		srgb8
	);
	SGE_OPENGL_CONVERT_FORMAT(
		srgba8
	);
	// TODO: Why?
	case sge::image::color::format::sbgr8:
		return
			sge::opengl::color_format::srgb8;
	case sge::image::color::format::sbgra8:
		return
			sge::opengl::color_format::srgba8;
	case sge::image::color::format::rgbx8:
		return
			sge::opengl::color_format::rgb8;
	case sge::image::color::format::bgrx8:
		return
			sge::opengl::color_format::bgr8;
	}

	FCPPT_ASSERT_UNREACHABLE;
}