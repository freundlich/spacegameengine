/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2012 Carl Philipp Reh (sefi@s-e-f-i.de)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/


#include <sge/charconv/convert.hpp>
#include <sge/charconv/encoding.hpp>
#include <sge/charconv/system_fwd.hpp>
#include <sge/charconv/utf8_string.hpp>
#include <sge/font/dim.hpp>
#include <sge/font/text.hpp>
#include <sge/font/text_parameters.hpp>
#include <sge/font/view_fwd.hpp>
#include <sge/image2d/dim.hpp>
#include <sge/image2d/view/size.hpp>
#include <sge/pango/glib_deleter.hpp>
#include <sge/pango/text.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <pango/pangoft2.h>
#include <pango/pango-layout.h>
#include <fcppt/config/external_end.hpp>


sge::pango::text::text(
	sge::charconv::system &_charconv_system,
	PangoLayout &_layout,
	sge::font::text_parameters const &_text_parameters
)
:
	layout_(
		::pango_layout_copy(
			&_layout
		)
	)
{
	{
		sge::charconv::utf8_string const converted_string(
			sge::charconv::convert<
				sge::charconv::encoding::utf8,
				sge::charconv::encoding::wchar
			>(
				_charconv_system,
				_text_parameters.string()
			)
		);

		::pango_layout_set_text(
			layout_.get(),
			reinterpret_cast<
				char const *
			>(
				converted_string.data()
			),
			static_cast<
				int
			>(
				converted_string.size()
			)
		);
	}
}

sge::pango::text::~text()
{
}

#include <sge/image2d/view/data.hpp>

void
sge::pango::text::render(
	sge::font::view const &_view
)
{
	sge::image2d::dim const view_size(
		sge::image2d::view::size(
			_view
		)
	);

	::pango_layout_set_width(
		layout_.get(),
		static_cast<
			int
		>(
			view_size.w()
		)
	);

	::pango_layout_set_height(
		layout_.get(),
		static_cast<
			int
		>(
			view_size.h()
		)
	);

	// FIXME!
	FT_Bitmap bitmap;

	bitmap.rows = static_cast<int>(view_size.w());
	bitmap.width = static_cast<int>(view_size.w());
	bitmap.pitch = static_cast<int>(view_size.w());
	bitmap.buffer = sge::image2d::view::data(_view);
	bitmap.num_grays = 256;
	bitmap.pixel_mode = FT_PIXEL_MODE_GRAY;

	/*
	FT_Bitmap bitmap(
		sge::pango::freetype::make_bitmap(
			_view
		)
	);
	*/

	::pango_ft2_render_layout(
		&bitmap,
		layout_.get(),
		0,
		0
	);
}

sge::font::dim const
sge::pango::text::size()
{
	/*
	if(
		!size
	)
	{
		sge::pango::glyph_string_size(
			context_,
			font_,

		//pango_glyph_string_extents*/
}
