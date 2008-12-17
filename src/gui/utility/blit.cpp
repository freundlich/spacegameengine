#include "blit.hpp"
#include <sge/renderer/copy_and_convert_pixels.hpp>
#include <sge/renderer/subimage_view.hpp>
#include <sge/math/rect_util.hpp>

void sge::gui::utility::blit(
	const_image_view const &src,
	rect const &src_rect,
	image_view const dst,
	rect const &dst_rect)
{
	// Calculate intersection of source and destination
	rect const is = math::intersection(
		src_rect,
		dst_rect);
	
	// No intersection? then leave now.
	if (is == rect::null())
		return;

	// Move intersection rect to origin of invalid rect
	rect const is_translated(
		is.pos()-dst_rect.pos(),
		is.dim());
	
	// Get sub view(s) and blit
	renderer::copy_and_convert_pixels(
		src,
		renderer::subimage_view(
			dst,
			math::structure_cast<renderer::size_type>(
				is_translated)));
}
