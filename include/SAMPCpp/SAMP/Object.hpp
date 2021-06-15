#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

namespace samp_cpp
{
	
class Player;
class Vehicle;

class Object
{
public:
	Object(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(Object const& other_) const { return _id == other_._id; }
	bool operator!=(Object const& other_) const { return !(*this == other_); }


	int32_t id() const { return _id; }

	float dist(Vec3f const& pos_) const { return this->pos().distanceSquared(pos_); }

	// A shorthand for this->getRotation()
	Vec3f rot() const { return this->getRotation(); }

	// A shorthand for this->getPosition()
	Vec3f pos() const { return this->getPosition(); }

	static Object create(int modelIdx_, Vec3f const& pos_, Vec3f const& rot_, float drawDistance_);
	static Object create(int modelIdx_, float x_, float y_, float z_, float rX_, float rY_, float rZ_, float drawDistance_);
	bool attachToVehicle(Vehicle vehicle_, Vec3f const& offset_, Vec3f const& rot_);
	bool attachToVehicle(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_);
	bool attachToObject(Object attachTo_, Vec3f const& offset_, Vec3f const& rot_, bool syncRotation_);
	bool attachToObject(Object attachTo_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_, bool syncRotation_);
	bool attachToPlayer(Player player_, Vec3f const& offset_, Vec3f const& rot_);
	bool attachToPlayer(Player player_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_);
	bool setPosition(Vec3f const& pos_);
	bool setPosition(float x_, float y_, float z_);
	Vec3f getPosition() const;
	bool setRotation(Vec3f const& rot_);
	bool setRotation(float rotX_, float rotY_, float rotZ_);
	Vec3f getRotation() const;
	int getModel() const;
	bool setNoCameraCol();
	bool valid() const;
	bool destroy();
	int move(float x_, float y_, float z_, float speed_, float rotX_, float rotY_, float rotZ_);
	bool stop();
	bool isMoving() const;
	bool setMaterial(int materialIndex_, int modelIdx_, std::string const& txdName_, std::string const& textureName_, Color materialColor_);
	bool setMaterial(int materialIndex_, int modelIdx_, char const* txdName_, char const* textureName_, Color materialColor_);
	bool setMaterialText(std::string const& text_, int materialIndex_, int materialSize_, std::string const& fontFace_, int fontSize_, bool bold_, Color fontColor_, Color backColor_, int textAlignment_);
	bool setMaterialText(char const* text_, int materialIndex_, int materialSize_, char const* fontFace_, int fontSize_, bool bold_, Color fontColor_, Color backColor_, int textAlignment_);
	static bool setObjectsDefaultCameraCol(bool disable_);

private:
	int32_t _id;
};


}