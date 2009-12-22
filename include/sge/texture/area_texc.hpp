/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2009 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef FCPPT_TEXTURE_AREA_TEXC_HPP_INCLUDED
#define FCPPT_TEXTURE_AREA_TEXC_HPP_INCLUDED

#include <sge/texture/part_ptr.hpp>
#include <sge/texture/part.hpp>
#include <sge/renderer/lock_rect_to_coords.hpp>
#include <sge/renderer/texture.hpp>
#include <sge/log/global.hpp>
#include <fcppt/math/dim/arithmetic.hpp>
#include <fcppt/math/dim/basic_impl.hpp>
#include <fcppt/math/box/basic_impl.hpp>
#include <fcppt/math/box/rect.hpp>
#include <fcppt/math/compare.hpp>
#include <fcppt/log/headers.hpp>
#include <ostream>

namespace sge
{
namespace texture
{

template<
	typename T
>
typename fcppt::math::box::rect<T>::type const
area_texc(
	const_part_ptr const part,
	T const repeat
)
{
	if(
		!fcppt::math::compare(
			repeat,
			static_cast<T>(1)
		)
		&& !part->repeatable()
	)
		FCPPT_LOG_WARNING(
			log::global(),
			fcppt::log::_
				<< FCPPT_TEXT("texture not repeatable but repetition is ")
				<< repeat
				<< FCPPT_TEXT('!')
		);

	typedef typename fcppt::math::box::rect<
		T
	>::type ret_type;
	
	ret_type ret_(
		renderer::lock_rect_to_coords<
			T
		>(
			part->area(),
			part->texture()->dim()
		)
	);

	ret_.dimension(
		ret_.dimension() * repeat
	);

	return ret_;
}

}
}

#endif
