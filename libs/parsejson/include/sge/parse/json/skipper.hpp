//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_PARSE_JSON_SKIPPER_HPP_INCLUDED
#define SGE_PARSE_JSON_SKIPPER_HPP_INCLUDED

#include <fcppt/parse/space_skipper.hpp>


namespace sge
{
namespace parse
{
namespace json
{

inline
auto
skipper()
{
	return
		fcppt::parse::space_skipper();
}

}
}
}

#endif