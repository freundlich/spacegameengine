/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_INPUT_JOYPAD_BUTTON_EVENT_HPP_INCLUDED
#define SGE_INPUT_JOYPAD_BUTTON_EVENT_HPP_INCLUDED

#include <sge/input/symbol.hpp>
#include <sge/input/joypad/button_event_fwd.hpp>
#include <sge/input/joypad/button_id.hpp>


namespace sge
{
namespace input
{
namespace joypad
{

class button_event
{
public:
	SGE_INPUT_SYMBOL
	button_event(
		joypad::button_id,
		bool pressed
	);

	SGE_INPUT_SYMBOL
	joypad::button_id const
	button_id() const;

	SGE_INPUT_SYMBOL
	bool
	pressed() const;
private:
	joypad::button_id button_id_;

	bool pressed_;
};

}
}
}

#endif
