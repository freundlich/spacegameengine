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


#ifndef SGE_X11INPUT_DEVICE_INFO_MULTI_HPP_INCLUDED
#define SGE_X11INPUT_DEVICE_INFO_MULTI_HPP_INCLUDED

#include <sge/x11input/device/info/base.hpp>
#include <awl/backends/x11/display_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/extensions/XInput2.h>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace x11input
{
namespace device
{
namespace info
{

class multi
{
	FCPPT_NONCOPYABLE(
		multi
	);
public:
	typedef info::base::size_type size_type;

	explicit
	multi(
		awl::backends::x11::display &
	);

	~multi();

	XIDeviceInfo const &
	operator[](
		size_type index
	) const;

	size_type
	size() const;
private:
	sge::x11input::device::info::base info_base_;
};

}
}
}
}

#endif
