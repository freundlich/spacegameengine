//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_SDLINPUT_JOYPAD_INSTANCE_ID_HPP_INCLUDED
#define SGE_SDLINPUT_JOYPAD_INSTANCE_ID_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <SDL_joystick.h>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace sdlinput
{
namespace joypad
{

SDL_JoystickID
instance_id(
	SDL_Joystick &
);

}
}
}

#endif