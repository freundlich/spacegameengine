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


#ifndef SGE_D3D9_STATE_CORE_SAMPLER_OBJECT_HPP_INCLUDED
#define SGE_D3D9_STATE_CORE_SAMPLER_OBJECT_HPP_INCLUDED

#include <sge/d3d9/d3dinclude.hpp>
#include <sge/d3d9/state/core/sampler/object_fwd.hpp>
#include <sge/d3d9/state/core/sampler/state_vector.hpp>
#include <sge/renderer/state/core/sampler/object.hpp>
#include <sge/renderer/texture/stage.hpp>
#include <fcppt/noncopyable.hpp>


namespace sge
{
namespace d3d9
{
namespace state
{
namespace core
{
namespace sampler
{

class object
:
	public sge::renderer::state::core::sampler::object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	object(
		IDirect3DDevice9 &,
		sge::d3d9::state::core::sampler::state_vector const &
	);

	~object();

	void
	set(
		sge::renderer::texture::stage
	) const;
private:
	IDirect3DDevice9 &device_;

	sge::d3d9::state::core::sampler::state_vector states_;
};

}
}
}
}
}

#endif