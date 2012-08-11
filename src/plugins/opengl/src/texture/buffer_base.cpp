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


#include <sge/opengl/texture/buffer_base.hpp>
#include <sge/opengl/texture/id.hpp>
#include <sge/opengl/texture/type.hpp>
#include <sge/renderer/texture/mipmap/level.hpp>


sge::opengl::texture::buffer_base::buffer_base(
	sge::opengl::texture::type const _type,
	sge::opengl::texture::id const _id,
	sge::renderer::texture::mipmap::level const _level
)
:
	type_(
		_type
	),
	id_(
		_id
	),
	level_(
		_level
	)
{
}

sge::opengl::texture::buffer_base::~buffer_base()
{
}

sge::opengl::texture::type const
sge::opengl::texture::buffer_base::type() const
{
	return type_;
}

sge::opengl::texture::id const
sge::opengl::texture::buffer_base::id() const
{
	return id_;
}

sge::renderer::texture::mipmap::level const
sge::opengl::texture::buffer_base::level() const
{
	return level_;
}