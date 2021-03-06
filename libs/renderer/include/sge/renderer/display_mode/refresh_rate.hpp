//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_RENDERER_DISPLAY_MODE_REFRESH_RATE_HPP_INCLUDED
#define SGE_RENDERER_DISPLAY_MODE_REFRESH_RATE_HPP_INCLUDED

#include <sge/renderer/display_mode/refresh_rate_value.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace sge
{
namespace renderer
{
namespace display_mode
{

/**
\brief A typedef used to describe refresh rates in Hz
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	sge::renderer::display_mode::refresh_rate_value,
	refresh_rate
);

}
}
}

#endif
