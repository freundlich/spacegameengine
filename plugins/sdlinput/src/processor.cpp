//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/input/processor.hpp>
#include <sge/input/cursor/container.hpp>
#include <sge/input/focus/container.hpp>
#include <sge/input/joypad/container.hpp>
#include <sge/input/keyboard/container.hpp>
#include <sge/input/mouse/container.hpp>
#include <sge/sdlinput/processor.hpp>
#include <sge/sdlinput/cursor/object.hpp>
#include <sge/sdlinput/focus/object.hpp>
#include <sge/sdlinput/keyboard/device.hpp>
#include <sge/sdlinput/mouse/device.hpp>
#include <sge/sdlinput/translate/event.hpp>
#include <sge/window/object.hpp>
#include <sge/window/system.hpp>
#include <sge/window/system_event_function.hpp>
#include <awl/backends/sdl/window/object.hpp>
#include <awl/backends/sdl/system/event/object.hpp>
#include <awl/event/base.hpp>
#include <awl/event/container.hpp>
#include <awl/window/object.hpp>
#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/dynamic.hpp>
#include <fcppt/cast/dynamic_exn.hpp>
#include <fcppt/optional/maybe.hpp>


sge::sdlinput::processor::processor(
	sge::window::object &_window
)
:
	sge::input::processor{},
	window_{
		_window
	},
	sdl_window_{
		fcppt::cast::dynamic_exn<
			awl::backends::sdl::window::object &
		>(
			_window.awl_object()
		)
	},
	cursor_{
		fcppt::make_shared_ptr<
			sge::sdlinput::cursor::object
		>(
			_window,
			this->sdl_window_
		)
	},
	focus_{
		fcppt::make_shared_ptr<
			sge::sdlinput::focus::object
		>(
			_window
		)
	},
	keyboard_{
		fcppt::make_shared_ptr<
			sge::sdlinput::keyboard::device
		>(
			_window
		)
	},
	mouse_{
		fcppt::make_shared_ptr<
			sge::sdlinput::mouse::device
		>(
			_window
		)
	},
	event_connection_{
		_window.system().event_handler(
			sge::window::system_event_function{
				[
					this
				](
					awl::event::base const &_event
				)
				{
					return
						this->on_event(
							_event
						);
				}
			}
		)
	}
{
}

sge::sdlinput::processor::~processor()
{
}

sge::window::object &
sge::sdlinput::processor::window() const
{
	return
		this->window_;
}

sge::input::cursor::container
sge::sdlinput::processor::cursors() const
{
	return
		sge::input::cursor::container{
			this->cursor_
		};
}

sge::input::focus::container
sge::sdlinput::processor::foci() const
{
	return
		sge::input::focus::container{
			this->focus_
		};
}

sge::input::joypad::container
sge::sdlinput::processor::joypads() const
{
	// TODO
	return
		sge::input::joypad::container{};
}

sge::input::keyboard::container
sge::sdlinput::processor::keyboards() const
{
	return
		sge::input::keyboard::container{
			this->keyboard_
		};
}

sge::input::mouse::container
sge::sdlinput::processor::mice() const
{
	return
		sge::input::mouse::container{
			this->mouse_
		};
}

awl::event::container
sge::sdlinput::processor::on_event(
	awl::event::base const &_event
)
{
	return
		fcppt::optional::maybe(
			fcppt::cast::dynamic<
				awl::backends::sdl::system::event::object const
			>(
				_event
			),
			[]{
				return
					awl::event::container{};
			},
			[
				this
			](
				fcppt::reference<
					awl::backends::sdl::system::event::object const
				> const _sdl_event
			)
			{
				return
					sge::sdlinput::translate::event(
						this->cursor_,
						this->focus_,
						this->keyboard_,
						this->mouse_,
						this->sdl_window_,
						_sdl_event.get()
					);
			}
		);
}