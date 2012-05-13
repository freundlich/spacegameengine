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


#include <sge/cg/string.hpp>
#include <sge/cg/context/object.hpp>
#include <sge/cg/parameter/named.hpp>
#include <sge/cg/parameter/object.hpp>
#include <sge/cg/parameter/matrix/set.hpp>
#include <sge/cg/parameter/scalar/set.hpp>
#include <sge/cg/parameter/vector/set.hpp>
#include <sge/cg/profile/object.hpp>
#include <sge/cg/profile/shader_type.hpp>
#include <sge/cg/program/from_string_parameters.hpp>
#include <sge/cg/program/main_function.hpp>
#include <sge/cg/program/object.hpp>
#include <sge/cg/program/source.hpp>
#include <sge/cg/program/source_type.hpp>
#include <sge/image/colors.hpp>
#include <sge/renderer/bit_depth.hpp>
#include <sge/renderer/const_vertex_buffer_ref_container.hpp>
#include <sge/renderer/depth_stencil_buffer.hpp>
#include <sge/renderer/device.hpp>
#include <sge/renderer/first_vertex.hpp>
#include <sge/renderer/lock_mode.hpp>
#include <sge/renderer/no_multi_sampling.hpp>
#include <sge/renderer/nonindexed_primitive_type.hpp>
#include <sge/renderer/parameters.hpp>
#include <sge/renderer/resource_flags_none.hpp>
#include <sge/renderer/scoped_vertex_declaration_and_buffers.hpp>
#include <sge/renderer/scoped_vertex_lock.hpp>
#include <sge/renderer/vertex_buffer.hpp>
#include <sge/renderer/vertex_buffer_scoped_ptr.hpp>
#include <sge/renderer/vertex_count.hpp>
#include <sge/renderer/vertex_declaration.hpp>
#include <sge/renderer/vertex_declaration_scoped_ptr.hpp>
#include <sge/renderer/vsync.hpp>
#include <sge/renderer/windowed.hpp>
#include <sge/renderer/cg/loaded_program.hpp>
#include <sge/renderer/cg/loaded_program_scoped_ptr.hpp>
#include <sge/renderer/cg/scoped_program.hpp>
#include <sge/renderer/clear/parameters.hpp>
#include <sge/renderer/context/object.hpp>
#include <sge/renderer/context/scoped.hpp>
#include <sge/renderer/target/onscreen.hpp>
#include <sge/renderer/vf/format.hpp>
#include <sge/renderer/vf/iterator.hpp>
#include <sge/renderer/vf/part.hpp>
#include <sge/renderer/vf/pos.hpp>
#include <sge/renderer/vf/vertex.hpp>
#include <sge/renderer/vf/view.hpp>
#include <sge/renderer/vf/dynamic/make_format.hpp>
#include <sge/renderer/vf/dynamic/make_part_index.hpp>
#include <sge/systems/cursor_option_field.hpp>
#include <sge/systems/input.hpp>
#include <sge/systems/input_helper.hpp>
#include <sge/systems/input_helper_field.hpp>
#include <sge/systems/instance.hpp>
#include <sge/systems/list.hpp>
#include <sge/systems/quit_on_escape.hpp>
#include <sge/systems/renderer.hpp>
#include <sge/systems/window.hpp>
#include <sge/viewport/fill_on_resize.hpp>
#include <sge/window/dim.hpp>
#include <sge/window/parameters.hpp>
#include <sge/window/system.hpp>
#include <sge/window/title.hpp>
#include <awl/main/exit_code.hpp>
#include <awl/main/exit_failure.hpp>
#include <awl/main/function_context_fwd.hpp>
#include <fcppt/cref.hpp>
#include <fcppt/exception.hpp>
#include <fcppt/text.hpp>
#include <fcppt/assign/make_container.hpp>
#include <fcppt/io/cerr.hpp>
#include <fcppt/math/matrix/object_impl.hpp>
#include <fcppt/math/matrix/scaling.hpp>
#include <fcppt/math/vector/object_impl.hpp>
#include <fcppt/math/vector/static.hpp>
#include <fcppt/signal/auto_connection.hpp>
#include <fcppt/signal/scoped_connection.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/vector/vector10.hpp>
#include <example_main.hpp>
#include <exception>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


