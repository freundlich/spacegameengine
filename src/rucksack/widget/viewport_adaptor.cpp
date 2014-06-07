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


#include <sge/renderer/pixel_rect.hpp>
#include <sge/renderer/device/core.hpp>
#include <sge/renderer/target/onscreen.hpp>
#include <sge/renderer/target/viewport.hpp>
#include <sge/rucksack/axis_policy.hpp>
#include <sge/rucksack/axis_policy2.hpp>
#include <sge/rucksack/dim.hpp>
#include <sge/rucksack/is_expanding.hpp>
#include <sge/rucksack/minimum_size.hpp>
#include <sge/rucksack/optional_scalar.hpp>
#include <sge/rucksack/preferred_size.hpp>
#include <sge/rucksack/scalar.hpp>
#include <sge/rucksack/vector.hpp>
#include <sge/rucksack/widget/optional_parent.hpp>
#include <sge/rucksack/widget/viewport_adaptor.hpp>
#include <sge/viewport/manager.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/math/dim/structure_cast.hpp>
#include <fcppt/math/vector/structure_cast.hpp>
#include <fcppt/preprocessor/disable_vc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <functional>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_VC_WARNING(4355)

sge::rucksack::widget::viewport_adaptor::viewport_adaptor(
	sge::viewport::manager &_viewport,
	sge::renderer::device::core &_renderer)
:
	sge::rucksack::widget::base(
		sge::rucksack::widget::optional_parent()
	),
	target_(
		_renderer.onscreen_target()
	),
	child_(
		nullptr
	),
	viewport_connection_(
		_viewport.manage_callback(
			std::bind(
				&sge::rucksack::widget::viewport_adaptor::manage_callback,
				this
			)
		)
	)
{
}

FCPPT_PP_POP_WARNING

void
sge::rucksack::widget::viewport_adaptor::size(
	sge::rucksack::dim const &_size)
{
	target_.viewport(
		sge::renderer::target::viewport(
			sge::renderer::pixel_rect(
				target_.viewport().get().pos(),
				fcppt::math::dim::structure_cast<
					sge::renderer::pixel_rect::dim
				>(
					_size
				)
			)
		)
	);
}

void
sge::rucksack::widget::viewport_adaptor::position(
	sge::rucksack::vector const &_pos)
{
	target_.viewport(
		sge::renderer::target::viewport(
			sge::renderer::pixel_rect(
				fcppt::math::vector::structure_cast<
					sge::renderer::pixel_rect::vector
				>(
					_pos
				),
				target_.viewport().get().size()
			)
		)
	);
}

sge::rucksack::dim const
sge::rucksack::widget::viewport_adaptor::size() const
{
	return
		fcppt::math::dim::structure_cast<
			sge::rucksack::dim
		>(
			target_.viewport().get().size()
		);
}

sge::rucksack::vector const
sge::rucksack::widget::viewport_adaptor::position() const
{
	return
		fcppt::math::vector::structure_cast<
			sge::rucksack::vector
		>(
			target_.viewport().get().pos()
		);
}

sge::rucksack::axis_policy2 const
sge::rucksack::widget::viewport_adaptor::axis_policy() const
{
	// A dummy for now, until there's a use case
	return
		sge::rucksack::axis_policy2(
			sge::rucksack::axis_policy(
				sge::rucksack::minimum_size(
					sge::rucksack::scalar()),
				sge::rucksack::preferred_size(
					sge::rucksack::optional_scalar()),
				sge::rucksack::is_expanding(
					false)),
			sge::rucksack::axis_policy(
				sge::rucksack::minimum_size(
					sge::rucksack::scalar()),
				sge::rucksack::preferred_size(
					sge::rucksack::optional_scalar()),
				sge::rucksack::is_expanding(
					false)),
			sge::rucksack::aspect(
				1,
				1));
}

void
sge::rucksack::widget::viewport_adaptor::relayout()
{
	if(child_)
		child_->relayout();
}

void
sge::rucksack::widget::viewport_adaptor::child(
	sge::rucksack::widget::base &_child)
{
	if(child_)
		child_->parent(
			sge::rucksack::widget::optional_parent());

	child_ = &_child;
	child_->parent(
		sge::rucksack::widget::optional_parent(
			*this));

	this->resize_child();
}


sge::rucksack::widget::viewport_adaptor::~viewport_adaptor()
{
	if(child_)
		child_->parent(
			sge::rucksack::widget::optional_parent());
}

void
sge::rucksack::widget::viewport_adaptor::manage_callback()
{
	if(child_)
		this->resize_child();
}

void
sge::rucksack::widget::viewport_adaptor::resize_child()
{
	FCPPT_ASSERT_PRE(
		child_
	);

	child_->position(
		sge::rucksack::vector::null());
	child_->size(
		this->size());
	child_->relayout();
}

void
sge::rucksack::widget::viewport_adaptor::child_destroyed(
	sge::rucksack::widget::base &_child)
{
	FCPPT_ASSERT_PRE(
		&_child == child_);

	child_ =
		nullptr;
}
