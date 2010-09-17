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


#include <X11/Xlib.h>
#include <sge/x11/display.hpp>
#include <sge/x11/window.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include "../warp_pointer.hpp"

void
sge::x11input::warp_pointer(
	x11::window_ptr const _wnd,
	mouse_pos const &_pos
)
{
	// always returns 1
	
	XWarpPointer(
		_wnd->display()->get(),
		None,
		_wnd->get(),
		0,
		0,
		0,
		0,
		_pos.x(),
		_pos.y()
	);
}