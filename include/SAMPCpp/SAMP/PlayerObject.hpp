#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>
#include <SAMPCpp/SAMP/Object.hpp>

namespace samp_cpp
{

class Player;
class Vehicle;

class PlayerObject
{
public:
	PlayerObject() = default;
	PlayerObject(Player player_, int32_t id_);

	bool operator==(PlayerObject const& other_) const { return (_playerId == other_._playerId && _id == other_._id); }
	bool operator!=(PlayerObject const& other_) const { return !(*this == other_); }


	int32_t id() const { return _id; }
	Player owner() const;


	bool valid() const;

	float dist(Vec3f const& pos_) const { return this->pos().distanceSquared(pos_); }

	// A shorthand for this->getRotation()
	Vec3f rot() const { return this->getRotation(); }

	// A shorthand for this->getPosition()
	Vec3f pos() const { return this->getPosition(); }

	static PlayerObject create(Player player_, int modelIdx_, Vec3f const& pos_, Vec3f rot_, float drawDistance_);
	static PlayerObject create(Player player_, int modelIdx_, float x_, float y_, float z_, float rX_, float rY_, float rZ_, float drawDistance_);
	bool attachTo(Player attachTo_, Vec3f const& offset_, Vec3f const& rot_);
	bool attachTo(Player attachTo_, float offsetX_, float offsetY_, float offsetZ_, float rX_, float rY_, float rZ_);
	bool attachTo(Vehicle vehicle_, Vec3f const& offset_, Vec3f const& rot_);
	bool attachTo(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_, float rotX_, float rotY_, float rotZ_);
	bool setPosition(Vec3f const& pos_);
	bool setPosition(float x, float y, float z);
	Vec3f getPosition() const;
	bool setRotation(Vec3f const& rot_);
	bool setRotation(float rotX_, float rotY_, float rotZ_);
	Vec3f getRotation() const;
	int getModel() const;
	bool setNoCameraCol();
	bool destroy();
	int move(Vec3f const& pos_, float speed_, Vec3f const& rot_ = { -1000.f, -1000.f, -1000.f });
	int move(float x_, float y_, float z_, float speed_, float rotX_ = -1000.f, float rotY_ = -1000.f, float rotZ_ = -1000.f);
	bool stop();
	bool isMoving() const;
	bool setMaterial(int materialIndex_, int modelIdx_, std::string const& txdName_, std::string const& textureName_, Color materialColor_ = colors::transparent);
	bool setMaterial(int materialIndex_, int modelIdx_, char const* txdName_, char const* textureName_, Color materialColor_ = colors::transparent);
	bool setMaterialText(std::string const& text_, int materialIndex_, ObjectMaterialSize materialSize_ = ObjectMaterialSize::Size_256x128, std::string const& fontFace_ = "Arial", int fontSize_ = 24, bool bold_ = true, Color fontColor_ = colors::white, Color backColor_ = colors::transparent, TextAlign textAlignment_ = TextAlign::Left);
	bool setMaterialText(char const* text_, int materialIndex_, ObjectMaterialSize materialSize_ = ObjectMaterialSize::Size_256x128, char const* fontFace_ = "Arial", int fontSize_ = 24, bool bold_ = true, Color fontColor_ = colors::white, Color backColor_ = colors::transparent, TextAlign textAlignment_ = TextAlign::Left);
private:
	int32_t _id = -1, _playerId = -1;
};

}