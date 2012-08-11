/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2012 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_RENDERER_DISPLAY_MODE_REFRESH_RATE_HPP_INCLUDED
#define SGE_RENDERER_DISPLAY_MODE_REFRESH_RATE_HPP_INCLUDED

#include <sge/renderer/display_mode/refresh_rate_value.hpp>
#include <fcppt/strong_typedef.hpp>


namespace sge
{
namespace renderer
{
namespace display_mode
{

/**
\brief A typedef used to describe refresh rates in Hz
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	sge::renderer::display_mode::refresh_rate_value,
	refresh_rate
);

}
}
}

#endif