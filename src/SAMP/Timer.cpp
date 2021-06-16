#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Timer.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////
Timer Timer::create(int interval_, bool repeat_, TimerCallback callback_, void * param_)
{
	return Timer{ sampgdk_SetTimer(interval_, repeat_, callback_, param_) };
}

///////////////////////////////////////////////
bool Timer::destroy()
{
	return sampgdk_KillTimer(_id);
}

}