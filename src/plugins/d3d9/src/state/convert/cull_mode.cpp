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


#include <sge/d3d9/d3dinclude.hpp>
#include <sge/d3d9/state/convert/cull_mode.hpp>
#include <sge/renderer/state/core/rasterizer/cull_mode.hpp>
#include <fcppt/assert/unreachable.hpp>


D3DCULL
sge::d3d9::state::convert::cull_mode(
	sge::renderer::state::core::rasterizer::cull_mode const _type
)
{
	switch(
		_type
	)
	{
	case sge::renderer::state::core::rasterizer::cull_mode::off:
		return D3DCULL_NONE;
	case sge::renderer::state::core::rasterizer::cull_mode::clockwise:
		return D3DCULL_CW;
	case sge::renderer::state::core::rasterizer::cull_mode::counter_clockwise:
		return D3DCULL_CCW;
	}

	FCPPT_ASSERT_UNREACHABLE;
}
