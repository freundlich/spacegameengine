/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_OPENGL_VF_POINTER_ACTOR_HPP_INCLUDED
#define SGE_OPENGL_VF_POINTER_ACTOR_HPP_INCLUDED

#include "actor.hpp"
#include "../common.hpp"
#include <sge/renderer/vf/vertex_size.hpp>
#include <sge/renderer/vf/dynamic/ordered_element_fwd.hpp>

namespace sge
{
namespace opengl
{
namespace vf
{

class pointer_actor
:
	public actor
{
protected:
	pointer_actor(
		renderer::vf::dynamic::ordered_element const &,
		renderer::vf::vertex_size stride
	);

	GLenum
	format() const;

	GLsizei
	stride() const;

	GLvoid const *
	pointer() const;
private:
	void
	source(
		vf::pointer
	);

	GLenum const format_;

	GLsizei const stride_;

	vf::pointer pointer_;

	renderer::vf::vertex_size const
		index_,
		offset_;
};

}
}
}

#endif
