//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_MODEL_OBJ_IDENTIFIER_HPP_INCLUDED
#define SGE_MODEL_OBJ_IDENTIFIER_HPP_INCLUDED

#include <sge/charconv/utf8_string.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/strong_typedef.hpp>


namespace sge
{
namespace model
{
namespace obj
{

FCPPT_MAKE_STRONG_TYPEDEF(
	sge::charconv::utf8_string,
	identifier
);

}
}
}

#endif
