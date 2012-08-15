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


#include <sge/opengl/check_state.hpp>
#include <sge/opengl/color_format.hpp>
#include <sge/opengl/color_format_type.hpp>
#include <sge/opengl/common.hpp>
#include <sge/opengl/internal_color_format.hpp>
#include <sge/opengl/context/use.hpp>
#include <sge/opengl/context/system/object_fwd.hpp>
#include <sge/opengl/texture/binding_fwd.hpp>
#include <sge/opengl/texture/buffer_type.hpp>
#include <sge/opengl/texture/volume_context.hpp>
#include <sge/opengl/texture/funcs/set_3d.hpp>
#include <sge/renderer/const_raw_pointer.hpp>
#include <sge/renderer/dim3.hpp>
#include <sge/renderer/texture/creation_failed.hpp>
#include <sge/renderer/texture/mipmap/level.hpp>
#include <fcppt/text.hpp>
#include <fcppt/math/dim/object_impl.hpp>
#include <fcppt/math/dim/output.hpp>


void
sge::opengl::texture::funcs::set_3d(
	sge::opengl::texture::binding const &,
	sge::opengl::context::system::object &_system_context,
	sge::opengl::texture::buffer_type const _buffer_type,
	sge::opengl::color_format const _format,
	sge::opengl::color_format_type const _format_type,
	sge::opengl::internal_color_format const _internal_format,
	sge::renderer::texture::mipmap::level const _level,
	sge::renderer::dim3 const &_dim,
	sge::renderer::const_raw_pointer const _src
)
{
	sge::opengl::context::use<
		sge::opengl::texture::volume_context
	>(
		_system_context
	).tex_image_3d()(
		_buffer_type.get(),
		static_cast<
			GLint
		>(
			_level.get()
		),
		_internal_format.get(),
		static_cast<
			GLsizei
		>(
			_dim.w()
		),
		static_cast<
			GLsizei
		>(
			_dim.h()
		),
		static_cast<
			GLsizei
		>(
			_dim.d()
		),
		0,
		_format.get(),
		_format_type.get(),
		_src
	);

	SGE_OPENGL_CHECK_STATE(
		(
			fcppt::format(
				FCPPT_TEXT("Creation of texture with size %1% failed!")
			)
			% _dim
		).str(),
		sge::renderer::texture::creation_failed
	);
}
