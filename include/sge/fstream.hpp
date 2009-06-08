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


#ifndef SGE_FSTREAM_HPP_INCLUDED
#define SGE_FSTREAM_HPP_INCLUDED

#include <sge/config.h>
#include <boost/filesystem/fstream.hpp>

namespace sge
{

typedef boost::filesystem::ifstream cifstream;
typedef boost::filesystem::ofstream cofstream;
typedef boost::filesystem::fstream cfstream;

#ifndef SGE_NARROW_STRING
typedef boost::filesystem::wifstream ifstream;
typedef boost::filesystem::wofstream ofstream;
typedef boost::filesystem::wfstream  fstream;
#else
typedef boost::filesystem::ifstream ifstream;
typedef boost::filesystem::ofstream ofstream;
typedef boost::filesystem::fstream  fstream;
#endif

}

#endif
