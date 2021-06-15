#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/PlayerObject.hpp>

#include <SAMPCpp/SAMP/Player.hpp>
#include <SAMPCpp/SAMP/Vehicle.hpp>

namespace samp_cpp
{

///////////////////////////////////////////
PlayerObject::PlayerObject(Player player_, int32_t id_)
	: _id(id_), _playerId(player_.id())
{
}

///////////////////////////////////////////
PlayerObject PlayerObject::create(Player player_, int modelIdx_, Vec3f const& pos_, Vec3f rot_, float drawDistance_)
{
	return PlayerObject::create(player_, modelIdx_, pos_.x, pos_.y, pos_.z, rot_.x, rot_.y, rot_.z, drawDistance_);
}

///////////////////////////////////////////
PlayerObject PlayerObject::create(Player player_, int modelIdx_, float x_, float y_, float z_, float rX_, float rY_, float rZ_, float drawDistance_)
{
	return PlayerObject{ player_, sampgdk_CreatePlayerObject(player_.id(), modelIdx_, x_, y_, z_, rX_, rY_, rZ_, drawDistance_) };
}

///////////////////////////////////////////
bool PlayerObject::attachToPlayer(Player attachTo_, Vec3f const& offset_, Vec3f const& rot_)
{
	return this->attachToPlayer(attachTo_.id(), offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z);
}

///////////////////////////////////////////
bool PlayerObject::attachToPlayer(Player attachTo_, float offsetX_, float offsetY_, float offsetZ_, float rX_, float rY_, float rZ_)
{
	return sampgdk_AttachPlayerObjectToPlayer(_playerId, _id, attachTo_.id(), offsetX_, offsetY_, offsetZ_, rX_, rY_, rZ_);
}

///////////////////////////////////////////
bool PlayerObject::attachToVehicle(Vehicle vehicle_, Vec3f const& offset_, Vec3f const& rot_)
{
	return this->attachToVehicle(vehicle_.id(), offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z);
}

///////////////////////////////////////////
bool PlayerObject::attachToVehicle(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_AttachPlayerObjectToVehicle(_playerId, _id, vehicle_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_);
}

///////////////////////////////////////////
bool PlayerObject::setPosition(Vec3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

///////////////////////////////////////////
bool PlayerObject::setPosition(float x, float y, float z)
{
	return sampgdk_SetPlayerObjectPos(_playerId, _id, x, y, z);
}

///////////////////////////////////////////
Vec3f PlayerObject::getPosition() const
{
	Vec3f result;
	sampgdk_GetPlayerObjectPos(_playerId, _id, &result.x, &result.y, &result.z);
	return result;
}

///////////////////////////////////////////
bool PlayerObject::setRotation(Vec3f const& rot_)
{
	return this->setRotation(rot_.x, rot_.y, rot_.z);
}

///////////////////////////////////////////
bool PlayerObject::setRotation(float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_SetPlayerObjectRot(_playerId, _id, rotX_, rotY_, rotZ_);
}

///////////////////////////////////////////
Vec3f PlayerObject::getRotation() const
{
	Vec3f result;
	sampgdk_GetPlayerObjectRot(_playerId, _id, &result.x, &result.y, &result.z);
	return result;
}

///////////////////////////////////////////
int PlayerObject::getModel() const
{
	return sampgdk_GetPlayerObjectModel(_playerId, _id);
}

///////////////////////////////////////////
bool PlayerObject::setNoCameraCol()
{
	return sampgdk_SetPlayerObjectNoCameraCol(_playerId, _id);
}

///////////////////////////////////////////
Player PlayerObject::owner() const
{
	return Player{ _playerId };
}

///////////////////////////////////////////
bool PlayerObject::valid() const
{
	return sampgdk_IsValidPlayerObject(_playerId, _id);
}

///////////////////////////////////////////
bool PlayerObject::destroy()
{
	return sampgdk_DestroyPlayerObject(_playerId, _id);
}

///////////////////////////////////////////
int PlayerObject::move(Vec3f const& pos_, Vec3f const& rot_, float speed_)
{
	return sampgdk_MovePlayerObject(_playerId, _id, pos_.x, pos_.y, pos_.z, speed_, rot_.x, rot_.y, rot_.z);
}

///////////////////////////////////////////
int PlayerObject::move(float x_, float y_, float z_, float speed_, float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_MovePlayerObject(_playerId, _id, x_, y_, z_, speed_, rotX_, rotY_, rotZ_);
}

///////////////////////////////////////////
bool PlayerObject::stop()
{
	return sampgdk_StopPlayerObject(_playerId, _id);
}

///////////////////////////////////////////
bool PlayerObject::isMoving() const
{
	return sampgdk_IsPlayerObjectMoving(_playerId, _id);
}

///////////////////////////////////////////
bool PlayerObject::setMaterial(int materialIndex_, int modelIdx_, std::string const& txdName_, std::string const& textureName_, Color materialColor_)
{
	return this->setMaterial(materialIndex_, modelIdx_, txdName_.c_str(), textureName_.c_str(), materialColor_);
}

///////////////////////////////////////////
bool PlayerObject::setMaterial(int materialIndex_, int modelIdx_, char const* txdName_, char const* textureName_, Color materialColor_)
{
	return sampgdk_SetPlayerObjectMaterial(_playerId, _id, materialIndex_, modelIdx_, txdName_, textureName_, materialColor_);
}

///////////////////////////////////////////
bool PlayerObject::setMaterialText(std::string const& text_, int materialIndex_, int materialSize_, std::string const& fontFace_, int fontSize_, bool bold_, Color fontColor_, Color backColor_, int textAlignment_)
{
	return this->setMaterialText(text_.c_str(), materialIndex_, materialSize_, fontFace_.c_str(), fontSize_, bold_, fontColor_, backColor_, textAlignment_);
}

///////////////////////////////////////////
bool PlayerObject::setMaterialText(char const* text_, int materialIndex_, int materialsize_, char const* fontFace_, int fontSize_, bool bold_, Color fontColor_, Color backColor_, int textAlignment_)
{
	return sampgdk_SetPlayerObjectMaterialText(_playerId, _id, text_, materialIndex_, materialsize_, fontFace_, fontSize_, bold_, fontColor_, backColor_, textAlignment_);
}

}