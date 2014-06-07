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


#include <sge/d3d9/d3dinclude.hpp>
#include <sge/d3d9/state/convert/alpha_func.hpp>
#include <sge/renderer/state/ffp/alpha_test/func.hpp>
#include <fcppt/assert/unreachable.hpp>


D3DCMPFUNC
sge::d3d9::state::convert::alpha_func(
	sge::renderer::state::ffp::alpha_test::func const _type
)
{
	switch(
		_type
	)
	{
	case sge::renderer::state::ffp::alpha_test::func::never:
		return D3DCMP_NEVER;
	case sge::renderer::state::ffp::alpha_test::func::less:
		return D3DCMP_LESS;
	case sge::renderer::state::ffp::alpha_test::func::equal:
		return D3DCMP_EQUAL;
	case sge::renderer::state::ffp::alpha_test::func::less_equal:
		return D3DCMP_LESSEQUAL;
	case sge::renderer::state::ffp::alpha_test::func::greater:
		return D3DCMP_GREATER;
	case sge::renderer::state::ffp::alpha_test::func::not_equal:
		return D3DCMP_NOTEQUAL;
	case sge::renderer::state::ffp::alpha_test::func::greater_equal:
		return D3DCMP_GREATEREQUAL;
	case sge::renderer::state::ffp::alpha_test::func::always:
		return D3DCMP_ALWAYS;
	}

	FCPPT_ASSERT_UNREACHABLE;
}
