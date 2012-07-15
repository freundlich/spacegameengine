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


#include <sge/evdev/device/create_fd.hpp>
#include <sge/evdev/device/fd.hpp>
#include <sge/evdev/device/fd_unique_ptr.hpp>
#include <sge/input/exception.hpp>
#include <sge/log/global.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/move.hpp>
#include <fcppt/text.hpp>
#include <fcppt/error/strerrno.hpp>
#include <fcppt/filesystem/path_to_string.hpp>
#include <fcppt/log/error.hpp>
#include <fcppt/log/output.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


sge::evdev::device::fd_unique_ptr
sge::evdev::device::create_fd(
	boost::filesystem::path const &_path
)
{
	sge::evdev::device::fd_unique_ptr ret(
		fcppt::make_unique_ptr<
			sge::evdev::device::fd
		>(
			_path
		)
	);

	if(
		ret->valid()
	)
		return
			fcppt::move(
				ret
			);

	FCPPT_LOG_ERROR(
		sge::log::global(),
		fcppt::log::_
			<<
			FCPPT_TEXT("Opening \"")
			<<
			fcppt::filesystem::path_to_string(
				_path
			)
			<<
			FCPPT_TEXT("\" failed: ")
			<<
			fcppt::error::strerrno()
	);

	return
		sge::evdev::device::fd_unique_ptr();
}
