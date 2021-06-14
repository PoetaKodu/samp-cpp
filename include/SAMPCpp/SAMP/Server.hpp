#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Weapon.hpp>
namespace samp_cpp
{

namespace server
{

int32_t getTickCount();


int32_t addPlayerClass(int modelIdx_, Vec3f const& spawnPos_, float rotation_, Weapon weapons_[3]);
int32_t addPlayerClass(int modelIdx_, Vec3f const& spawnPos_, float rotation_, Weapon weapon1_ = {}, Weapon weapon2_ = {}, Weapon weapon3_ = {});

int32_t addPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);

int32_t setTimer(int interval_, bool repeat_, TimerCallback callback_, void * param_);

}

}