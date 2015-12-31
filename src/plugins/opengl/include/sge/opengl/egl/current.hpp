/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2015 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#ifndef SGE_OPENGL_EGL_CURRENT_HPP_INCLUDED
#define SGE_OPENGL_EGL_CURRENT_HPP_INCLUDED

#include <sge/opengl/backend/current.hpp>
#include <sge/opengl/backend/fun_ptr.hpp>
#include <sge/opengl/egl/window_surface_fwd.hpp>
#include <sge/renderer/display_mode/vsync_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <EGL/egl.h>
#include <string>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace opengl
{
namespace egl
{

class current
:
	public sge::opengl::backend::current
{
	FCPPT_NONCOPYABLE(
		current
	);
public:
	current(
		EGLDisplay,
		sge::opengl::egl::window_surface const &
	);

	~current()
	override;
private:
	sge::opengl::backend::fun_ptr
	load_function(
		std::string const &
	) const
	override;

	void
	begin_rendering()
	override;

	void
	end_rendering()
	override;

	void
	vsync(
		sge::renderer::display_mode::vsync
	)
	override;

	EGLDisplay const display_;

	sge::opengl::egl::window_surface const &surface_;
};

}
}
}

#endif