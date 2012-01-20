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


#include <sge/opengl/context/object_fwd.hpp>
#include <sge/opengl/context/use.hpp>
#include <sge/opengl/texture/base.hpp>
#include <sge/opengl/texture/binding_fwd.hpp>
#include <sge/opengl/texture/filter/context.hpp>
#include <sge/opengl/texture/filter/set.hpp>
#include <sge/opengl/texture/filter/visitor.hpp>
#include <sge/renderer/exception.hpp>
#include <sge/renderer/texture/filter/need_mipmap.hpp>
#include <sge/renderer/texture/filter/object.hpp>
#include <fcppt/text.hpp>
#include <fcppt/variant/apply_unary.hpp>
#include <fcppt/variant/object_impl.hpp>


void
sge::opengl::texture::filter::set(
	opengl::context::object &_context,
	opengl::texture::binding const &_binding,
	opengl::texture::base const &_texture,
	renderer::texture::stage const _stage
)
{
	renderer::texture::filter::object const filter(
		opengl::context::use<
			opengl::texture::filter::context
		>(
			_context
		).get(
			_stage
		)
	);

	if(
		!_texture.update_filter(
			filter
		)
	)
		return;

	if(
		sge::renderer::texture::filter::need_mipmap(
			filter
		)
		&&
		!_texture.has_mipmap()
	)
		throw sge::renderer::exception(
			FCPPT_TEXT("Mipmap filter used with a texture that has none!")
		);

	fcppt::variant::apply_unary(
		filter::visitor(
			_context,
			_binding,
			_texture.type()
		),
		filter.variant()
	);
}