#include SAMPCPP_PCH

#include <SAMPCpp/Server.hpp>

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
int32_t addPlayerClass(int modelid, math::Vector3f const& spawnPos_, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
	return addPlayerClass(modelid, spawnPos_.x, spawnPos_.y, spawnPos_.z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
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