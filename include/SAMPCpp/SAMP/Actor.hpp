#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class Player;

class Actor
{
public:
	Actor(int32_t id_)
		: _id(id_)
	{
	}

	int32_t id() const { return _id; }
	bool valid() const;	

	float dist(Vec3f const& pos_) const { return this->pos().distanceSquared(pos_); }

	// A shorthand for this->getFacingAngle()
	float rot() const { return this->getFacingAngle(); }

	// A shorthand for this->getPosition()
	Vec3f pos() const { return this->getPosition(); }

	// A shorthand for this->getVirtualWorld()
	int32_t world() const { return this->getVirtualWorld(); }

	// A shorthand for this->getHealth()
	float hp() const { return this->getHealth(); }

	static Actor create(int modelIdx_, Vec3f const& pos_, float rotation_);
	static Actor create(int modelIdx_, float x_, float y_, float z_, float rotation_);

	bool destroy();
	bool isStreamedIn(Player forPlayer_) const;
	bool setVirtualWorld(int vworld_);
	int getVirtualWorld() const;
	bool applyAnimation(std::string const& animLib_, std::string const& animName_, float delta_, bool loop_, bool lockx_, bool locky_, bool freeze_, int time_);
	bool applyAnimation(char const* animLib_, char const* animName_, float delta_, bool loop_, bool lockx_, bool locky_, bool freeze_, int time_);
	bool clearAnimations();
	bool setPosition(Vec3f const& pos_);
	bool setPosition(float x_, float y_, float z_);
	Vec3f getPosition() const;
	bool setFacingAngle(float angle_);
	float getFacingAngle() const;
	bool setHealth(float health_);
	float getHealth() const;
	bool setInvulnerable(bool invulnerable_);
	bool isInvulnerable() const;

private:
	int32_t _id;
};

}