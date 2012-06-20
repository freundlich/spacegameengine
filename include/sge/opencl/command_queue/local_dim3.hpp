#ifndef SGE_OPENCL_COMMAND_QUEUE_LOCAL_DIM3_HPP_INCLUDED
#define SGE_OPENCL_COMMAND_QUEUE_LOCAL_DIM3_HPP_INCLUDED

#include <fcppt/strong_typedef.hpp>
#include <sge/opencl/dim3.hpp>

namespace sge
{
namespace opencl
{
namespace command_queue
{
FCPPT_MAKE_STRONG_TYPEDEF(
	sge::opencl::dim3,
	local_dim3);
}
}
}

#endif

