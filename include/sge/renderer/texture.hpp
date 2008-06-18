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


#ifndef SGE_RENDERER_TEXTURE_HPP_INCLUDED
#define SGE_RENDERER_TEXTURE_HPP_INCLUDED

#include "../export.hpp"
#include "../math/dim.hpp"
#include "texture_base.hpp"
#include "image.hpp"

namespace sge
{
namespace renderer
{

class texture : public texture_base {
public:
	typedef math::basic_dim<size_type, 2>        dim_type;

	SGE_SYMBOL size_type size() const;
	virtual const dim_type dim() const = 0;
	virtual void set_data(image const &, const lock_rect& r) = 0;
	virtual void set_data(image const &) = 0;
	virtual void lock(lock_flag_t flags = lock_flags::default_) = 0;
	//virtual void lock(const lock_rect&, lock_flag_t flags = lock_flags::default_) = 0;
	virtual void unlock() = 0;
};

const texture::dim_type gil_dim_to_sge(image::point_t const &);

typedef shared_ptr<texture> texture_ptr;

}
}

#endif
