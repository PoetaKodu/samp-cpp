#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Object.hpp>

#include <SAMPCpp/SAMP/Player.hpp>
#include <SAMPCpp/SAMP/Vehicle.hpp>

namespace samp_cpp
{

////////////////////////////////////////////////////////////
Object Object::create(int modelIdx_, Vec3f const& pos_, Vec3f const& rot_, float drawDistance_)
{
	return Object::create(modelIdx_, pos_.x, pos_.y, pos_.z, rot_.x, rot_.y, rot_.z, drawDistance_);
}

////////////////////////////////////////////////////////////
Object Object::create(int modelIdx_, float x_, float y_, float z_, float rX_, float rY_, float rZ_, float drawDistance_)
{
	return Object{ sampgdk_CreateObject(modelIdx_, x_, y_, z_, rX_, rY_, rZ_, drawDistance_) };
}

////////////////////////////////////////////////////////////
bool Object::attachToVehicle(Vehicle vehicle_, Vec3f const& offset_, Vec3f const& rot_)
{
	return this->attachToVehicle(vehicle_, offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
bool Object::attachToVehicle(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_AttachObjectToVehicle(_id, vehicle_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
bool Object::attachToObject(Object attachTo_, Vec3f const& offset_, Vec3f const& rot_, bool syncRotation_)
{
	return this->attachToObject(attachTo_, offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z, syncRotation_);
}

////////////////////////////////////////////////////////////
bool Object::attachToObject(Object attachTo_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_, bool syncRotation_)
{
	return sampgdk_AttachObjectToObject(_id, attachTo_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_, syncRotation_);
}

////////////////////////////////////////////////////////////
bool Object::attachToPlayer(Player player_, Vec3f const& offset_, Vec3f const& rot_)
{
	return this->attachToPlayer(player_, offset_.x, offset_.y, offset_.z, rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
bool Object::attachToPlayer(Player player_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_AttachObjectToPlayer(_id, player_.id(), offsetX_, offsetY_, offsetZ_, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
bool Object::setPosition(Vec3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

////////////////////////////////////////////////////////////
bool Object::setPosition(float x_, float y_, float z_)
{
	return sampgdk_SetObjectPos(_id, x_, y_, z_);
}

////////////////////////////////////////////////////////////
Vec3f Object::getPosition() const
{
	Vec3f result;
	sampgdk_GetObjectPos(_id, &result.x, &result.y, &result.z);
	return result;
}

////////////////////////////////////////////////////////////
bool Object::setRotation(Vec3f const& rot_)
{
	return this->setRotation(rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
bool Object::setRotation(float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_SetObjectRot(_id, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
Vec3f Object::getRotation() const
{
	Vec3f result;
	sampgdk_GetObjectRot(_id, &result.x, &result.y, &result.z);
	return result;
}

////////////////////////////////////////////////////////////
int Object::getModel() const
{
	return sampgdk_GetObjectModel(_id);
}

////////////////////////////////////////////////////////////
bool Object::setNoCameraCol()
{
	return sampgdk_SetObjectNoCameraCol(_id);
}

////////////////////////////////////////////////////////////
bool Object::valid() const
{
	return _id != INVALID_OBJECT_ID && sampgdk_IsValidObject(_id);
}

////////////////////////////////////////////////////////////
bool Object::destroy()
{
	return sampgdk_DestroyObject(_id);
}


///////////////////////////////////////////
int Object::move(Vec3f const& pos_, float speed_, Vec3f const& rot_)
{
	return this->move(pos_.x, pos_.y, pos_.z, speed_, rot_.x, rot_.y, rot_.z);
}

////////////////////////////////////////////////////////////
int Object::move(float x_, float y_, float z_, float speed_, float rotX_, float rotY_, float rotZ_)
{
	return sampgdk_MoveObject(_id, x_, y_, z_, speed_, rotX_, rotY_, rotZ_);
}

////////////////////////////////////////////////////////////
bool Object::stop()
{
	return sampgdk_StopObject(_id);
}

////////////////////////////////////////////////////////////
bool Object::isMoving() const
{
	return sampgdk_IsObjectMoving(_id);
}

////////////////////////////////////////////////////////////
bool Object::setMaterial(int materialIndex_, int modelIdx_, std::string const& txdName_, std::string const& textureName_, Color materialColor_)
{
	return this->setMaterial(materialIndex_, modelIdx_, txdName_.c_str(), textureName_.c_str(), materialColor_);
}

////////////////////////////////////////////////////////////
bool Object::setMaterial(int materialIndex_, int modelIdx_, char const* txdName_, char const* textureName_, Color materialColor_)
{
	return sampgdk_SetObjectMaterial(_id, materialIndex_, modelIdx_, txdName_, textureName_, materialColor_);
}

////////////////////////////////////////////////////////////
bool Object::setMaterialText(std::string const& text_, int materialIndex_, ObjectMaterialSize materialSize_, std::string const& fontFace_, int fontSize_, bool bold_, Color fontColor_, Color backColor_, TextAlign textAlignment_)
{
	return this->setMaterialText(text_.c_str(), materialIndex_, materialSize_, fontFace_.c_str(), fontSize_, bold_, fontColor_, backColor_, textAlignment_);
}

////////////////////////////////////////////////////////////
bool Object::setMaterialText(char const* text_, int materialIndex_, ObjectMaterialSize materialSize_, char const* fontFace_, int fontSize_, bool bold_, Color fontColor_, Color backColor_, TextAlign textAlignment_)
{
	return sampgdk_SetObjectMaterialText(_id, text_, materialIndex_, static_cast<int>(materialSize_), fontFace_, fontSize_, bold_, fontColor_, backColor_, toObjectMaterialTextAlign(textAlignment_));
}

////////////////////////////////////////////////////////////
bool Object::setObjectsDefaultCameraCol(bool disable_)
{
	return sampgdk_SetObjectsDefaultCameraCol(disable_);
}

}