//          Copyright Carl Philipp Reh 2009 - 2015.
//          Copyright Philipp Middendorf 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_SRC_SCENIC_NUMBER_MULTIPLEXER_SET_BITS_HPP_INCLUDED
#define SGE_SRC_SCENIC_NUMBER_MULTIPLEXER_SET_BITS_HPP_INCLUDED

namespace sge
{
namespace scenic
{
namespace number_multiplexer
{
template<typename T>
T
set_bits(
	T const begin,
	T const size,
	T const value,
	T const input)
{
	T const part =
		((1u << begin) - 1u) ^ ((1u << (begin + size)) - 1u);

	return
		(input & ~part) | (value << begin);
}
}
}
}

#endif