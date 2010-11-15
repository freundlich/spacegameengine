/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2010 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include <sge/input/mouse/axis_event.hpp>

sge::input::mouse::axis_event::axis_event(
	mouse::axis::type const _axis,
	mouse::axis_position const _axis_position
)
:
	axis_(_axis),
	axis_position_(_axis_position)
{
}

sge::input::mouse::axis::type
sge::input::mouse::axis_event::axis() const
{
	return axis_;
}

sge::input::mouse::axis_position
sge::input::mouse::axis_event::axis_position() const
{
	return axis_position_;
}