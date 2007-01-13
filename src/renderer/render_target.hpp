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


#ifndef SGE_RENDER_TARGET_HPP_INCLUDED
#define SGE_RENDER_TARGET_HPP_INCLUDED

#include "../shared_ptr.hpp"
#include "./texture.hpp"

namespace sge
{

template<typename BitDepth>
class basic_render_target : public basic_texture_base<BitDepth> {
public:
	typedef basic_texture_base<BitDepth> base;
	typedef typename base::size_type size_type;
	typedef typename base::pointer pointer;
	virtual size_type width() const = 0;
	virtual size_type height() const = 0;
	virtual size_type size() const = 0;
};

typedef basic_render_target<BitDepth32> render_target;
typedef shared_ptr<render_target> render_target_ptr;

}

#endif
