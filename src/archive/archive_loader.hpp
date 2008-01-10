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


#ifndef SGE_ARCHIVE_LOADER_HPP_INCLUDED
#define SGE_ARCHIVE_LOADER_HPP_INCLUDED

#include "../path.hpp"
#include "../shared_ptr.hpp"
#include "../plugin_traits.hpp"
#include "archive.hpp"

namespace sge
{

class archive_loader {
public:
	virtual const archive_ptr load_archive(const path&) = 0;
	virtual ~archive_loader() {}
};

typedef shared_ptr<archive_loader> archive_loader_ptr;

namespace detail
{

template<> struct plugin_traits<archive_loader> {
	static const char* plugin_loader_name() { return "create_archive_loader"; }
	static plugin_type::type get_plugin_type() { return plugin_type::archive; }
	typedef archive_loader* (*loader_fun)();
};

}

}

#endif
