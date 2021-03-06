//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_SPRITE_DETAIL_SET_POS_HPP_INCLUDED
#define SGE_SPRITE_DETAIL_SET_POS_HPP_INCLUDED

#include <sge/sprite/config/pos_option.hpp>
#include <sge/sprite/roles/pos.hpp>
#include <sge/sprite/roles/pos_or_center.hpp>
#include <sge/sprite/types/pos.hpp>
#include <sge/sprite/types/pos_or_center.hpp>
#include <fcppt/record/set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace sprite
{
namespace detail
{

template<
	typename Choices,
	typename Elements
>
inline
typename
std::enable_if<
	Choices::pos_choice::option::value
	==
	sge::sprite::config::pos_option::pos
	,
	void
>::type
set_pos(
	Elements &_elements,
	sge::sprite::types::pos<
		typename
		Choices::type_choices
	> const _pos

)
{
	fcppt::record::set<
		sge::sprite::roles::pos
	>(
		_elements,
		_pos.get()
	);
}

template<
	typename Choices,
	typename Elements
>
inline
typename
std::enable_if<
	Choices::pos_choice::option::value
	==
	sge::sprite::config::pos_option::pos_or_center
	,
	void
>::type
set_pos(
	Elements &_elements,
	sge::sprite::types::pos<
		typename
		Choices::type_choices
	> const _pos
)
{
	fcppt::record::set<
		sge::sprite::roles::pos_or_center
	>(
		_elements,
		sge::sprite::types::pos_or_center<
			typename
			Choices::type_choices
		>(
			_pos
		)
	);
}

}
}
}

#endif
