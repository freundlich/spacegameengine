/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006  Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#ifndef SGE_FRAGMENTED_TEXTURE_HPP_INCLUDED
#define SGE_FRAGMENTED_TEXTURE_HPP_INCLUDED

#include <boost/noncopyable.hpp>
#include "../shared_ptr.hpp"
#include "../renderer/texture.hpp"
#include "../renderer/renderer.hpp"
#include "../types.hpp"
#include "../bsp_tree.hpp"
#include "./virtual_texture.hpp"

namespace sge
{

class fragmented_texture : boost::noncopyable {
public:
	fragmented_texture(renderer_ptr r, texture::size_type texsize);
	virtual_texture_ptr consume_fragments(texture::size_type w, texture::size_type h);
	void return_fragments(const virtual_texture&);
	texture_ptr get_texture() const { return tex; }
private:
	typedef bsp_tree<texture::size_type> bsp_type;
	bsp_type bsp;
	texture_ptr tex;
};
typedef shared_ptr<fragmented_texture> fragmented_texture_ptr;

}

#endif
