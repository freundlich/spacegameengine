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


#ifndef SGE_CONSOLE_VAR_HPP_INCLUDED
#define SGE_CONSOLE_VAR_HPP_INCLUDED

#include <sge/console/var_base.hpp>
#include <sge/console/object_fwd.hpp>
#include <sge/string.hpp>

namespace sge
{
namespace console
{
template<typename T>
class var : public var_base {
public:
	typedef T value_type;

	var(
		object &,
		string const &name,
		value_type const & = value_type());

	void string(sge::string const &); 
	sge::string const string() const;

	value_type const &value() const;
	void value(value_type const &);

private:
	value_type t;
};
}
}

#endif

