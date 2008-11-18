#ifndef SGE_GUI_UTILITY_FONT_BLITTER_HPP_INCLUDED
#define SGE_GUI_UTILITY_FONT_BLITTER_HPP_INCLUDED

#include "font_channel_blitter.hpp"
#include <sge/gui/types.hpp>
#include <sge/renderer/color_convert.hpp>
#include <boost/mpl/for_each.hpp>

#include <boost/gil/color_convert.hpp>

namespace sge
{
namespace gui
{
namespace utility
{
class font_blitter
{
	public:
	explicit font_blitter(
		color const &font_color);

	template<
		typename Src1,
		typename Src2,
		typename Dst
	>
	void operator()(
		Src1 const &src_color,
		Src2 const &font_value,
		Dst &dst_color) const;
	
	private:
	color const font_color;
};
}
}
}

sge::gui::utility::font_blitter::font_blitter(
	color const &font_color)
	: font_color(font_color)
{
}

template<
	typename Src1,
	typename Src2,
	typename Dst
>
void
sge::gui::utility::font_blitter::operator()(
	Src1 const &src_color,
	Src2 const &font_value,
	Dst &result) const
{
	Dst src1, src2;
	boost::gil::color_convert(src_color, src1);
	boost::gil::color_convert(font_value, src2);

	boost::mpl::for_each<typename Dst::layout_t::channel_mapping_t>(
		font_channel_blitter<Dst,Src2>(
			src1,
			src2,
			//src_color,
			//font_color,
			//renderer::color_convert<Dst>(src_color),
			//renderer::color_convert<Dst>(font_color),
			font_value,
			result));
}

#endif
