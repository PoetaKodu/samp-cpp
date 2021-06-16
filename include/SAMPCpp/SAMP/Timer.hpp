#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class Timer
{
public:
	Timer() = default;
	Timer(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(Timer const& other_) const { return _id == other_._id; }
	bool operator!=(Timer const& other_) const { return !(*this == other_); }

	int32_t id() const { return _id; }
	bool valid() const { return _id != -1; }

	static Timer create(int interval_, bool repeat_, TimerCallback callback_, void * param_);
	bool destroy();

private:
	int32_t _id = -1;
};


}