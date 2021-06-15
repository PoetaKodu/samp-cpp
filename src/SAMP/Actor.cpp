#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Actor.hpp>

#include <SAMPCpp/SAMP/Player.hpp>

namespace samp_cpp
{

//////////////////////////////////////////////////////
Actor Actor::create(int modelIdx_, Vec3f const& pos_, float rotation_)
{
	return Actor::create(modelIdx_, pos_.x, pos_.y, pos_.z, rotation_);
}

//////////////////////////////////////////////////////
Actor Actor::create(int modelIdx_, float x_, float y_, float z_, float rotation_)
{
	return Actor{ sampgdk_CreateActor(modelIdx_, x_, y_, z_, rotation_) };
}

//////////////////////////////////////////////////////
bool Actor::destroy()
{
	return sampgdk_DestroyActor(_id);
}

//////////////////////////////////////////////////////
bool Actor::isStreamedIn(Player forPlayer_) const
{
	return sampgdk_IsActorStreamedIn(_id, forPlayer_.id());
}

//////////////////////////////////////////////////////
bool Actor::setVirtualWorld(int vworld_)
{
	return sampgdk_SetActorVirtualWorld(_id, vworld_);
}

//////////////////////////////////////////////////////
int Actor::getVirtualWorld() const
{
	return sampgdk_GetActorVirtualWorld(_id);
}

//////////////////////////////////////////////////////
bool Actor::applyAnimation(std::string const& animLib_, std::string const& animName_, float delta_, bool loop_, bool lockx_, bool locky_, bool freeze_, int time_)
{
	return this->applyAnimation(animLib_.c_str(), animName_.c_str(), delta_, loop_, lockx_, locky_, freeze_, time_);
}

//////////////////////////////////////////////////////
bool Actor::applyAnimation(char const* animLib_, char const* animName_, float delta_, bool loop_, bool lockx_, bool locky_, bool freeze_, int time_)
{
	return sampgdk_ApplyActorAnimation(_id, animLib_, animName_, delta_, loop_, lockx_, locky_, freeze_, time_);
}

//////////////////////////////////////////////////////
bool Actor::clearAnimations()
{
	return sampgdk_ClearActorAnimations(_id);
}

//////////////////////////////////////////////////////
bool Actor::setPosition(Vec3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////////////////////
bool Actor::setPosition(float x_, float y_, float z_)
{
	return sampgdk_SetActorPos(_id, x_, y_, z_);
}

//////////////////////////////////////////////////////
Vec3f Actor::getPosition() const
{
	Vec3f result;
	sampgdk_GetActorPos(_id, &result.x, &result.y, &result.z);
	return result;
}

//////////////////////////////////////////////////////
bool Actor::setFacingAngle(float angle_)
{
	return sampgdk_SetActorFacingAngle(_id, angle_);
}

//////////////////////////////////////////////////////
float Actor::getFacingAngle() const
{
	float result = 0;
	sampgdk_GetActorFacingAngle(_id, &result);
	return result;
}

//////////////////////////////////////////////////////
bool Actor::setHealth(float health_)
{
	return sampgdk_SetActorHealth(_id, health_);
}

//////////////////////////////////////////////////////
float Actor::getHealth() const
{
	float result = 0;
	sampgdk_GetActorHealth(_id, &result);
	return result;
}

//////////////////////////////////////////////////////
bool Actor::setInvulnerable(bool invulnerable_)
{
	return sampgdk_SetActorInvulnerable(_id, invulnerable_);
}

//////////////////////////////////////////////////////
bool Actor::isInvulnerable() const
{
	return sampgdk_IsActorInvulnerable(_id);
}


}