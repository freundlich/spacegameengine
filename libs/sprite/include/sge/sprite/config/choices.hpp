//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_SPRITE_CONFIG_CHOICES_HPP_INCLUDED
#define SGE_SPRITE_CONFIG_CHOICES_HPP_INCLUDED

#include <sge/sprite/config/choices_fwd.hpp>
#include <sge/sprite/config/is_pos_choice.hpp>
#include <sge/sprite/config/is_size_choice.hpp>
#include <sge/sprite/config/is_type_choices.hpp>
#include <fcppt/config/external_begin.hpp>
#include <metal.hpp>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace sprite
{
namespace config
{

template<
	typename TypeChoices,
	typename PosChoice,
	typename SizeChoice,
	typename OptionalElements
>
struct choices
{
	using
	type_choices
	=
	TypeChoices;

	using
	pos_choice
	=
	PosChoice;

	using
	size_choice
	=
	SizeChoice;

	using
	optional_elements
	=
	OptionalElements;

	static_assert(
		sge::sprite::config::is_type_choices<
			TypeChoices
		>::value,
		"TypeChoices must be a sprite type_choices struct"
	);

	static_assert(
		sge::sprite::config::is_pos_choice<
			PosChoice
		>::value,
		"PosChoice must be one of sprite's pos choices"
	);

	static_assert(
		sge::sprite::config::is_size_choice<
			SizeChoice
		>::value,
		"SizeChoice must be one of sprite's size choices"
	);

	static_assert(
		metal::is_list<
			OptionalElements
		>::value,
		"OptionalElements must be an mpl sequence"
	);
};

}
}
}

#endif
