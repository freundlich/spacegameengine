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


#include <sge/dinput/di.hpp>
#include <sge/dinput/is_down.hpp>
#include <sge/dinput/device/object.hpp>
#include <sge/dinput/device/parameters.hpp>
#include <sge/dinput/mouse/axis_map.hpp>
#include <sge/dinput/mouse/button_map.hpp>
#include <sge/dinput/mouse/device.hpp>
#include <sge/dinput/mouse/make_info.hpp>
#include <sge/input/info/name.hpp>
#include <sge/input/mouse/axis.hpp>
#include <sge/input/mouse/axis_callback.hpp>
#include <sge/input/mouse/axis_id.hpp>
#include <sge/input/mouse/axis_event.hpp>
#include <sge/input/mouse/axis_value.hpp>
#include <sge/input/mouse/button.hpp>
#include <sge/input/mouse/button_callback.hpp>
#include <sge/input/mouse/button_id.hpp>
#include <sge/input/mouse/button_event.hpp>
#include <sge/input/mouse/button_pressed.hpp>
#include <sge/input/mouse/device.hpp>
#include <sge/input/mouse/info_fwd.hpp>
#include <fcppt/optional/maybe_void.hpp>
#include <fcppt/container/find_opt_mapped.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/object_impl.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

sge::dinput::mouse::device::device(
	sge::dinput::device::parameters const &_parameters
)
:
	sge::input::mouse::device(),
	sge::dinput::device::object(
		_parameters,
		c_dfDIMouse2
	),
	info_(
		sge::dinput::mouse::make_info(
			this->get(),
			_parameters.name()
		)
	),
	axis_signal_(),
	button_signal_()
{
}

FCPPT_PP_POP_WARNING

sge::dinput::mouse::device::~device()
{
}

fcppt::signal::auto_connection
sge::dinput::mouse::device::axis_callback(
	sge::input::mouse::axis_callback const &_callback
)
{
	return
		axis_signal_.connect(
			_callback
		);
}

fcppt::signal::auto_connection
sge::dinput::mouse::device::button_callback(
	sge::input::mouse::button_callback const &_callback
)
{
	return
		button_signal_.connect(
			_callback
		);
}

sge::input::mouse::info const &
sge::dinput::mouse::device::info() const
{
	return
		info_.input_info();
}

void
sge::dinput::mouse::device::on_dispatch(
	DIDEVICEOBJECTDATA const &_data
)
{
	fcppt::optional::maybe_void(
		fcppt::container::find_opt_mapped(
			info_.axis_map(),
			_data.dwOfs
		),
		[
			this,
			&_data
		](
			sge::input::mouse::axis_id const _id
		)
		{
			axis_signal_(
				sge::input::mouse::axis_event(
					sge::input::mouse::axis(
						info_.input_info().axes()[
							_id
						].code(),
						_id
					),
					static_cast<
						sge::input::mouse::axis_value
					>(
						_data.dwData
					)
				)
			);
		}
	);

	fcppt::optional::maybe_void(
		fcppt::container::find_opt_mapped(
			info_.button_map(),
			_data.dwOfs
		),
		[
			this,
			&_data
		](
			sge::input::mouse::button_id const _id
		)
		{
			button_signal_(
				sge::input::mouse::button_event(
					sge::input::mouse::button(
						info_.input_info().buttons()[
							_id
						].code(),
						_id
					),
					sge::input::mouse::button_pressed{
						sge::dinput::is_down(
							_data.dwData
						)
					}
				)
			);
		}
	);
}
