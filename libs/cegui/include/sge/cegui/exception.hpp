//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_CEGUI_EXCEPTION_HPP_INCLUDED
#define SGE_CEGUI_EXCEPTION_HPP_INCLUDED

#include <sge/cegui/detail/symbol.hpp>
#include <sge/core/exception.hpp>
#include <sge/core/detail/class_symbol.hpp>
#include <fcppt/string.hpp>


namespace sge
{
namespace cegui
{

class SGE_CORE_DETAIL_CLASS_SYMBOL exception
:
	public sge::core::exception
{
public:
	SGE_CEGUI_DETAIL_SYMBOL
	explicit
	exception(
		fcppt::string &&
	);

	SGE_CEGUI_DETAIL_SYMBOL
	exception(
		exception &&
	)
	noexcept;

	SGE_CEGUI_DETAIL_SYMBOL
	exception(
		exception const &
	);

	SGE_CEGUI_DETAIL_SYMBOL
	exception &
	operator=(
		exception &&
	)
	noexcept;

	SGE_CEGUI_DETAIL_SYMBOL
	exception &
	operator=(
		exception const &
	);

	SGE_CEGUI_DETAIL_SYMBOL
	~exception() noexcept
	override;
};

}
}

#endif
