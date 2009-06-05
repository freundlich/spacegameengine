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


#ifndef SGE_PREPROCESSOR_MESSAGE_HPP_INCLUDED
#define SGE_PREPROCESSOR_MESSAGE_HPP_INCLUDED

#include <sge/preprocessor/pragma.hpp>
#include <sge/config.h>

#ifdef _MSC_VER
#define SGE_PP_MESSAGE(x) SGE_PP_PRAGMA(message (x))
#elif defined(SGE_HAVE_GCC_PRAGMA_MESSAGE)
#define SGE_PP_MESSAGE(x) SGE_PP_PRAGMA(message (x))
#else
#define SGE_PP_MESSAGE(x)
#endif

#endif