awl::main::exit_code const
example_main(
	awl::main::function_context const &
)
try
{
	sge::systems::instance const sys(
		sge::systems::list()
		(
			sge::systems::window(
				sge::window::parameters(
					sge::window::title(
						FCPPT_TEXT("sge cg parameters test")
					),
					sge::window::dim(
						1024,
						768
					)
				)
			)
		)
		(
			sge::systems::renderer(
				sge::renderer::parameters(
					sge::renderer::windowed(
						sge::renderer::bit_depth::depth32
					),
					sge::renderer::depth_stencil_buffer::off,
					sge::renderer::vsync::on,
					sge::renderer::no_multi_sampling
				),
				sge::viewport::fill_on_resize()
			)
		)
		(
			sge::systems::input(
				sge::systems::input_helper_field(
					sge::systems::input_helper::keyboard_collector
				),
				sge::systems::cursor_option_field::null()
			)
		)
	);

	sge::cg::context::object const cg_context;

	sge::cg::profile::object const vertex_profile(
		sys.renderer().create_cg_profile(
			sge::cg::profile::shader_type::vertex
		)
	);

	sge::cg::string const vertex_shader_source(
		"struct C2E1v_Output {\n"
		"	float4 position : POSITION;\n"
		"	float3 color    : COLOR;\n"
		"};\n"
		"\n"
		"C2E1v_Output C2E1v_green(float2 position : POSITION, uniform float4x4 transformation, uniform float4 translation, uniform float green)\n"
		"{\n"
		"	C2E1v_Output OUT;\n"
		"\n"
		"	OUT.position = translation + mul(transformation, float4(position, 0, 1));\n"
		"	OUT.color = float3(0,green,0);\n"
		"\n"
		"	return OUT;\n"
		"}\n"
	);

	sge::cg::program::object vertex_program(
		sge::cg::program::from_string_parameters(
			cg_context,
			sge::cg::program::source_type::text,
			vertex_profile,
			sge::cg::program::source(
				vertex_shader_source
			),
			sge::cg::program::main_function(
				"C2E1v_green"
			),
			sys.renderer().cg_compile_options(
				cg_context,
				vertex_profile
			)
		)
	);

	sge::cg::parameter::matrix::set(
		vertex_program.parameter(
			"transformation"
		).object(),
		fcppt::math::matrix::scaling(
			0.5f,
			1.f,
			1.f
		)
	);

	sge::cg::parameter::vector::set(
		vertex_program.parameter(
			"translation"
		).object(),
		fcppt::math::vector::static_<
			float,
			4
		>::type(
			0.5f,
			0.f,
			0.f,
			0.f
		)
	);

	sge::cg::parameter::scalar::set(
		vertex_program.parameter(
			"green"
		).object(),
		1.f
	);

	sge::renderer::cg::loaded_program_scoped_ptr const loaded_program(
		sys.renderer().load_cg_program(
			vertex_program
		)
	);

	typedef sge::renderer::vf::pos<
		float,
		3
	> pos3_type;

	typedef sge::renderer::vf::part<
		boost::mpl::vector1<
			pos3_type
		>
	> format_part;

	typedef sge::renderer::vf::format<
		boost::mpl::vector1<
			format_part
		>
	> format;

	sge::renderer::vertex_declaration_scoped_ptr const vertex_declaration(
		sys.renderer().create_vertex_declaration(
			sge::renderer::vf::dynamic::make_format<
				format
			>()
		)
	);

	sge::renderer::vertex_buffer_scoped_ptr const vertex_buffer(
		sys.renderer().create_vertex_buffer(
			*vertex_declaration,
			sge::renderer::vf::dynamic::make_part_index<
				format,
				format_part
			>(),
			sge::renderer::vertex_count(
				3u
			),
			sge::renderer::resource_flags::none
		)
	);

	{
		sge::renderer::scoped_vertex_lock const vblock(
			*vertex_buffer,
			sge::renderer::lock_mode::writeonly
		);

		typedef sge::renderer::vf::view<
			format_part
		> vertex_view;

		vertex_view const vertices(
			vblock.value()
		);

		vertex_view::iterator vb_it(
			vertices.begin()
		);

		typedef pos3_type::packed_type vec3;

		(*vb_it).set<
			pos3_type
		>(
			vec3(
				-1.f,
				1.f,
				0.f
			)
		);

		++vb_it;

		(*vb_it).set<
			pos3_type
		>(
			vec3(
				-1.f,
				-1.f,
				0.f
			)
		);

		++vb_it;

		(*vb_it).set<
			pos3_type
		>(
			vec3(
				1.f,
				1.f,
				0.f
			)
		);
	}

	fcppt::signal::scoped_connection const input_connection(
		sge::systems::quit_on_escape(
			sys
		)
	);

	while(
		sys.window_system().poll()
	)
	{
		sge::renderer::context::scoped const scoped_block(
			sys.renderer(),
			sys.renderer().onscreen_target()
		);

		scoped_block.get().clear(
			sge::renderer::clear::parameters()
			.back_buffer(
				sge::image::colors::black()
			)
		);

		sge::renderer::scoped_vertex_declaration_and_buffers const vb_context(
			scoped_block.get(),
			*vertex_declaration,
			fcppt::assign::make_container<
				sge::renderer::const_vertex_buffer_ref_container
			>(
				fcppt::cref(
					*vertex_buffer
				)
			)
		);

		sge::renderer::cg::scoped_program const scoped_program(
			scoped_block.get(),
			*loaded_program
		);

		scoped_block.get().render_nonindexed(
			sge::renderer::first_vertex(
				0u
			),
			sge::renderer::vertex_count(
				3u
			),
			sge::renderer::nonindexed_primitive_type::triangle
		);
	}

	return
		sys.window_system().exit_code();
}
catch(
	fcppt::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.string()
		<< FCPPT_TEXT('\n');

	return awl::main::exit_failure();
}
catch(
	std::exception const &_error
)
{
	fcppt::io::cerr()
		<< _error.what()
		<< FCPPT_TEXT('\n');

	return awl::main::exit_failure();
}