//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_OPENAL_FUNCS_ALC_MAKE_CONTEXT_CURRENT_HPP_INCLUDED
#define SGE_OPENAL_FUNCS_ALC_MAKE_CONTEXT_CURRENT_HPP_INCLUDED

#include <sge/openal/alc.hpp>
#include <fcppt/reference_fwd.hpp>


namespace sge
{
namespace openal
{
namespace funcs
{

void
alc_make_context_current(
	fcppt::reference<
		ALCdevice
	>,
	ALCcontext *
);

}
}
}

#endif
