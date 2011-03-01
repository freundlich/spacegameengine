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


#ifndef SGE_D3D9_TEXTURE_LOCK_PLANAR_HPP_INCLUDED
#define SGE_D3D9_TEXTURE_LOCK_PLANAR_HPP_INCLUDED

#include "optional_lock_rect.hpp"
#include "../d3dinclude.hpp"
#include "../lock_flags.hpp"
#include <sge/renderer/stage_type.hpp>

namespace sge
{
namespace d3d9
{
namespace texture
{

D3DLOCKED_RECT const
lock_planar(
	IDirect3DTexture9 *,
	sge::renderer::stage_type,
	d3d9::texture::optional_lock_rect const &,
	d3d9::lock_flags
);

}
}
}

#endif
