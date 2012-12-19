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


#include <sge/model/md3/load_flags.hpp>
#include <sge/model/md3/object_unique_ptr.hpp>
#include <sge/src/model/md3/loader_impl.hpp>
#include <sge/src/model/md3/object_impl.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/fstream.hpp>
#include <boost/filesystem/path.hpp>
#include <ios>
#include <fcppt/config/external_end.hpp>


sge::model::md3::loader_impl::loader_impl()
{
}

sge::model::md3::loader_impl::~loader_impl()
{
}

sge::model::md3::object_unique_ptr
sge::model::md3::loader_impl::load(
	boost::filesystem::path const &_path,
	sge::model::md3::load_flags::type const _flags
)
{
	boost::filesystem::ifstream file(
		_path,
		std::ios_base::binary
	);

	file.exceptions(
		std::ios_base::failbit
		| std::ios_base::badbit
	);

	return
		sge::model::md3::object_unique_ptr(
			fcppt::make_unique_ptr<
				sge::model::md3::object_impl
			>(
				file,
				_flags
			)
		);
}

sge::model::md3::object_unique_ptr
sge::model::md3::loader_impl::load_stream(
	std::istream &_stream,
	sge::model::md3::load_flags::type const _flags
)
{
	return
		sge::model::md3::object_unique_ptr(
			fcppt::make_unique_ptr<
				sge::model::md3::object_impl
			>(
				_stream,
				_flags
			)
		);
}
