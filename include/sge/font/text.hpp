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


#ifndef SGE_FONT_TEXT_HPP_INCLUDED
#define SGE_FONT_TEXT_HPP_INCLUDED

#include <sge/class_symbol.hpp>
#include <sge/font/rect_fwd.hpp>
#include <sge/font/symbol.hpp>
#include <sge/font/text_fwd.hpp>
#include <sge/font/view_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace sge
{
namespace font
{

class SGE_CLASS_SYMBOL text
{
	FCPPT_NONCOPYABLE(
		text
	);
protected:
	SGE_FONT_SYMBOL
	text();
public:
	SGE_FONT_SYMBOL
	virtual
	~text() = 0;

	virtual
	void
	render(
		sge::font::view const &
	) = 0;

	virtual
	sge::font::rect const
	rect() = 0;
};

}
}

#endif