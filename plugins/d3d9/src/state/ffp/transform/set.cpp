/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2016 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#include <sge/d3d9/state/ffp/transform/object.hpp>
#include <sge/d3d9/state/ffp/transform/set.hpp>
#include <sge/renderer/state/ffp/transform/const_optional_object_ref.hpp>
#include <sge/renderer/state/ffp/transform/mode.hpp>
#include <sge/renderer/state/ffp/transform/object.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/cast/static_downcast.hpp>
#include <fcppt/optional/maybe.hpp>


void
sge::d3d9::state::ffp::transform::set(
	sge::renderer::state::ffp::transform::mode const _mode,
	sge::renderer::state::ffp::transform::const_optional_object_ref const &_opt_state,
	sge::d3d9::state::ffp::transform::object const &_default
)
{
	fcppt::optional::maybe(
		_opt_state,
		[
			&_default
		]()
		{
			return
				fcppt::make_cref(
					_default
				);
		},
		[](
			fcppt::reference<
				sge::renderer::state::ffp::transform::object const
			> const _state
		)
		{
			return
				fcppt::make_cref(
					fcppt::cast::static_downcast<
						sge::d3d9::state::ffp::transform::object const &
					>(
						_state.get()
					)
				);
		}
	).get().set(
		_mode
	);
}