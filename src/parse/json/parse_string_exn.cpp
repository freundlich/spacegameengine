/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include <sge/parse/json/exception.hpp>
#include <sge/parse/json/object.hpp>
#include <sge/parse/json/parse_range.hpp>
#include <sge/parse/json/parse_string_exn.hpp>
#include <fcppt/string.hpp>
#include <fcppt/text.hpp>


sge::parse::json::object const
sge::parse::json::parse_string_exn(
	fcppt::string const &s)
{
	sge::parse::json::object result;
	fcppt::string::const_iterator current =
		s.begin();
	if(!sge::parse::json::parse_range(current,s.end(),result))
		throw
			sge::parse::json::exception(
				FCPPT_TEXT("Error parsing json"));
	return result;
}
