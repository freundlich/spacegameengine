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


#ifndef SGE_FONT_ALIGN_H_LEFT_HPP_INCLUDED
#define SGE_FONT_ALIGN_H_LEFT_HPP_INCLUDED

#include <sge/font/symbol.hpp>
#include <sge/font/align_h/left_fwd.hpp>
#include <sge/font/align_h/max_width.hpp>
#include <sge/font/align_h/optional_max_width.hpp>


namespace sge
{
namespace font
{
namespace align_h
{

class left
{
public:
	SGE_FONT_SYMBOL
	left();

	SGE_FONT_SYMBOL
	explicit
	left(
		sge::font::align_h::max_width
	);

	SGE_FONT_SYMBOL
	sge::font::align_h::optional_max_width const
	max_width() const;
private:
	sge::font::align_h::optional_max_width max_width_;
};

}
}
}

#endif
