/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2013 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include <sge/charconv/system_fwd.hpp>
#include <sge/font/object.hpp>
#include <sge/font/parameters.hpp>
#include <sge/font/string.hpp>
#include <sge/font/text.hpp>
#include <sge/font/text_parameters_fwd.hpp>
#include <sge/font/text_unique_ptr.hpp>
#include <sge/image/color/format.hpp>
#include <sge/image/color/optional_format.hpp>
#include <sge/pango/create_layout.hpp>
#include <sge/pango/glib_deleter.hpp>
#include <sge/pango/object.hpp>
#include <sge/pango/text.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/scoped_ptr_impl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <pango/pango-fontmap.h>
#include <pango/pango-types.h>
#include <pango/pangoft2.h>
#include <fcppt/config/external_end.hpp>


sge::pango::object::object(
	sge::charconv::system &_charconv_system,
	sge::font::parameters const &_parameters
)
:
	sge::font::object(),
	charconv_system_(
		_charconv_system
	),
	font_map_(
		::pango_ft2_font_map_new()
	),
	context_(
		::pango_font_map_create_context(
			font_map_.get()
		)
	),
	layout_(
		sge::pango::create_layout(
			*context_,
			_parameters
		)
	)
{
	if(
		_parameters.dpi()
	)
		::pango_ft2_font_map_set_resolution(
			reinterpret_cast<
				PangoFT2FontMap *
			>(
				font_map_.get()
			),
			_parameters.dpi()->x(),
			_parameters.dpi()->y()
		);
}

sge::pango::object::~object()
{
}

sge::font::text_unique_ptr
sge::pango::object::create_text(
	sge::font::string const &_text,
	sge::font::text_parameters const &_parameters
)
{
	return
		sge::font::text_unique_ptr(
			fcppt::make_unique_ptr<
				sge::pango::text
			>(
				charconv_system_,
				*layout_,
				_text,
				_parameters
			)
		);
}

sge::image::color::optional_format const
sge::pango::object::color_format() const
{
	// TODO: This should be extended to all formats
	return
		sge::image::color::optional_format(
			sge::image::color::format::a8
		);
}
