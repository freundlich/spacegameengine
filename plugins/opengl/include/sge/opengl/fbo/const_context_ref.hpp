//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef SGE_OPENGL_FBO_CONST_CONTEXT_REF_HPP_INCLUDED
#define SGE_OPENGL_FBO_CONST_CONTEXT_REF_HPP_INCLUDED

#include <sge/opengl/fbo/context_fwd.hpp>
#include <fcppt/reference_impl.hpp>


namespace sge
{
namespace opengl
{
namespace fbo
{

using
const_context_ref
=
fcppt::reference<
	sge::opengl::fbo::context const
>;

}
}
}

#endif