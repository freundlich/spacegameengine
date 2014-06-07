/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2014 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#ifndef SGE_RUCKSACK_AXIS_POLICY_HPP_INCLUDED
#define SGE_RUCKSACK_AXIS_POLICY_HPP_INCLUDED

#include <sge/rucksack/axis_policy_fwd.hpp>
#include <sge/rucksack/is_expanding.hpp>
#include <sge/rucksack/minimum_size.hpp>
#include <sge/rucksack/preferred_size.hpp>
#include <sge/rucksack/symbol.hpp>


namespace sge
{
namespace rucksack
{

class axis_policy
{
public:
	SGE_RUCKSACK_SYMBOL
	axis_policy(
		sge::rucksack::minimum_size const &,
		sge::rucksack::preferred_size const &,
		sge::rucksack::is_expanding const &
	);

	SGE_RUCKSACK_SYMBOL
	sge::rucksack::minimum_size const
	minimum_size() const;

	SGE_RUCKSACK_SYMBOL
	sge::rucksack::preferred_size const
	preferred_size() const;

	SGE_RUCKSACK_SYMBOL
	sge::rucksack::is_expanding const
	is_expanding() const;
private:
	sge::rucksack::minimum_size minimum_size_;

	sge::rucksack::preferred_size preferred_size_;

	sge::rucksack::is_expanding is_expanding_;
};

}
}

#endif
