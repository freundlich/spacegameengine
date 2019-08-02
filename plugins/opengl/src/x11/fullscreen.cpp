//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/opengl/x11/fullscreen.hpp>
#include <sge/opengl/x11/fullscreen_atom.hpp>
#include <sge/opengl/x11/state_atom.hpp>
#include <awl/backends/x11/window/base.hpp>
#include <awl/backends/x11/window/basic_property_data.hpp>
#include <awl/backends/x11/window/change_property.hpp>
#include <awl/backends/x11/window/delete_property.hpp>
#include <awl/backends/x11/window/property_data.hpp>
#include <awl/backends/x11/window/property_mode.hpp>
#include <awl/backends/x11/window/property_type.hpp>
#include <awl/backends/x11/window/root.hpp>
#include <awl/backends/x11/window/event/mask.hpp>
#include <awl/backends/x11/window/event/object.hpp>
#include <awl/backends/x11/window/event/send.hpp>
#include <fcppt/cast/to_signed.hpp>
#include <fcppt/config/external_begin.hpp>
#include <X11/X.h>
#include <X11/Xatom.h>
#include <X11/Xlib.h>
#include <fcppt/config/external_end.hpp>


namespace
{

void
set_property(
	awl::backends::x11::window::base &_window,
	sge::opengl::x11::state_atom const _wm_state,
	sge::opengl::x11::fullscreen_atom const _wm_fullscreen,
	bool const _value
)
{
	// TODO: Add an fcppt::cast for this
	long const *const fullscreen{
		reinterpret_cast<
			long const *
		>(
			&_wm_fullscreen.get().get()
		)
	};

	typedef
	awl::backends::x11::window::basic_property_data<
		long
	>
	range_type;

	if(
		_value
	)
		awl::backends::x11::window::change_property(
			_window,
			awl::backends::x11::window::property{
				_wm_state.get()
			},
			awl::backends::x11::window::property_type{
				awl::backends::x11::atom{
					XA_ATOM
				}
			},
			// TODO: We should keep the previous values intact.
			awl::backends::x11::window::property_mode::replace,
			awl::backends::x11::window::property_data{
				range_type{
					fullscreen,
					fullscreen + 1
				}
			}
		);
	else
		awl::backends::x11::window::delete_property(
			_window,
			awl::backends::x11::window::property{
				_wm_state.get()
			}
		);
}

void
send_event(
	awl::backends::x11::window::base &_window,
	sge::opengl::x11::state_atom const _wm_state,
	bool const _value
)
{
	XEvent event{};
	event.xany.type = ClientMessage;
	event.xclient.message_type = _wm_state.get().get();
	event.xclient.format = 32;
	event.xclient.data.l[0] = _value ? 1 : 0;
	event.xclient.data.l[1] = fcppt::cast::to_signed(_wm_state.get().get());
	event.xclient.data.l[2] = 0l;
	event.xclient.data.l[3] = 0l;
	event.xclient.data.l[4] = 0l;

	awl::backends::x11::window::event::send(
		*awl::backends::x11::window::root(
			_window.display(),
			_window.screen()
		),
		awl::backends::x11::window::event::mask{
			SubstructureNotifyMask
			|
			SubstructureRedirectMask
		},
		awl::backends::x11::window::event::object{
			event
		}
	);
}

}

void
sge::opengl::x11::fullscreen(
	awl::backends::x11::window::base &_window,
	sge::opengl::x11::state_atom const _wm_state,
	sge::opengl::x11::fullscreen_atom const _wm_fullscreen,
	bool const _value
)
{
	set_property(
		_window,
		_wm_state,
		_wm_fullscreen,
		_value
	);

	send_event(
		_window,
		_wm_state,
		_value
	);
}