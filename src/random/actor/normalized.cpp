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


#include <sge/random/actor/normalized.hpp>
#include <sge/random/actor/element.hpp>
#include <sge/random/inclusive_range.hpp>
#include <sge/exception.hpp>
#include <sge/text.hpp>
#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <numeric>
#include <functional>

sge::random::actor::normalized::normalized(
	container const &elements)
:
	elements(elements),
	rng(
		random::make_inclusive_range(
			static_cast<float_type>(0),
			std::accumulate(
				elements.begin(),
				elements.end(),
				static_cast<float_type>(0),
				boost::bind(
					std::plus<
						float_type
					>(),
					_1,
					boost::bind(
						&element::prob,
						_2
					)
				)
			)
		)
	)
{}

sge::random::actor::normalized::~normalized()
{}

void
sge::random::actor::normalized::operator()()
{
	float_type val(
		rng()
	);

	BOOST_FOREACH(
		container::const_reference ref,
		elements
	)
	{
		if(val < ref.prob())
		{
			ref.callback()();
			return;
		}
		val -= ref.prob();
	}

	throw exception(
		SGE_TEXT("random::actor::normalized: nothing matched!")
	);
}
