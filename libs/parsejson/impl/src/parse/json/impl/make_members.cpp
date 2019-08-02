//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/charconv/utf8_string.hpp>
#include <sge/parse/json/member.hpp>
#include <sge/parse/json/member_map.hpp>
#include <sge/parse/json/value.hpp>
#include <sge/parse/json/impl/make_members.hpp>
#include <sge/parse/json/impl/member_vector.hpp>
#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/not.hpp>
#include <fcppt/recursive_impl.hpp>
#include <fcppt/strong_typedef_impl.hpp>
#include <fcppt/algorithm/fold.hpp>
#include <fcppt/container/insert.hpp>
#include <fcppt/container/make_move_range.hpp>
#include <fcppt/either/try_call.hpp>
#include <fcppt/parse/error.hpp>
#include <fcppt/parse/result.hpp>
#include <fcppt/config/external_begin.hpp>
#include <string>
#include <tuple>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace
{

FCPPT_MAKE_STRONG_TYPEDEF(
	sge::charconv::utf8_string,
	double_insert
);

sge::parse::json::member_map
make_members_impl(
	sge::parse::json::impl::member_vector &&_args
)
{
	return
		fcppt::algorithm::fold(
			fcppt::container::make_move_range(
				std::move(
					_args
				)
			),
			sge::parse::json::member_map{},
			[](
				std::tuple<
					sge::charconv::utf8_string,
					fcppt::recursive<
						sge::parse::json::value
					>
				> &&_element,
				sge::parse::json::member_map &&_state
			)
			{
				if(
					fcppt::not_(
						fcppt::container::insert(
							_state,
							sge::parse::json::member{
								std::get<
									0
								>(
									_element
								),
								std::move(
									std::get<
										1
									>(
										_element
									)
								)
							}
						)
					)
				)
					throw
						double_insert{
							std::move(
								std::get<
									0
								>(
									_element
								)
							)
						};

			return
				std::move(
					_state
				);
			}
		);
}

}

fcppt::parse::result<
	char,
	sge::parse::json::member_map
>
sge::parse::json::impl::make_members(
	sge::parse::json::impl::member_vector &&_args
)
{
	return
		fcppt::either::try_call<
			double_insert
		>(
			[
				&_args
			]{
				return
					make_members_impl(
						std::move(
							_args
						)
					);
			},
			[](
				double_insert const &_error
			)
			{
				return
					fcppt::parse::error<
						char
					>{
						std::string{
							"Duplicate object name: "
						}
						+
						// TODO: Convert this?
						_error.get()
					};
			}
		);
}