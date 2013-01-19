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


#ifndef SGE_RENDERER_STATE_FFP_ALPHA_TEST_SCOPED_HPP_INCLUDED
#define SGE_RENDERER_STATE_FFP_ALPHA_TEST_SCOPED_HPP_INCLUDED

#include <sge/renderer/symbol.hpp>
#include <sge/renderer/context/ffp_fwd.hpp>
#include <sge/renderer/state/ffp/alpha_test/object_fwd.hpp>
#include <sge/renderer/state/ffp/alpha_test/scoped_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace sge
{
namespace renderer
{
namespace state
{
namespace ffp
{
namespace alpha_test
{

class scoped
{
	FCPPT_NONCOPYABLE(
		scoped
	);
public:
	SGE_RENDERER_SYMBOL
	scoped(
		sge::renderer::context::ffp &context,
		sge::renderer::state::ffp::alpha_test::object const &
	);

	SGE_RENDERER_SYMBOL
	~scoped();
private:
	sge::renderer::context::ffp &context_;
};

}
}
}
}
}

#endif
