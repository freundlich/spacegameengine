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


#ifndef SGE_RENDERER_VF_FORMAT_TO_ELEMENT_HPP_INCLUDED
#define SGE_RENDERER_VF_FORMAT_TO_ELEMENT_HPP_INCLUDED

#include "element_type.hpp"

namespace sge
{
namespace renderer
{
namespace vf
{

template<typename T>
struct format_to_element;

template<>
struct format_to_element<float> {
	static element_type::type const value = element_type::float_;
};

template<>
struct format_to_element<double> {
	static element_type::type const value = element_type::double_;
};

}
}
}

#endif
