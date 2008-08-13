/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License
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


#ifndef SGE_OPENGL_WRITEONLY_TEXTURE_LOCK_HPP_INCLUDED
#define SGE_OPENGL_WRITEONLY_TEXTURE_LOCK_HPP_INCLUDED

#include "texture_lock.hpp"
#include "pixel_unpack_buffer.hpp"
#include <sge/renderer/resource_flags.hpp>

namespace sge
{
namespace ogl
{

class writeonly_texture_lock : public texture_lock {
public:
	writeonly_texture_lock(
		size_type lock_size,
		size_type offset,
		size_type stride,
		renderer::resource_flag_t flags);

	void post_lock();

	void pre_unlock();

	pointer write_pointer() const;
private:
	lock_method::type method() const;

	pixel_unpack_buffer buffer;
};

}
}

#endif
