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


#ifndef SGE_TIMER_PARAMETERS_IMPL_HPP_INCLUDED
#define SGE_TIMER_PARAMETERS_IMPL_HPP_INCLUDED

#include <sge/timer/enable_ctor_stateful.hpp>
#include <sge/timer/enable_ctor_stateless.hpp>
#include <sge/timer/parameters_decl.hpp>
#include <sge/timer/detail/parameters_base_impl.hpp>


template<typename Clock>
template<typename Duration>
sge::timer::parameters<Clock>::parameters(
	clock_type const &_clock,
	Duration const &_interval,
	typename timer::enable_ctor_stateful<
		Clock,
		Duration
	>::type const *)
:
	state_base(
		_clock),
	parameters_base(
		_interval)
{
}

template<typename Clock>
template<typename Duration>
sge::timer::parameters<Clock>::parameters(
	Duration const &_interval,
	typename timer::enable_ctor_stateless<
		Clock,
		Duration
	>::type const *)
:
	state_base(),
	parameters_base(
		_interval)
{
}

template<typename Clock>
sge::timer::parameters<Clock> &
sge::timer::parameters<Clock>::active(
	bool const _active)
{
	this->active_ =
		_active;
	return
		*this;
}

template<typename Clock>
sge::timer::parameters<Clock> &
sge::timer::parameters<Clock>::expired(
	bool const _expired)
{
	this->expired_ =
		_expired;
	return
		*this;
}

template<typename Clock>
typename
sge::timer::parameters<Clock>::duration const
sge::timer::parameters<Clock>::interval() const
{
	return this->interval_;
}

template<typename Clock>
typename
sge::timer::parameters<Clock>::state_base const &
sge::timer::parameters<Clock>::clock() const
{
	return *this;
}

template<typename Clock>
bool
sge::timer::parameters<Clock>::active() const
{
	return
		this->active_;
}

template<typename Clock>
bool
sge::timer::parameters<Clock>::expired() const
{
	return
		this->expired_;
}

#endif
