/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_TEXTURE_MANAGER_HPP_INCLUDED
#define SGE_TEXTURE_MANAGER_HPP_INCLUDED

#include <boost/noncopyable.hpp>
#include <boost/function.hpp>
#include <boost/ptr_container/ptr_list.hpp>
#include "../shared_ptr.hpp"
#include "../exception.hpp"
#include "../renderer/renderer.hpp"
#include "../renderer/texture.hpp"
#include "fragmented_texture.hpp"

namespace sge
{

class texture_manager : boost::noncopyable {
public:
	typedef boost::function<fragmented_texture* ()> onalloc_function;
	texture_manager(renderer_ptr rend, const onalloc_function&);
	const virtual_texture_ptr add_texture(texture::const_pointer src,
	                                      const texture::dim_type& dim);
	const virtual_texture_ptr add_texture(texture_ptr tex);
	const renderer_ptr get_renderer() const;
	void onalloc(const onalloc_function&);

	class image_too_big : public exception {
	public:
		image_too_big();
	};
private:
	const virtual_texture_ptr init_texture(fragmented_texture&,
	                                       texture::const_pointer src,
	                                       const texture::dim_type& dim) const;

	const renderer_ptr                          rend;
	onalloc_function                            onalloc_;
	typedef boost::ptr_list<fragmented_texture> fragmented_texture_list;
	fragmented_texture_list                     fragmented_textures;
};

typedef shared_ptr<texture_manager> texture_manager_ptr;

}

#endif
