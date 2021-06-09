#include SAMPCPP_PCH

#include <SAMPCpp/Player.hpp>

namespace samp_cpp
{
	
//////////////////////////////////////
bool Player::setPosition(float x_, float y_, float z_)
{
	return sampgdk_SetPlayerPos(_id, x_, y_, z_);
}

//////////////////////////////////////
bool Player::msg(int color_, std::string const& content_)
{
	return this->msg(color_, content_.c_str());
}

//////////////////////////////////////
bool Player::msg(int color_, char const* content_)
{
	return sampgdk_SendClientMessage(_id, color_, content_);
}

//////////////////////////////////////
bool Player::setCameraPosition(float x_, float y_, float z_)
{
	return sampgdk_SetPlayerCameraPos(_id, x_, y_, z_);
}

//////////////////////////////////////
bool Player::setCameraLookAt(float x_, float y_, float z_, CameraMove moveMethod_)
{
	return sampgdk_SetPlayerCameraLookAt(_id, x_, y_, z_, static_cast<int>(moveMethod_));
}

//////////////////////////////////////
std::string Player::getName() const
{
	std::string name;
	name.resize(MAX_PLAYER_NAME);
	if (!sampgdk_GetPlayerName(_id, name.data(), MAX_PLAYER_NAME))
		return {};

	return name;
}



}