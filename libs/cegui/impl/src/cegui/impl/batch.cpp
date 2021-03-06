//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/cegui/impl/batch.hpp>
#include <sge/cegui/impl/clip.hpp>
#include <sge/renderer/resource_flags_field.hpp>
#include <sge/renderer/device/core.hpp>
#include <sge/renderer/device/core_ref.hpp>
#include <sge/renderer/texture/planar_ref.hpp>
#include <sge/renderer/vertex/buffer.hpp>
#include <sge/renderer/vertex/buffer_parameters.hpp>
#include <sge/renderer/vertex/const_declaration_ref.hpp>
#include <sge/renderer/vertex/count.hpp>
#include <sge/renderer/vf/dynamic/part_index.hpp>


sge::cegui::impl::batch::batch(
	sge::renderer::device::core_ref const _renderer,
	sge::renderer::vertex::const_declaration_ref const _vertex_declaration,
	sge::renderer::texture::planar_ref const _texture,
	sge::renderer::vertex::count const _vertex_count,
	sge::cegui::impl::clip const _clip
)
:
	texture_(
		_texture
	),
	vertex_buffer_(
		_renderer.get().create_vertex_buffer(
			sge::renderer::vertex::buffer_parameters(
				_vertex_declaration,
				sge::renderer::vf::dynamic::part_index(
					0U
				),
				_vertex_count,
				sge::renderer::resource_flags_field::null()
			)
		)
	),
	clip_(
		_clip
	)
{
}

sge::cegui::impl::batch::batch(
	batch &&
)
noexcept
= default;

sge::cegui::impl::batch &
sge::cegui::impl::batch::operator=(
	batch &&
)
noexcept
= default;

sge::cegui::impl::batch::~batch()
= default;

sge::renderer::texture::planar &
sge::cegui::impl::batch::texture() const
{
	return
		texture_.get();
}

sge::renderer::vertex::buffer &
sge::cegui::impl::batch::vertex_buffer() const
{
	return
		*vertex_buffer_;
}

sge::cegui::impl::clip
sge::cegui::impl::batch::clip() const
{
	return
		clip_;
}
