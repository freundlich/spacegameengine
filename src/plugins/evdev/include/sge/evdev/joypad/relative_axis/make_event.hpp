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


#ifndef SGE_EVDEV_JOYPAD_RELATIVE_AXIS_MAKE_EVENT_HPP_INCLUDED
#define SGE_EVDEV_JOYPAD_RELATIVE_AXIS_MAKE_EVENT_HPP_INCLUDED

#include <sge/input/joypad/relative_axis_event_fwd.hpp>
#include <sge/input/joypad/relative_axis_id.hpp>
#include <sge/input/joypad/relative_axis_info_container_fwd.hpp>
#include <sge/evdev/device/event_fwd.hpp>


namespace sge
{
namespace evdev
{
namespace joypad
{
namespace relative_axis
{

sge::input::joypad::relative_axis_event const
make_event(
	sge::input::joypad::relative_axis_id,
	sge::input::joypad::relative_axis_info_container const &,
	sge::evdev::device::event
);

}
}
}
}

#endif