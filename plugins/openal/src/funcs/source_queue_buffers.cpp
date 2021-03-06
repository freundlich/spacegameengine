//          Copyright Carl Philipp Reh 2006 - 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <sge/audio/exception.hpp>
#include <sge/openal/al.hpp>
#include <sge/openal/check_state.hpp>
#include <sge/openal/source_id.hpp>
#include <sge/openal/funcs/source_queue_buffers.hpp>
#include <fcppt/text.hpp>


void
sge::openal::funcs::source_queue_buffers(
	sge::openal::source_id const _source,
	ALuint const *const _buffers,
	ALsizei const _size
)
{
	::alSourceQueueBuffers(
		_source.get(),
		_size,
		_buffers
	);

	SGE_OPENAL_CHECK_STATE(
		FCPPT_TEXT("alSourceQueueBuffers failed"),
		sge::audio::exception
	)
}
