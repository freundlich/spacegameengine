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


#include <sge/evdev/eventfd/callback.hpp>
#include <sge/evdev/eventfd/object.hpp>
#include <awl/backends/x11/system/event/processor.hpp>
#include <fcppt/assert/error.hpp>
#include <fcppt/function/object.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/cstdint.hpp>
#include <unistd.h>
#include <fcppt/config/external_end.hpp>


sge::evdev::eventfd::object::object(
	awl::backends::x11::system::event::processor &_processor,
	sge::evdev::eventfd::callback const &_callback
)
:
	fd_(),
	fd_connection_(
		_processor.register_fd_callback(
			fd_.get(),
			std::tr1::bind(
				_callback
			)
		)
	)
{
}


sge::evdev::eventfd::object::~object()
{
}

void
sge::evdev::eventfd::object::write()
{
	typedef boost::uint64_t value_type;

	value_type const value(
		1u
	);

	FCPPT_ASSERT_ERROR(
		::write(
			fd_.get().get(),
			&value,
			sizeof(
				value_type
			)
		)
		==
		sizeof(
			value_type
		)
	);
}
