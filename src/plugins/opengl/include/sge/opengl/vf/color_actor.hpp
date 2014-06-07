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


#ifndef SGE_OPENGL_VF_COLOR_ACTOR_HPP_INCLUDED
#define SGE_OPENGL_VF_COLOR_ACTOR_HPP_INCLUDED

#include <sge/opengl/color_format_type.hpp>
#include <sge/opengl/common.hpp>
#include <sge/opengl/vf/actor_parameters_fwd.hpp>
#include <sge/opengl/vf/fp_actor.hpp>
#include <sge/opengl/vf/pointer.hpp>
#include <sge/renderer/vf/dynamic/color_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace sge
{
namespace opengl
{
namespace vf
{

class color_actor
:
	public vf::fp_actor
{
	FCPPT_NONCOPYABLE(
		color_actor
	);
public:
	explicit color_actor(
		actor_parameters const &,
		sge::renderer::vf::dynamic::color const &
	);

	~color_actor();
private:
	void
	on_use(
		vf::pointer
	) const;

	GLint const elements_;

	opengl::color_format_type const format_;
};

}
}
}

#endif
