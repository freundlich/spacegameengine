//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_IMAGE_COLOR_IMPL_TRAITS_FORMAT_MAP_HPP_INCLUDED
#define SGE_IMAGE_COLOR_IMPL_TRAITS_FORMAT_MAP_HPP_INCLUDED

#include <sge/image/color/tag.hpp>
#include <sge/image/color/impl/format_map.hpp>
#include <sge/image/impl/traits/pixel/format_map_tpl_fwd.hpp>


namespace sge
{
namespace image
{
namespace impl
{
namespace traits
{
namespace pixel
{

template<>
struct format_map_tpl<
	sge::image::color::tag
>
{
	using
	type
	=
	sge::image::color::impl::format_map;
};

}
}
}
}
}

#endif
