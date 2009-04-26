/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

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
#include <sge/bad_lexical_cast.hpp>
#include <sge/text.hpp>

sge::bad_lexical_cast::bad_lexical_cast(
	sge::type_info const &_source,
	sge::type_info const &_destination)
:
	exception(
		SGE_TEXT("Invalid lexical cast from type \"")+
		_source.name()+
		SGE_TEXT("\" to type \"")+
		_destination.name()+
		SGE_TEXT("\"")),
	source_(_source),
	destination_(_destination)
{
}

sge::type_info const &sge::bad_lexical_cast::source() const
{
	return source_;
}

sge::type_info const &sge::bad_lexical_cast::destination() const
{
	return destination_;
}
