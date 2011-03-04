/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_OPENGL_GLX_PROC_CONTEXT_HPP_INCLUDED
#define SGE_OPENGL_GLX_PROC_CONTEXT_HPP_INCLUDED

#include "proc_context_fwd.hpp"
#include "../context/base.hpp"
#include "../context/id.hpp"
#include <fcppt/noncopyable.hpp>

namespace sge
{
namespace opengl
{
namespace glx
{

class proc_context
:
	public opengl::context::base
{
	FCPPT_NONCOPYABLE(
		proc_context
	);
public:
	proc_context();

	~proc_context();

	bool
	get_proc_address_supported() const;

	typedef void needs_before;

	static opengl::context::id const static_id;
private:
	bool const get_proc_address_supported_;	
};

}
}
}

#endif