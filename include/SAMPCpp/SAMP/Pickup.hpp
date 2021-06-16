#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class StaticPickup final
{
public:
	static bool add(int modelIdx_, int type_, Vec3f const& pos_, int virtualWorld_);
	static bool add(int modelIdx_, int type_, float x_, float y_, float z_, int virtualWorld_);
};

class Pickup
{
public:
	Pickup(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(Pickup const& other_) const { return _id == other_._id; }
	bool operator!=(Pickup const& other_) const { return !(*this == other_); }

	int32_t id() const { return _id; }

	static Pickup create(int modelIdx_, int type_, Vec3f const& pos_, int virtualWorld_);
	static Pickup create(int modelIdx_, int type_, float x_, float y_, float z_, int virtualWorld_);
	bool destroy();

private:
	int32_t _id;
};

}