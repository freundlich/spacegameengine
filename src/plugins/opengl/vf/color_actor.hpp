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



#ifndef SGE_OPENGL_VF_COLOR_ACTOR_HPP_INCLUDED
#define SGE_OPENGL_VF_COLOR_ACTOR_HPP_INCLUDED

#include "pointer_actor.hpp"
#include <sge/renderer/vf/vertex_size.hpp>

namespace sge
{
namespace renderer
{
namespace vf
{
class dynamic_ordered_element;
}
}

namespace ogl
{
namespace vf
{

class client_state_combiner;

class color_actor : public pointer_actor {
public:
	color_actor(
		renderer::vf::dynamic_ordered_element const &,
		renderer::vf::vertex_size);

private:
	void operator()(
		client_state_combiner &) const;

	GLint const elements;
};

}
}
}

#endif
