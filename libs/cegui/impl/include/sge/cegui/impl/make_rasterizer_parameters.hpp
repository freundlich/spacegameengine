//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_CEGUI_IMPL_MAKE_RASTERIZER_PARAMETERS_HPP_INCLUDED
#define SGE_CEGUI_IMPL_MAKE_RASTERIZER_PARAMETERS_HPP_INCLUDED

#include <sge/renderer/state/core/rasterizer/enable_scissor_test.hpp>
#include <sge/renderer/state/core/rasterizer/parameters_fwd.hpp>


namespace sge
{
namespace cegui
{
namespace impl
{

sge::renderer::state::core::rasterizer::parameters
make_rasterizer_parameters(
	sge::renderer::state::core::rasterizer::enable_scissor_test
);

}
}
}

#endif
