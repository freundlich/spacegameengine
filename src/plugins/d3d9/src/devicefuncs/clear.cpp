/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2015 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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
#include <sge/d3d9/convert/to_color.hpp>
#include <sge/d3d9/devicefuncs/clear.hpp>
#include <sge/renderer/exception.hpp>
#include <sge/renderer/clear/back_buffer_value.hpp>
#include <sge/renderer/clear/depth_buffer_value.hpp>
#include <sge/renderer/clear/parameters.hpp>
#include <sge/renderer/clear/stencil_buffer_value.hpp>
#include <fcppt/const.hpp>
#include <fcppt/from_optional.hpp>
#include <fcppt/optional/maybe.hpp>
#include <fcppt/optional/object_impl.hpp>
#include <fcppt/text.hpp>


namespace
{

template<
	typename T
>
DWORD
make_flag(
	fcppt::optional::object<
		T
	>,
	DWORD
);

}

void
sge::d3d9::devicefuncs::clear(
	IDirect3DDevice9 &_device,
	sge::renderer::clear::parameters const &_parameters
)
{
	if(
		_device.Clear(
			0u,
			nullptr,
			::make_flag(
				_parameters.back_buffer(),
				D3DCLEAR_TARGET
			)
			|
			::make_flag(
				_parameters.depth_buffer(),
				D3DCLEAR_ZBUFFER
			)
			|
			::make_flag(
				_parameters.stencil_buffer(),
				D3DCLEAR_STENCIL
			),
			fcppt::optional::maybe(
				_parameters.back_buffer(),
				fcppt::const_<
					D3DCOLOR
				>(
					0
				),
				[](
					sge::renderer::clear::back_buffer_value const _back_buffer
				)
				{
					return
						sge::d3d9::convert::to_color(
							_back_buffer
						);
				}
			),
			fcppt::from_optional(
				_parameters.depth_buffer(),
				fcppt::const_(
					0.f
				)
			),
			// TODO: why is the stencil clear value a DWORD?
			fcppt::optional::maybe(
				_parameters.stencil_buffer(),
				fcppt::const_<
					DWORD
				>(
					0
				),
				[](
					sge::renderer::clear::stencil_buffer_value const _stencil_buffer
				)
				-> DWORD
				{
					return
						_stencil_buffer;
				}
			)
		)
		!= D3D_OK
	)
		throw
			sge::renderer::exception{
				FCPPT_TEXT("Clear() failed!")
			};
}

namespace
{

template<
	typename T
>
DWORD
make_flag(
	fcppt::optional::object<
		T
	> const _enabled,
	DWORD const _flag
)
{
	return
		_enabled.has_value()
		?
			_flag
		:
			0u
		;
}

}
