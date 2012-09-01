/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2012 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_RENDERER_DEVICE_FFP_HPP_INCLUDED
#define SGE_RENDERER_DEVICE_FFP_HPP_INCLUDED

#include <sge/class_symbol.hpp>
#include <sge/renderer/symbol.hpp>
#include <sge/renderer/context/ffp_fwd.hpp>
#include <sge/renderer/context/ffp_unique_ptr.hpp>
#include <sge/renderer/device/core.hpp>
#include <sge/renderer/device/ffp_fwd.hpp>
#include <sge/renderer/state/ffp/alpha_test/object_unique_ptr.hpp>
#include <sge/renderer/state/ffp/alpha_test/parameters_fwd.hpp>
#include <sge/renderer/state/ffp/fog/object_unique_ptr.hpp>
#include <sge/renderer/state/ffp/fog/parameters_fwd.hpp>
#include <sge/renderer/state/ffp/lighting/object_unique_ptr.hpp>
#include <sge/renderer/state/ffp/lighting/parameters_fwd.hpp>
#include <sge/renderer/state/ffp/texture_stage/object_unique_ptr.hpp>
#include <sge/renderer/state/ffp/texture_stage/parameters_fwd.hpp>
#include <sge/renderer/target/base_fwd.hpp>
#include <fcppt/noncopyable.hpp>


namespace sge
{
namespace renderer
{
namespace device
{

/**
\brief Provides ffp functionality

In addition to the core device, ffp states such as fog, lighting and
alpha_testing are provided.
*/
class SGE_CLASS_SYMBOL ffp
:
	public sge::renderer::device::core
{
	FCPPT_NONCOPYABLE(
		ffp
	);
protected:
	SGE_RENDERER_SYMBOL
	ffp();
public:
	virtual
	sge::renderer::context::ffp_unique_ptr
	begin_rendering_ffp(
		sge::renderer::target::base &
	) = 0;

	virtual
	void
	end_rendering_ffp(
		sge::renderer::context::ffp &
	) = 0;

	virtual
	sge::renderer::state::ffp::alpha_test::object_unique_ptr
	create_alpha_test_state(
		sge::renderer::state::ffp::alpha_test::parameters const &
	) = 0;

	virtual
	sge::renderer::state::ffp::fog::object_unique_ptr
	create_fog_state(
		sge::renderer::state::ffp::fog::parameters const &
	) = 0;

	virtual
	sge::renderer::state::ffp::lighting::object_unique_ptr
	create_lighting_state(
		sge::renderer::state::ffp::lighting::parameters const &
	) = 0;

	virtual
	sge::renderer::state::ffp::texture_stage::object_unique_ptr
	create_texture_stage_state(
		sge::renderer::state::ffp::texture_stage::parameters const &
	) = 0;

	SGE_RENDERER_SYMBOL
	virtual
	~ffp() = 0;
};

}
}
}

#endif
