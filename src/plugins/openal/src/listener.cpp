#include "../listener.hpp"
#include "../error.hpp"
#include "../log.hpp"
#include "../openal.hpp"

sge::openal::listener::listener()
	: pos_(no_initialization_tag()),
	  vel_(no_initialization_tag())
{
	pos(audio::point::null());
	vel(audio::point::null());
	direction(
		audio::angle(
			audio::point(
				static_cast<audio::unit>(0),
				static_cast<audio::unit>(0),
				static_cast<audio::unit>(1)),
			audio::point(
				static_cast<audio::unit>(0),
				static_cast<audio::unit>(1),
				static_cast<audio::unit>(0))));
}

void sge::openal::listener::vel(audio::point const &n)
{
	SGE_LOG_DEBUG(log(),log::_1 << SGE_TEXT("setting listener velocity to ") << n);
	vel_ = n;
	ALfloat const vec[3] = 
		{ 
			static_cast<ALfloat>(n.x()),
			static_cast<ALfloat>(n.y()),
			static_cast<ALfloat>(n.z()) 
		};
	alListenerfv(AL_VELOCITY, vec); SGE_OPENAL_ERROR_CHECK;
}

sge::audio::point const sge::openal::listener::vel() const
{
	return vel_;
}

void sge::openal::listener::pos(audio::point const &n)
{
	SGE_LOG_DEBUG(log(),log::_1 << SGE_TEXT("setting listener position to ") << n);
	pos_ = n;
	ALfloat const vec[3] = 
		{ 
			static_cast<ALfloat>(n.x()),
			static_cast<ALfloat>(n.y()),
			static_cast<ALfloat>(n.z()) 
		};
	alListenerfv(AL_POSITION, vec); SGE_OPENAL_ERROR_CHECK;
}

sge::audio::point const sge::openal::listener::pos() const
{
	return pos_;
}

void sge::openal::listener::direction(audio::angle const &n)
{
	ALfloat const vec[6] = 
		{ 
			static_cast<ALfloat>(n.forward.x()),
			static_cast<ALfloat>(n.forward.y()),
			static_cast<ALfloat>(n.forward.z()),
			static_cast<ALfloat>(n.up.x()),
			static_cast<ALfloat>(n.up.y()),
			static_cast<ALfloat>(n.up.z()) 
		};

	alListenerfv(AL_POSITION, vec); SGE_OPENAL_ERROR_CHECK;
}


sge::audio::angle const sge::openal::listener::direction() const
{
	return angle_;
}
