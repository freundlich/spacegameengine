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


#ifndef SGE_PLUGIN_MANAGER_HPP_INCLUDED
#define SGE_PLUGIN_MANAGER_HPP_INCLUDED

#include <sge/plugin/capabilities.hpp>
#include <sge/plugin/category_array.hpp>
#include <sge/plugin/context_base.hpp>
#include <sge/plugin/context_fwd.hpp>
#include <sge/plugin/iterator_fwd.hpp>
#include <sge/plugin/manager_fwd.hpp>
#include <sge/plugin/symbol.hpp>
#include <sge/plugin/detail/instantiate/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/path.hpp>
#include <cstddef>
#include <map>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace sge
{
namespace plugin
{

class manager
{
	FCPPT_NONCOPYABLE(
		manager
	);
public:
	typedef std::size_t size_type;

	SGE_PLUGIN_SYMBOL
	explicit
	manager(
		boost::filesystem::path const &
	);

	SGE_PLUGIN_SYMBOL
	~manager();

	template<
		typename Type
	>
	SGE_PLUGIN_DETAIL_INSTANTIATE_SYMBOL
	sge::plugin::iterator<
		Type
	>
	begin();

	template<
		typename Type
	>
	SGE_PLUGIN_DETAIL_INSTANTIATE_SYMBOL
	sge::plugin::iterator<
		Type
	>
	end();

	template<
		typename Type
	>
	SGE_PLUGIN_DETAIL_INSTANTIATE_SYMBOL
	sge::plugin::context<
		Type
	>
	plugin(
		sge::plugin::manager::size_type index = 0
	);

	template<
		typename Type
	>
	SGE_PLUGIN_DETAIL_INSTANTIATE_SYMBOL
	sge::plugin::manager::size_type
	size() const;
private:
	typedef std::vector<
		sge::plugin::context_base
	> plugin_array;

	typedef std::map<
		sge::plugin::capabilities::type,
		sge::plugin::category_array
	> plugin_map;

	plugin_array plugins_;

	plugin_map categories_;
};

}
}

#endif
