//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/input/joypad/axis_value.hpp>
#include <sge/input/joypad/shared_ptr.hpp>
#include <sge/input/joypad/event/absolute_axis.hpp>
#include <sge/sdlinput/joypad/device.hpp>
#include <sge/sdlinput/joypad/from_event.hpp>
#include <sge/sdlinput/joypad/map.hpp>
#include <sge/sdlinput/joypad/shared_ptr.hpp>
#include <sge/sdlinput/joypad/translate_axis_event.hpp>
#include <awl/event/base.hpp>
#include <awl/event/container.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/container/make.hpp>
#include <fcppt/config/external_begin.hpp>
#include <SDL_events.h>
#include <fcppt/config/external_end.hpp>


awl::event::container
sge::sdlinput::joypad::translate_axis_event(
	sge::sdlinput::joypad::map const &_joypads,
	SDL_JoyAxisEvent const &_event
)
{
	sge::sdlinput::joypad::shared_ptr const joypad{
		sge::sdlinput::joypad::from_event(
			_joypads,
			_event
		)
	};

	return
		fcppt::container::make<
			awl::event::container
		>(
			fcppt::unique_ptr_to_base<
				awl::event::base
			>(
				fcppt::make_unique_ptr<
					sge::input::joypad::event::absolute_axis
				>(
					sge::input::joypad::shared_ptr{
						joypad
					},
					joypad->axis(
						_event.axis
					),
					sge::input::joypad::axis_value{
						_event.value
					}
				)
			)
		);
}
