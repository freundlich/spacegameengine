//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_PLUGIN_MANAGER_HPP_INCLUDED
#define SGE_PLUGIN_MANAGER_HPP_INCLUDED

#include <sge/plugin/capabilities.hpp>
#include <sge/plugin/category_array.hpp>
#include <sge/plugin/collection_fwd.hpp>
#include <sge/plugin/manager_fwd.hpp>
#include <sge/plugin/optional_cache_ref_fwd.hpp>
#include <sge/plugin/detail/context_base_vector.hpp>
#include <sge/plugin/detail/symbol.hpp>
#include <sge/plugin/detail/instantiate/symbol.hpp>
#include <fcppt/noncopyable.hpp>
#include <fcppt/enum/array_decl.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <filesystem>
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
	SGE_PLUGIN_DETAIL_SYMBOL
	manager(
		fcppt::log::context &,
		std::filesystem::path const &,
		sge::plugin::optional_cache_ref const &
	);

	SGE_PLUGIN_DETAIL_SYMBOL
	~manager();

	template<
		typename Type
	>
	SGE_PLUGIN_DETAIL_INSTANTIATE_SYMBOL
	sge::plugin::collection<
		Type
	>
	collection();
private:
	fcppt::log::object log_;

	typedef
	fcppt::enum_::array<
		sge::plugin::capabilities,
		sge::plugin::category_array
	>
	plugin_map;

	sge::plugin::detail::context_base_vector const plugins_;

	plugin_map const categories_;
};

}
}

#endif
