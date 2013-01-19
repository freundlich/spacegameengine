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


#ifndef SGE_GDIFONT_ALPHA_TO_MAX_HPP_INCLUDED
#define SGE_GDIFONT_ALPHA_TO_MAX_HPP_INCLUDED

#include <sge/gdifont/a8_view.hpp>
#include <sge/image/mizuiro_color.hpp>
#include <mizuiro/color/channel_max.hpp>
#include <mizuiro/color/channel/alpha.hpp>


namespace sge
{
namespace gdifont
{

struct alpha_to_max
{
	void
	operator()(
		sge::gdifont::a8_view::reference _color
	) const
	{
		if(
			_color.get(
				mizuiro::color::channel::alpha()
			)
			> 0
		)
			_color.set(
				mizuiro::color::channel::alpha(),
				mizuiro::color::channel_max(
					_color.format_store(),
					mizuiro::color::channel::alpha()
				)
			);
	}
};

}
}

#endif
