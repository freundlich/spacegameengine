/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_D3D9_STATE_PARAMETERS_HPP_INCLUDED
#define SGE_D3D9_STATE_PARAMETERS_HPP_INCLUDED

#include "parameters_fwd.hpp"
#include "clear_fwd.hpp"
#include "deferred/object_fwd.hpp"
#include "../d3dinclude.hpp"
#include <fcppt/nonassignable.hpp>

namespace sge
{
namespace d3d9
{
namespace state
{

class parameters
{
	FCPPT_NONASSIGNABLE(
		parameters
	);
public:
	parameters(
		IDirect3DDevice9 *,
		state::deferred::object &,
		state::clear &
	);

	IDirect3DDevice9 *
	device() const;

	state::deferred::object &
	deferred() const;

	state::clear &
	clear() const;
private:
	IDirect3DDevice9 *const device_;

	state::deferred::object &deferred_;

	state::clear &clear_;
};

}
}
}

#endif
