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


#include <sge/rucksack/axis_policy2.hpp>
#include <sge/rucksack/dim.hpp>
#include <sge/rucksack/vector.hpp>
#include <sge/rucksack/widget/base.hpp>
#include <sge/rucksack/widget/minimum_size.hpp>
#include <sge/rucksack/widget/optional_parent.hpp>


sge::rucksack::widget::minimum_size::minimum_size(
	sge::rucksack::widget::base &_child
)
:
	sge::rucksack::widget::base(
		sge::rucksack::widget::optional_parent()
	),
	child_(
		_child
	)
{
}

void
sge::rucksack::widget::minimum_size::size(
	sge::rucksack::dim const &
)
{
}

void
sge::rucksack::widget::minimum_size::position(
	sge::rucksack::vector const &_position
)
{
	child_.position(
		_position
	);
}

sge::rucksack::dim const
sge::rucksack::widget::minimum_size::size() const
{
	return
		child_.size();
}

sge::rucksack::vector const
sge::rucksack::widget::minimum_size::position() const
{
	return
		child_.position();
}

sge::rucksack::axis_policy2 const
sge::rucksack::widget::minimum_size::axis_policy() const
{
	return
		child_.axis_policy();
}

void
sge::rucksack::widget::minimum_size::relayout()
{
	sge::rucksack::axis_policy2 const policy(
		child_.axis_policy()
	);

	child_.size(
		sge::rucksack::dim(
			policy.x().minimum_size().get(),
			policy.y().minimum_size().get()
		)
	);

	child_.relayout();
}

sge::rucksack::widget::minimum_size::~minimum_size()
{
}
