/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include "../keyboard_keys.hpp"
#include "../translation.hpp"
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <sge/x11/sentry.hpp>
#include <sge/input/key_type.hpp>
#include <sge/log/headers.hpp>
#include <sge/text.hpp>
#include <sge/string.hpp>
#include <sge/iconv.hpp>
#include <boost/tr1/array.hpp>
#include <map>
#include <ostream>
#include <utility>

namespace
{

sge::string const
get_key_name(
	KeySym const ks);

}

sge::input::key_type const
sge::x11input::keyboard_key(
	XKeyEvent const &xev)
{
	XComposeStatus state;
	KeySym ks;
	std::tr1::array<char, 32> keybuf;

	SGE_X11_SENTRY

	int const num_chars = XLookupString(
		const_cast<XKeyEvent *>(&xev),
		keybuf.c_array(),
		static_cast<int>(keybuf.size()),
		&ks,
		&state);

	char const code = keybuf[0];

	if(num_chars > 1)
	{
		SGE_LOG_WARNING(
			log::global(),
			log::_1
				<< SGE_TEXT("stub: character '")
				<< code
				<< SGE_TEXT("' in XLookupString has ")
				<< num_chars
				<< SGE_TEXT(" bytes!"));
		return input::key_type();
	}

	return input::key_type(
		get_key_name(ks),
		translate_key_code(ks),
		code);
}

namespace
{

sge::string const
get_key_name(
	KeySym const ks)
{
	typedef std::map<
		KeySym,
		sge::string
	> name_map;

	static name_map names;

	name_map::const_iterator const it(
		names.find(ks));

	if(names.find(ks) != names.end())
		return it->second;

	SGE_X11_SENTRY

	char const* const name = XKeysymToString(ks);
	return names.insert(
		std::make_pair(
			ks,
			name
			? sge::iconv(name)
			: SGE_TEXT("unknown"))).first->second;
}

}
