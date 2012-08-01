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


#include <sge/model/obj/index_buffer_range.hpp>

sge::model::obj::index_buffer_range::index_buffer_range(
	sge::renderer::first_index const &_first_index,
	sge::renderer::index_count const &_index_count)
:
	first_index_(
		_first_index),
	index_count_(
		_index_count)
{
}

sge::renderer::first_index const &
sge::model::obj::index_buffer_range::first_index() const
{
	return
		first_index_;
}

sge::renderer::index_count const &
sge::model::obj::index_buffer_range::index_count() const
{
	return
		index_count_;
}
