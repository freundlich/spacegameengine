//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_RENDERER_STATE_FFP_LIGHTING_MATERIAL_EMISSIVE_COLOR_HPP_INCLUDED
#define SGE_RENDERER_STATE_FFP_LIGHTING_MATERIAL_EMISSIVE_COLOR_HPP_INCLUDED

#include <sge/image/color/any/object.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace sge
{
namespace renderer
{
namespace state
{
namespace ffp
{
namespace lighting
{
namespace material
{

FCPPT_MAKE_STRONG_TYPEDEF(
	sge::image::color::any::object,
	emissive_color
);

}
}
}
}
}
}

#endif
