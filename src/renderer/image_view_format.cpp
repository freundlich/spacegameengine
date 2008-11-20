/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2007  Carl Philipp Reh (sefi@s-e-f-i.de)

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


#include <sge/renderer/image_view_format.hpp>
#include <sge/renderer/const_image_view_elements.hpp>
#include <boost/gil/extension/dynamic_image/apply_operation.hpp>
#include <sge/mpl/index_of.hpp>

namespace
{

struct format_fun {
	typedef sge::renderer::color_format::type result_type;

	template<
		typename T
	> 
	result_type
	operator()(
		T const &) const;
};

}

sge::renderer::color_format::type
sge::renderer::image_view_format(
	const_image_view const &view)
{
	return boost::gil::apply_operation(
		view,
		format_fun());
}

namespace
{

template<
	typename T
>
format_fun::result_type
format_fun::operator()(
	T const &) const
{
	typedef typename sge::mpl::index_of<
		sge::renderer::const_image_view_elements,
		T
	>::type index;

	return static_cast<sge::renderer::color_format::type>(
		index::value);
}

}
