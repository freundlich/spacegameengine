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


#include <sge/camera/projection/orthogonal.hpp>

sge::camera::projection::orthogonal::orthogonal(
	renderer::projection::rect const &_rect,
	renderer::projection::near const &_near,
	renderer::projection::far const &_far)
:
	rect_(
		_rect),
	near_(
		_near.get()),
	far_(
		_far.get())
{

}

sge::renderer::projection::rect const
sge::camera::projection::orthogonal::rect() const
{
	return rect_;
}

sge::renderer::scalar
sge::camera::projection::orthogonal::near() const
{
	return near_;
}

sge::renderer::scalar
sge::camera::projection::orthogonal::far() const
{
	return far_;
}