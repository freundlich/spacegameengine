//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_RENDERER_CAPS_RENDER_TARGET_INVERTED_HPP_INCLUDED
#define SGE_RENDERER_CAPS_RENDER_TARGET_INVERTED_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace sge
{
namespace renderer
{
namespace caps
{

/**
\brief A strong typedef for a bool telling if render targets are inverted

\ingroup sge_renderer
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	bool,
	render_target_inverted
);

}
}
}

#endif
