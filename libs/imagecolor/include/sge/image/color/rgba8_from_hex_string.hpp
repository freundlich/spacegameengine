//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_IMAGE_COLOR_RGBA8_FROM_HEX_STRING_HPP_INCLUDED
#define SGE_IMAGE_COLOR_RGBA8_FROM_HEX_STRING_HPP_INCLUDED

#include <sge/image/color/rgb8_from_hex_string.hpp>
#include <sge/image/color/rgba8.hpp>
#include <sge/image/color/init/alpha.hpp>
#include <sge/image/color/init/blue.hpp>
#include <sge/image/color/init/green.hpp>
#include <sge/image/color/init/red.hpp>
#include <mizuiro/color/channel/blue.hpp>
#include <mizuiro/color/channel/green.hpp>
#include <mizuiro/color/channel/red.hpp>


namespace sge
{
namespace image
{
namespace color
{

template<
	typename String
>
sge::image::color::rgba8
rgba8_from_hex_string(
	String const &_string,
	sge::image::color::rgba8::format::channel_type const _alpha
)
{
	sge::image::color::rgb8 const rgb(
		sge::image::color::rgb8_from_hex_string(
			_string
		)
	);

	return
		sge::image::color::rgba8(
			(sge::image::color::init::red() = rgb.get(mizuiro::color::channel::red()))
			(sge::image::color::init::green() = rgb.get(mizuiro::color::channel::green()))
			(sge::image::color::init::blue() = rgb.get(mizuiro::color::channel::blue()))
			(sge::image::color::init::alpha() = _alpha)
		);
}

}
}
}

#endif
