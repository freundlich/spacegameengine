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
#include <sge/d3d9/get_display_modes_for_format.hpp>
#include <sge/d3d9/optional_display_mode.hpp>
#include <sge/d3d9/convert/to_display_mode.hpp>
#include <sge/d3d9/systemfuncs/enum_adapter_modes.hpp>
#include <sge/renderer/device/index.hpp>
#include <sge/renderer/display_mode/container.hpp>
#include <fcppt/optional_bind_construct.hpp>
#include <fcppt/algorithm/map_optional.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/range/irange.hpp>
#include <fcppt/config/external_end.hpp>


sge::renderer::display_mode::container
sge::d3d9::get_display_modes_for_format(
	IDirect3D9 &_d3d9,
	sge::renderer::device::index const _index,
	D3DFORMAT const _format
)
{
	return
		fcppt::algorithm::map_optional<
			sge::renderer::display_mode::container
		>(
			boost::irange(
				0u,
				_d3d9.GetAdapterModeCount(
					_index.get(),
					_format
				)
			),
			[
				&_d3d9,
				_index,
				_format
			](
				UINT const _mode_index
			)
			{
				return
					fcppt::optional_bind_construct(
						sge::d3d9::systemfuncs::enum_adapter_modes(
							_d3d9,
							_index,
							_format,
							_mode_index
						),
						[](
							D3DDISPLAYMODE const _mode
						)
						{
							return
								sge::d3d9::convert::to_display_mode(
									_mode
								);
						}
					);
			}
		);
}