#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Server.hpp>

namespace samp_cpp
{
	
namespace server
{
	
/////////////////////////////////////////////////
int32_t getTickCount()
{
	return sampgdk_GetTickCount();
}

/////////////////////////////////////////////////
int32_t addPlayerClass(int modelIdx_, Vec3f const& spawnPos_, float rotation_, Weapon weapons_[3])
{
	return addPlayerClass(modelIdx_, 
			spawnPos_.x, spawnPos_.y, spawnPos_.z, rotation_,
			weapons_[0].id, weapons_[0].ammo,
			weapons_[1].id, weapons_[1].ammo,
			weapons_[2].id, weapons_[2].ammo
		);
}

/////////////////////////////////////////////////
int32_t addPlayerClass(int modelIdx_, Vec3f const& spawnPos_, float rotation_, Weapon weapon1_, Weapon weapon2_, Weapon weapon3_)
{
	return addPlayerClass(modelIdx_, 
			spawnPos_.x, spawnPos_.y, spawnPos_.z, rotation_,
			weapon1_.id, weapon1_.ammo,
			weapon2_.id, weapon2_.ammo,
			weapon3_.id, weapon3_.ammo
		);
}

/////////////////////////////////////////////////
int32_t addPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
	return sampgdk_AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

/////////////////////////////////////////////////
int32_t setTimer(int interval_, bool repeat_, TimerCallback callback_, void * param_)
{
	return sampgdk_SetTimer(interval_, repeat_, callback_, param_);
}

}

}