//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_RENDERER_CAPS_LIGHT_INDICES_HPP_INCLUDED
#define SGE_RENDERER_CAPS_LIGHT_INDICES_HPP_INCLUDED

#include <sge/renderer/state/index_count.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace sge
{
namespace renderer
{
namespace caps
{

/**
\brief A strong typedef for the maximum number of lights

\ingroup sge_renderer
*/
FCPPT_MAKE_STRONG_TYPEDEF(
	sge::renderer::state::index_count,
	light_indices
);

}
}
}

#endif
