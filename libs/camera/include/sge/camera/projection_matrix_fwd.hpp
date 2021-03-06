//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_CAMERA_PROJECTION_MATRIX_FWD_HPP_INCLUDED
#define SGE_CAMERA_PROJECTION_MATRIX_FWD_HPP_INCLUDED

#include <sge/renderer/matrix4_fwd.hpp>
#include <fcppt/make_strong_typedef.hpp>


namespace sge
{
namespace camera
{

FCPPT_MAKE_STRONG_TYPEDEF(
	sge::renderer::matrix4,
	projection_matrix
);

}
}

#endif
