#include SAMPCPP_PCH

#include <SAMPCpp/Player.hpp>

namespace samp_cpp
{

/////////////////////////////////
bool Player::msg(ChatFmtColorPair const& coloredMsg_)
{
	return this->msg(coloredMsg_.first, coloredMsg_.second);
}

/////////////////////////////////
bool Player::msg(Color color_, std::string const& content_)
{
	return this->msg(color_, content_.c_str());
}

//////////////////////////////////////
bool Player::msg(Color color_, char const* content_)
{
	return sampgdk_SendClientMessage(_id, color_, content_);
}

//////////////////////////////////////
bool Player::setPosition(math::Vector3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////
bool Player::setPosition(float x_, float y_, float z_)
{
	return sampgdk_SetPlayerPos(_id, x_, y_, z_);
}

//////////////////////////////////////
math::Vector3f Player::getPosition() const
{
	math::Vector3f result;

	sampgdk_GetPlayerPos(_id, &result.x, &result.y, &result.z);
		
	return result;
}

//////////////////////////////////////
bool Player::setCameraPosition(math::Vector3f const& pos_)
{
	return this->setCameraPosition(pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////
bool Player::setCameraPosition(float x_, float y_, float z_)
{
	return sampgdk_SetPlayerCameraPos(_id, x_, y_, z_);
}

//////////////////////////////////////
bool Player::setCameraLookAt(math::Vector3f const& lookAt_, CameraMove moveMethod_)
{
	return this->setCameraLookAt(lookAt_.x, lookAt_.y, lookAt_.z, moveMethod_);
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