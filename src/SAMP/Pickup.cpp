#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Pickup.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////
bool StaticPickup::add(int modelIdx_, int type_, Vec3f const& pos_, int virtualWorld_)
{
	return sampgdk_AddStaticPickup(modelIdx_, type_, pos_.x, pos_.y, pos_.z, virtualWorld_) == 1;
}

///////////////////////////////////////////////
bool StaticPickup::add(int modelIdx_, int type_, float x_, float y_, float z_, int virtualWorld_)
{
	return sampgdk_AddStaticPickup(modelIdx_, type_, x_, y_, z_, virtualWorld_) == 1;
}

///////////////////////////////////////////////
Pickup Pickup::create(int modelIdx_, Type type_, Vec3f const& pos_, int virtualWorld_)
{
	return Pickup::create(modelIdx_, type_, pos_.x, pos_.y, pos_.z, virtualWorld_);
}

///////////////////////////////////////////////
Pickup Pickup::create(int modelIdx_, Type type_, float x_, float y_, float z_, int virtualWorld_)
{
	return Pickup{ sampgdk_CreatePickup(modelIdx_, static_cast<int>(type_), x_, y_, z_, virtualWorld_) };
}

///////////////////////////////////////////////
bool Pickup::destroy()
{
	return sampgdk_DestroyPickup(_id);
}

}