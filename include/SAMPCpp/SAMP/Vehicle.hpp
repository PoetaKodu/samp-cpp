#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class Vehicle
{
public:
	Vehicle(int32_t id_)
		: _id(id_)
	{
	}

	
	bool valid() const { return _id != INVALID_VEHICLE_ID; }
	int32_t id() const { return _id; }
private:
	int32_t _id;
};

}