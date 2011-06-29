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


#ifndef SGE_IMAGE_VIEW_CONST_OBJECT_HPP_INCLUDED
#define SGE_IMAGE_VIEW_CONST_OBJECT_HPP_INCLUDED

#include <sge/image/view/const_object_fwd.hpp>
#include <sge/image/view/object_fwd.hpp>
#include <sge/image/instantiate_symbol.hpp>
#include <fcppt/variant/object_decl.hpp>

namespace sge
{
namespace image
{
namespace view
{

template<
	typename ElementsWrapper,
	typename NonConstElementsWrapper
>
class const_object
{
public:
	typedef view::object<
		NonConstElementsWrapper
	> nonconst_object;

	typedef fcppt::variant::object<
		typename ElementsWrapper::type
	> variant;

	SGE_IMAGE_INSTANTIATE_SYMBOL
	explicit const_object(
		variant const &
	);

	SGE_IMAGE_INSTANTIATE_SYMBOL
	explicit const_object(
		nonconst_object const  &
	);

	SGE_IMAGE_INSTANTIATE_SYMBOL
	const_object(
		const_object const &
	);

	SGE_IMAGE_INSTANTIATE_SYMBOL
	const_object &
	operator=(
		const_object const &
	);

	SGE_IMAGE_INSTANTIATE_SYMBOL
	~const_object();

	SGE_IMAGE_INSTANTIATE_SYMBOL
	variant const &
	get() const;
private:
	variant variant_;
};

}
}
}

#endif