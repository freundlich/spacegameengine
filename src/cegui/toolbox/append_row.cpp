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


#include <sge/cegui/toolbox/append_row.hpp>
#include <sge/cegui/toolbox/row.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/config/external_begin.hpp>
#include <CEGUI/Base.h>
#include <CEGUI/widgets/ListboxTextItem.h>
#include <CEGUI/widgets/MultiColumnList.h>
#include <fcppt/config/external_end.hpp>


void
sge::cegui::toolbox::append_row(
	CEGUI::MultiColumnList &_list,
	sge::cegui::toolbox::row const &_mapper
)
{
	FCPPT_ASSERT_PRE(
		static_cast<
			sge::cegui::toolbox::row::size_type
		>(
			_list.getColumnCount()
		)
		==
		_mapper.size()
	);

	FCPPT_ASSERT_PRE(
		!_mapper.empty()
	);

	CEGUI::uint const index(
		_list.addRow(
			new CEGUI::ListboxTextItem(
				_mapper[
					0
				],
				0,
				nullptr
			),
			0
		)
	);

	for(
		sge::cegui::toolbox::row::size_type cur(
			1u
		);
		cur < _mapper.size();
		++cur
	)
		_list.setItem(
			new CEGUI::ListboxTextItem(
				_mapper[
					cur
				],
				0,
				nullptr
			),
			static_cast<
				CEGUI::uint
			>(
				cur
			),
			index
		);
}
