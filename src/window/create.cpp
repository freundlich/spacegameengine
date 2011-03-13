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


#include <sge/window/create.hpp>
#include <sge/window/parameters.hpp>
#include <sge/window/instance.hpp>
#include <awl/system/event/create_processor.hpp>
#include <awl/system/event/processor.hpp>
#include <awl/system/event/processor_shared_ptr.hpp>
#include <awl/window/event/create_processor.hpp>
#include <awl/window/event/processor.hpp>
#include <awl/window/event/processor_shared_ptr.hpp>
#include <fcppt/make_shared_ptr.hpp>

sge::window::instance_ptr const
sge::window::create(
	sge::window::parameters const &_param
)
{
	return
		fcppt::make_shared_ptr<
			sge::window::instance
		>(
			_param.system(),
			_param.window(),
			_param.window_event_processor()
			?
				_param.window_event_processor()
			:
				awl::window::event::processor_shared_ptr(
					awl::window::event::create_processor(
						*_param.window()
					)
				),
			_param.system_event_processor()
			?
				_param.system_event_processor()
			:
				awl::system::event::processor_shared_ptr(
					awl::system::event::create_processor(
						*_param.system()
					)
				),
			_param.io_service()
		);
}
