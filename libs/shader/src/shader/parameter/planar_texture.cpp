//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/cg/parameter/named.hpp>
#include <sge/cg/program/object.hpp>
#include <sge/cg/program/object_ref.hpp>
#include <sge/renderer/cg/loaded_texture.hpp>
#include <sge/renderer/cg/loaded_texture_unique_ptr.hpp>
#include <sge/renderer/cg/scoped_texture.hpp>
#include <sge/renderer/context/core_fwd.hpp>
#include <sge/renderer/context/core_ref.hpp>
#include <sge/renderer/device/core.hpp>
#include <sge/renderer/device/core_ref.hpp>
#include <sge/renderer/texture/base.hpp>
#include <sge/renderer/texture/planar.hpp>
#include <sge/shader/pair.hpp>
#include <sge/shader/pair_ref.hpp>
#include <sge/shader/parameter/planar_texture.hpp>
#include <fcppt/make_cref.hpp>
#include <fcppt/make_ref.hpp>
#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/reference_to_base.hpp>
#include <fcppt/assert/optional_error.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/optional/assign.hpp>
#include <fcppt/optional/deref.hpp>
#include <fcppt/optional/maybe_void.hpp>


sge::shader::parameter::planar_texture::planar_texture(
	sge::cg::program::object_ref const _program,
	sge::shader::parameter::name const &_name,
	sge::shader::pair_ref const _parent,
	sge::renderer::device::core_ref const _renderer,
	optional_value const &_value
)
:
	parent_(
		_parent
	),
	renderer_(
		_renderer
	),
	parameter_(
		_program.get().parameter(
			_name.get()
		)
	),
	loaded_texture_(),
	scoped_texture_(),
	optional_render_context_(),
	value_(
		_value
	)
{
	parent_.get().add_planar_texture(
		fcppt::make_ref(
			*this
		)
	);
}

void
sge::shader::parameter::planar_texture::set(
	optional_value const &_value
)
{
	value_ =
		_value;

	fcppt::optional::maybe_void(
		optional_render_context_,
		[
			this
		](
			fcppt::reference<
				sge::renderer::context::core
			> const _render_context
		)
		{
			scoped_texture_ =
				optional_scoped_texture_ptr();

			loaded_texture_ =
				optional_loaded_texture_ptr();

			fcppt::optional::maybe_void(
				value_,
				[
					_render_context,
					this
				](
					fcppt::reference<
						sge::renderer::texture::planar
					> const _texture
				)
				{
					sge::renderer::cg::loaded_texture_unique_ptr const &cur_loaded_texture(
						fcppt::optional::assign(
							loaded_texture_,
							renderer_.get().load_cg_texture(
								parameter_.object(),
								fcppt::reference_to_base<
									sge::renderer::texture::base
								>(
									_texture
								)
							)
						)
					);

					scoped_texture_ =
						optional_scoped_texture_ptr(
							fcppt::make_unique_ptr<
								sge::renderer::cg::scoped_texture
							>(
								_render_context,
								fcppt::make_cref(
									*cur_loaded_texture
								)
							)
						);
				}
			);
		}
	);
}

void
sge::shader::parameter::planar_texture::activate(
	sge::renderer::context::core_ref const _render_context
)
{
	FCPPT_ASSERT_PRE(
		!optional_render_context_.has_value()
	);

	FCPPT_ASSERT_PRE(
		!scoped_texture_.has_value()
	);

	optional_render_context_ =
		optional_render_context(
			_render_context
		);

	this->set(
		value_
	);
}

void
sge::shader::parameter::planar_texture::deactivate()
{
	FCPPT_ASSERT_PRE(
		optional_render_context_.has_value()
	);

	scoped_texture_ =
		optional_scoped_texture_ptr();

	loaded_texture_ =
		optional_loaded_texture_ptr();

	optional_render_context_ =
		optional_render_context();
}

sge::shader::parameter::planar_texture::optional_loaded_texture
sge::shader::parameter::planar_texture::loaded_texture()
{
	return
		fcppt::optional::deref(
			loaded_texture_
		);
}

sge::renderer::texture::stage
sge::shader::parameter::planar_texture::stage() const
{
	return
		FCPPT_ASSERT_OPTIONAL_ERROR(
			scoped_texture_
		)->stage();
}

sge::shader::parameter::planar_texture::~planar_texture()
{
	parent_.get().remove_planar_texture(
		*this
	);
}
