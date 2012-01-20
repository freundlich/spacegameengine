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


#ifndef SGE_SPRITE_BUFFERS_OPTION_TO_RESOURCE_FLAGS_HPP_INCLUDED
#define SGE_SPRITE_BUFFERS_OPTION_TO_RESOURCE_FLAGS_HPP_INCLUDED

#include <sge/renderer/resource_flags_field_fwd.hpp>
#include <sge/sprite/buffers_option.hpp>
#include <sge/sprite/symbol.hpp>


namespace sge
{
namespace sprite
{

SGE_SPRITE_SYMBOL
sge::renderer::resource_flags_field const
buffers_option_to_resource_flags(
	sge::sprite::buffers_option::type
);

}
}

#endif