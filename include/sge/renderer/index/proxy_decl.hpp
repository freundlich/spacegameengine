/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2012 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_RENDERER_INDEX_PROXY_DECL_HPP_INCLUDED
#define SGE_RENDERER_INDEX_PROXY_DECL_HPP_INCLUDED

#include <sge/renderer/index/format.hpp>
#include <sge/renderer/index/nonconst_tag.hpp>
#include <sge/renderer/index/proxy_fwd.hpp>
#include <fcppt/nonassignable.hpp>
#include <fcppt/static_assert_statement.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_same.hpp>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace renderer
{
namespace index
{

template<
	typename Format
>
class proxy
{
	FCPPT_NONASSIGNABLE(
		proxy
	);
public:
	FCPPT_STATIC_ASSERT_STATEMENT((
		boost::is_same<
			typename Format::constness,
			index::nonconst_tag
		>::value
	));

	typedef typename Format::index_type value_type;

	typedef typename Format::pointer pointer;

	explicit proxy(
		pointer
	);

	void
	set(
		value_type
	);

	value_type
	get() const;
private:
	pointer const data_;
};

}
}
}

#endif
