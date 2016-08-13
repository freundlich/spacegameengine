/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2016 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#ifndef SGE_EVDEV_DEVICE_OBJECT_HPP_INCLUDED
#define SGE_EVDEV_DEVICE_OBJECT_HPP_INCLUDED

#include <sge/evdev/device/event_fwd.hpp>
#include <sge/evdev/device/fd_fwd.hpp>
#include <sge/evdev/device/fd_unique_ptr.hpp>
#include <awl/backends/posix/event_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/signal/auto_connection.hpp>


namespace sge
{
namespace evdev
{
namespace device
{

class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	object(
		awl::backends::posix::processor &,
		sge::evdev::device::fd_unique_ptr
	);

	virtual
	~object() = 0;

	void
	on_event(
		awl::backends::posix::event const &
	);
protected:
	sge::evdev::device::fd const &
	fd() const;
private:
	virtual
	void
	process_event(
		sge::evdev::device::event const &
	) = 0;

	sge::evdev::device::fd_unique_ptr const fd_;

	fcppt::signal::auto_connection const auto_connection_;
};

}
}
}

#endif
