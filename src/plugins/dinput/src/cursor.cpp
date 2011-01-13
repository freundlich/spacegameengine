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


#include "../cursor.hpp"
#include <awl/backends/windows/window/event/processor.hpp>
#include <awl/backends/windows/window/event/object.hpp>
#include <awl/backends/windows/windows.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/math/vector/basic_impl.hpp>
#include <fcppt/signal/connection_manager.hpp>
#include <fcppt/signal/object_impl.hpp>
#include <fcppt/signal/shared_connection.hpp>
#include <fcppt/tr1/functional.hpp>
#include <fcppt/optional_impl.hpp>

sge::dinput::cursor::cursor(
	awl::backends::windows::window::event::processor_ptr const _processor
)
:
	button_signal_(),
	move_signal_(),
	connections_(
		fcppt::assign::make_container<
			fcppt::signal::connection_manager::container
		>(
			fcppt::signal::shared_connection(
				_processor->register_callback(
					WM_MOUSEMOVE,
					std::tr1::bind(
						&dinput::cursor::on_move,
						this,
						std::tr1::placeholders::_1
					)
				)
			)
		)
	)
{
}

sge::dinput::cursor::~cursor()
{
}

fcppt::signal::auto_connection
sge::dinput::cursor::button_callback(
	input::cursor::button_callback const &_callback
)
{
	return
		button_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
sge::dinput::cursor::move_callback(
	input::cursor::move_callback const &_callback
)
{
	return
		move_signal_.connect(
			_callback
		);
}

sge::input::cursor::position const
sge::dinput::cursor::position() const
{
	return sge::input::cursor::position();
}

void
sge::dinput::cursor::window_mode(
	input::cursor::window_mode::type const _mode
)
{
}

awl::backends::windows::window::event::return_type
sge::dinput::cursor::on_move(
	awl::backends::windows::window::event::object const &_event
)
{
	return awl::backends::windows::window::event::return_type();
}
