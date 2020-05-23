//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/renderer/context/core.hpp>
#include <sge/renderer/context/core_ref.hpp>
#include <sge/renderer/state/core/blend/const_optional_object_ref.hpp>
#include <sge/renderer/state/core/blend/object_fwd.hpp>
#include <sge/renderer/state/core/blend/scoped.hpp>
#include <fcppt/reference_impl.hpp>


sge::renderer::state::core::blend::scoped::scoped(
	sge::renderer::context::core_ref const _context,
	fcppt::reference<
		sge::renderer::state::core::blend::object const
	> const _object
)
:
	context_(
		_context
	)
{
	context_.get().blend_state(
		sge::renderer::state::core::blend::const_optional_object_ref(
			_object
		)
	);
}

sge::renderer::state::core::blend::scoped::~scoped()
{
	context_.get().blend_state(
		sge::renderer::state::core::blend::const_optional_object_ref()
	);
}
