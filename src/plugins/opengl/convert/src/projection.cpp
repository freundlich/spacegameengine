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


#include "../projection.hpp"
#include <sge/renderer/scalar.hpp>
#include <fcppt/math/matrix/basic_impl.hpp>

sge::renderer::matrix4 const
sge::opengl::convert::projection(
	renderer::matrix4 const &_matrix
)
{
	sge::renderer::matrix4 ret(
		_matrix
	);

	for(
		sge::renderer::matrix4::size_type row(
			0
		);
		row < ret.rows();
		++row
	)
		ret[row][2] *=
			static_cast<
				sge::renderer::scalar
			>(
				-1
			);

	return ret;
}
