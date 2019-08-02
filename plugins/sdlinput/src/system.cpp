//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/input/capabilities.hpp>
#include <sge/input/capabilities_field.hpp>
#include <sge/input/processor.hpp>
#include <sge/input/processor_unique_ptr.hpp>
#include <sge/input/system.hpp>
#include <sge/window/object_fwd.hpp>
#include <sge/sdlinput/processor.hpp>
#include <sge/sdlinput/system.hpp>
#include <awl/backends/sdl/window/object.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>


sge::sdlinput::system::system()
:
	sge::input::system()
{
}

sge::sdlinput::system::~system()
{
}

sge::input::processor_unique_ptr
sge::sdlinput::system::create_processor(
	sge::window::object &_window
)
{
	return
		fcppt::unique_ptr_to_base<
			sge::input::processor
		>(
			fcppt::make_unique_ptr<
				sge::sdlinput::processor
			>(
				_window
			)
		);
}

sge::input::capabilities_field
sge::sdlinput::system::capabilities() const
{
	return
		sge::input::capabilities_field{
			sge::input::capabilities::cursor,
			sge::input::capabilities::focus,
			sge::input::capabilities::joypad,
			sge::input::capabilities::keyboard,
			sge::input::capabilities::mouse
		};
}