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


#ifndef SGE_RENDERER_PIXEL_FORMAT_COLOR_HPP_INCLUDED
#define SGE_RENDERER_PIXEL_FORMAT_COLOR_HPP_INCLUDED

#include <sge/renderer/pixel_format/color_fwd.hpp>


namespace sge
{
namespace renderer
{
namespace pixel_format
{

enum class color
{
	/**
	\brief A bit depth of 16 bits

	This means 5 bits for red and blue, and 5 or 6 bits for green.
	*/
	depth16,
	/**
	\brief A bit depth of 32 bits

	Red, blue and green have eigth bits with a possible unused channel for
	padding.
	*/
	depth32
};

}
}
}

#endif
