//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_EVDEV_JOYPAD_ADD_HPP_INCLUDED
#define SGE_EVDEV_JOYPAD_ADD_HPP_INCLUDED

#include <sge/evdev/joypad/map.hpp>
#include <sge/window/object_fwd.hpp>
#include <awl/backends/posix/processor_fwd.hpp>
#include <awl/event/optional_base_unique_ptr.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace evdev
{
namespace joypad
{

awl::event::optional_base_unique_ptr
add(
	fcppt::log::object &,
	sge::window::object &,
	awl::backends::posix::processor &,
	sge::evdev::joypad::map &,
	std::filesystem::path const &
);

}
}
}

#endif
