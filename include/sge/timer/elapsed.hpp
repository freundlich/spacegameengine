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


#ifndef SGE_TIMER_ELAPSED_HPP_INCLUDED
#define SGE_TIMER_ELAPSED_HPP_INCLUDED

#include <sge/timer/basic.hpp>
#include <fcppt/chrono/duration_cast.hpp>
#include <fcppt/chrono/time_point_arithmetic.hpp>


namespace sge
{
namespace timer
{
template<typename Duration,typename Clock>
Duration const
elapsed(
	timer::basic<Clock> const &t)
{
	if(!t.active())
		return
			Duration();

	if(t.expired())
		return
			t.template interval<Duration>();

	return
		fcppt::chrono::duration_cast<Duration>(
			t.now() -
			t.last_time());
}
}
}

#endif
