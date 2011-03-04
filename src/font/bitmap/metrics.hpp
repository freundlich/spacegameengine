/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2011 Carl Philipp Reh (sefi@s-e-f-i.de)

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


#ifndef SGE_FONT_BITMAP_METRICS_HPP_INCLUDED
#define SGE_FONT_BITMAP_METRICS_HPP_INCLUDED

#include "char_map.hpp"
#include <sge/font/char_metric_ptr.hpp>
#include <sge/font/metrics.hpp>
#include <sge/font/char_type.hpp>
#include <sge/image2d/file_ptr.hpp>
#include <sge/image2d/multi_loader_fwd.hpp>
#include <fcppt/filesystem/path.hpp>
#include <fcppt/noncopyable.hpp>
#include <vector>

namespace sge
{
namespace font
{
namespace bitmap
{

class metrics
:
	public font::metrics
{
	FCPPT_NONCOPYABLE(
		metrics
	);
public:
	metrics(
		fcppt::filesystem::path const &,
		sge::image2d::multi_loader &
	);

	~metrics();

	font::char_metric_ptr const
	load_char(
		font::char_type
	);

	font::unit
	line_height() const;
private:
	typedef std::vector<
		sge::image2d::file_ptr
	> image_vector;

	image_vector images_;

	font::unit line_height_;

	font::bitmap::char_map char_map_;
};

}
}
}

#endif