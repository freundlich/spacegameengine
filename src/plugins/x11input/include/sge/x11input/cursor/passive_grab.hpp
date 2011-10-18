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


#ifndef SGE_X11INPUT_CURSOR_PASSIVE_GRAB_HPP_INCLUDED
#define SGE_X11INPUT_CURSOR_PASSIVE_GRAB_HPP_INCLUDED

#include <sge/x11input/cursor/passive_grab_fwd.hpp>
#include <sge/x11input/cursor/image.hpp>
#include <sge/x11input/device/id.hpp>
#include <awl/backends/x11/window/instance_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/extensions/XInput2.h>
#include <fcppt/config/external_end.hpp>

namespace sge
{
namespace x11input
{
namespace cursor
{

class passive_grab
{
	FCPPT_NONCOPYABLE(
		passive_grab
	);
public:
	passive_grab(
		awl::backends::x11::window::instance &,
		x11input::device::id,
		cursor::image
	);

	~passive_grab();
private:
	awl::backends::x11::window::instance &window_;

	x11input::device::id const id_;

	int const num_modifiers_;

	XIGrabModifiers modifiers_;
};

}
}
}

#endif