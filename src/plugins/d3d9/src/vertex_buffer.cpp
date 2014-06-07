/*
spacegameengine is a portable easy to use game engine written in C++.
Copyright (C) 2006-2014 Carl Philipp Reh (carlphilippreh <at> gmail.com)

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


#include <sge/d3d9/d3dinclude.hpp>
#include <sge/d3d9/vertex_buffer.hpp>
#include <sge/d3d9/convert/lock_flags.hpp>
#include <sge/d3d9/convert/resource_flags.hpp>
#include <sge/d3d9/convert/resource_flags_to_pool.hpp>
#include <sge/image/color/format.hpp>
#include <sge/renderer/exception.hpp>
#include <sge/renderer/lock_mode.hpp>
#include <sge/renderer/resource_flags_field.hpp>
#include <sge/renderer/lock_flags/from_mode.hpp>
#include <sge/renderer/lock_flags/method.hpp>
#include <sge/renderer/vertex/buffer.hpp>
#include <sge/renderer/vertex/buffer_parameters.hpp>
#include <sge/renderer/vf/dynamic/color_format_vector.hpp>
#include <sge/renderer/vf/dynamic/const_view.hpp>
#include <sge/renderer/vf/dynamic/part.hpp>
#include <sge/renderer/vf/dynamic/part_index.hpp>
#include <sge/renderer/vf/dynamic/stride.hpp>
#include <sge/renderer/vf/dynamic/view.hpp>
#include <fcppt/text.hpp>


sge::d3d9::vertex_buffer::vertex_buffer(
	IDirect3DDevice9 &_device,
	sge::renderer::vf::dynamic::part const &_format_part,
	sge::renderer::vertex::buffer_parameters const &_parameters
)
:
	sge::renderer::vertex::buffer(),
	sge::d3d9::resource(
		sge::d3d9::convert::resource_flags_to_pool(
			_parameters.flags()
		)
	),
	device_(
		_device
	),
	format_part_(
		_format_part
	),
	format_part_index_(
		_parameters.part()
	),
	size_(
		_parameters.count()
	),
	resource_flags_(
		_parameters.flags()
	),
	converter_(
		format_part_,
		sge::renderer::vf::dynamic::color_format_vector{
			sge::image::color::format::bgra8
		}
	),
	buffer_(),
	lock_dest_(
		nullptr
	)
{
	this->init();
}

sge::d3d9::vertex_buffer::~vertex_buffer()
{
}

sge::d3d9::vertex_buffer::view_type const
sge::d3d9::vertex_buffer::lock(
	sge::renderer::lock_mode const _lock_mode,
	first_type const _first,
	count_type const _count
)
{
	return
		this->do_lock<
			view_type
		>(
			_first,
			_count,
			sge::renderer::lock_flags::from_mode(
				_lock_mode
			)
		);
}

sge::d3d9::vertex_buffer::const_view_type const
sge::d3d9::vertex_buffer::lock(
	first_type const _first,
	count_type const _count
) const
{
	return
		this->do_lock<
			const_view_type
		>(
			_first,
			_count,
			sge::renderer::lock_flags::method::read
		);
}

void
sge::d3d9::vertex_buffer::unlock() const
{
	if(
		lock_dest_ == nullptr
	)
		throw sge::renderer::exception(
			FCPPT_TEXT("d3d9::vertex_buffer::unlock() you have to lock first!")
		);

	converter_.unlock();

	if(
		buffer_->Unlock()
		!= D3D_OK
	)
		throw sge::renderer::exception(
			FCPPT_TEXT("Cannot unlock d3d vertex buffer!")
		);

	lock_dest_ = nullptr;
}

sge::d3d9::vertex_buffer::count_type const
sge::d3d9::vertex_buffer::size() const
{
	return size_;
}

sge::renderer::resource_flags_field const
sge::d3d9::vertex_buffer::resource_flags() const
{
	return resource_flags_;
}

sge::renderer::vf::dynamic::part const
sge::d3d9::vertex_buffer::format_part() const
{
	return format_part_;
}

sge::renderer::vf::dynamic::part_index const
sge::d3d9::vertex_buffer::format_part_index() const
{
	return format_part_index_;
}

sge::renderer::vf::dynamic::stride const
sge::d3d9::vertex_buffer::stride() const
{
	return format_part_.stride();
}

IDirect3DVertexBuffer9 *
sge::d3d9::vertex_buffer::get() const
{
	return buffer_.get();
}

void
sge::d3d9::vertex_buffer::init()
{
	IDirect3DVertexBuffer9 *ret;

	if(
		device_.CreateVertexBuffer(
			static_cast<
				UINT
			>(
				this->stride().get()
				* this->size().get()
			),
			convert::resource_flags(
				this->resource_flags()
			).get(),
			0, // no FVF
			this->pool(),
			&ret,
			nullptr
		)
		!= D3D_OK
	)
		throw sge::renderer::exception(
			FCPPT_TEXT("Cannot create vertex buffer!")
		);

	buffer_.reset(
		ret
	);
}

void
sge::d3d9::vertex_buffer::on_loss()
{
	converter_.reset();

	buffer_.reset();
}

void
sge::d3d9::vertex_buffer::on_reset()
{
	this->init();
}

template<
	typename View
>
View const
sge::d3d9::vertex_buffer::do_lock(
	first_type const _first,
	count_type const _count,
	sge::renderer::lock_flags::method const _method
) const
{
	if(
		lock_dest_
	)
		throw sge::renderer::exception(
			FCPPT_TEXT("d3d::vertex_buffer::lock() you have to unlock first!")
		);

	void *data(
		nullptr
	);

	count_type const lock_count(
		_count == npos
		?
			this->size()
		:
			_count
	);

	if(
		buffer_->Lock(
			static_cast<
				UINT
			>(
				_first.get()
				* this->stride().get()
			),
			static_cast<
				UINT
			>(
				lock_count.get()
				* this->stride().get()
			),
			&data,
			sge::d3d9::convert::lock_flags(
				_method,
				this->resource_flags()
			).get()
		)
		!= D3D_OK
	)
		throw sge::renderer::exception(
			FCPPT_TEXT("Cannot lock d3d vertex buffer!")
		);

	lock_dest_ =
		static_cast<
			renderer::raw_pointer
		>(
			data
		);

	converter_.lock(
		sge::renderer::vf::dynamic::locked_part(
			lock_dest_,
			_first,
			lock_count,
			_method
		)
	);

	return
		View(
			lock_dest_,
			_count,
			this->format_part(),
			this->format_part_index()
		);
}
