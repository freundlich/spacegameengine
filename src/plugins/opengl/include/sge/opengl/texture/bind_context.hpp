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


#ifndef SGE_OPENGL_TEXTURE_BIND_CONTEXT_HPP_INCLUDED
#define SGE_OPENGL_TEXTURE_BIND_CONTEXT_HPP_INCLUDED

#include <sge/opengl/context/base.hpp>
#include <sge/opengl/context/id.hpp>
#include <sge/opengl/context/object_fwd.hpp>
#include <sge/opengl/texture/base_fwd.hpp>
#include <sge/opengl/texture/bind_context_fwd.hpp>
#include <sge/opengl/texture/optional_type.hpp>
#include <sge/renderer/texture/stage.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/optional_decl.hpp>
#include <fcppt/container/index_map_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace opengl
{
namespace texture
{

class bind_context
:
	public sge::opengl::context::base
{
	FCPPT_NONCOPYABLE(
		bind_context
	);
public:
	bind_context();

	~bind_context();

	void
	bind_for_rendering(
		sge::opengl::context::object &,
		sge::opengl::texture::base const &,
		sge::renderer::texture::stage
	);

	void
	unbind_for_rendering(
		sge::opengl::context::object &,
		sge::renderer::texture::stage
	);

	sge::opengl::texture::base const *
	render_texture(
		sge::renderer::texture::stage
	);

	typedef void needs_before;

	static sge::opengl::context::id const static_id;
private:
	typedef fcppt::container::index_map<
		sge::opengl::texture::base const *
	> texture_vector;

	typedef fcppt::container::index_map<
		sge::opengl::texture::optional_type
	> texture_type_vector;

	texture_vector render_textures_;

	texture_type_vector last_types_;
};

}
}
}

#endif
