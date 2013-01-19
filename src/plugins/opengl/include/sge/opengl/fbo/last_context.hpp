/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2013 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_OPENGL_FBO_LAST_CONTEXT_HPP_INCLUDED
#define SGE_OPENGL_FBO_LAST_CONTEXT_HPP_INCLUDED

#include <sge/opengl/context/device/base.hpp>
#include <sge/opengl/context/device/id.hpp>
#include <sge/opengl/fbo/id.hpp>
#include <sge/opengl/fbo/last_context_fwd.hpp>


namespace sge
{
namespace opengl
{
namespace fbo
{

class last_context
:
	public sge::opengl::context::device::base
{
	FCPPT_NONCOPYABLE(
		last_context
	);
public:
	last_context();

	~last_context();

	sge::opengl::fbo::id const
	last_buffer() const;

	void
	last_buffer(
		sge::opengl::fbo::id
	);

	typedef void parameter;

	static sge::opengl::context::device::id const static_id;
private:
	sge::opengl::fbo::id last_buffer_;
};

}
}
}

#endif

