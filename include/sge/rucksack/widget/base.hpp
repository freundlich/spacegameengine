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


#ifndef SGE_RUCKSACK_WIDGET_BASE_HPP_INCLUDED
#define SGE_RUCKSACK_WIDGET_BASE_HPP_INCLUDED

#include <sge/class_symbol.hpp>
#include <sge/rucksack/axis_policy2_fwd.hpp>
#include <sge/rucksack/dim_fwd.hpp>
#include <sge/rucksack/rect_fwd.hpp>
#include <sge/rucksack/symbol.hpp>
#include <sge/rucksack/vector_fwd.hpp>
#include <sge/rucksack/widget/optional_parent.hpp>
#include <fcppt/noncopyable.hpp>


namespace sge
{
namespace rucksack
{
namespace widget
{

class SGE_CLASS_SYMBOL base
{
	FCPPT_NONCOPYABLE(
		base
	);
public:
	virtual
	void
	size(
		sge::rucksack::dim const &
	) = 0;

	virtual
	void
	position(
		sge::rucksack::vector const &
	) = 0;

	virtual
	sge::rucksack::dim const
	size() const = 0;

	SGE_RUCKSACK_SYMBOL
	sge::rucksack::rect const
	area() const;

	virtual
	sge::rucksack::vector const
	position() const = 0;

	virtual
	sge::rucksack::axis_policy2 const
	axis_policy() const = 0;

	virtual
	void
	relayout() = 0;

	SGE_RUCKSACK_SYMBOL
	void
	parent(
		sge::rucksack::widget::optional_parent const &
	);

	SGE_RUCKSACK_SYMBOL
	sge::rucksack::widget::optional_parent const &
	parent() const;

	SGE_RUCKSACK_SYMBOL
	virtual
	~base() = 0;
protected:
	SGE_RUCKSACK_SYMBOL
	explicit
	base(
		sge::rucksack::widget::optional_parent const &
	);

	SGE_RUCKSACK_SYMBOL
	virtual
	void
	child_destroyed(
		base &
	);
private:
	sge::rucksack::widget::optional_parent parent_;
};
}
}
}


#endif
