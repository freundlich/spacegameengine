#include <sge/systems/instance.hpp>
#include <sge/systems/list.hpp>
#include <sge/font/metrics.hpp>
#include <sge/font/font.hpp>
#include <sge/font/drawer_3d.hpp>
#include <sge/media.hpp>
#include <sge/exception.hpp>
#include <sge/renderer/scoped_block.hpp>
#include <sge/renderer/system.hpp>
#include <sge/text.hpp>
#include <sge/iostream.hpp>
#include <exception>
#include <iostream>

int main()
try
{
	/*sge::systems::instance sys(
		sge::systems::list()
		(sge::renderer::parameters(
			sge::renderer::display_mode(
				sge::renderer::screen_size_t(
					static_cast<sge::renderer::screen_unit>(640),
					static_cast<sge::renderer::screen_unit>(480)),
				sge::renderer::bit_depth::bd32
			),
			sge::renderer::depth_format::off,
			sge::renderer::stencil_format::off))
		(sge::systems::parameterless::font));

	sge::font::metrics_ptr const metrics = 
		sys.font_system()->create_font(
			sge::media_path() / SGE_TEXT("fonts") / SGE_TEXT("default.ttf"),
			static_cast<sge::font::size_type>(15));
	
	sge::font::drawer_ptr const drawer(
		new sge::font::drawer_3d(sys.renderer()));
	sge::font::font font(
		metrics,drawer);

	while (true)
	{
		sge::window::dispatch();
		sge::renderer::scoped_block block(sys.renderer());
		font.draw_text(
			SGE_TEXT("hello world"),
			sge::font::pos(
				static_cast<sge::font::unit>(0),
				static_cast<sge::font::unit>(0)),
			sge::math::structure_cast<sge::font::unit>(sys.renderer->screen_size()),
			sge::font::align_h::center,
			sge::font::align_v::center);
	}*/
}
catch (sge::exception const &e)
{
	sge::cerr << SGE_TEXT("caught sge exception: ") << e.what() << SGE_TEXT("\n");
}
catch (std::exception const &e)
{
	std::cerr << "caught std exception: " << e.what() << "\n";
}
