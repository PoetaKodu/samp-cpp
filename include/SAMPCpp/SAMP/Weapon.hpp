#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

struct Weapon
{
	enum Type
	{
		None 				= 0,
		BrassKnuckle		= 1,
		GolfClub 			= 2,
		Nitestick 			= 3,
		Knife 				= 4,
		Bat 				= 5,
		Shovel 				= 6,
		PoolStick 			= 7,
		Katana 				= 8,
		Chainsaw 			= 9,
		Dildo 				= 10,
		Dildo2 				= 11,
		Vibrator 			= 12,
		Vibrator2 			= 13,
		Flower 				= 14,
		Cane 				= 15,
		Grenade 			= 16,
		Teargas 			= 17,
		Moltov 				= 18,
		Colt45 				= 22,
		Silenced 			= 23,
		Deagle 				= 24,
		Shotgun 			= 25,
		Sawedoff 			= 26,
		Shotgspa 			= 27,
		Uzi 				= 28,
		Mp5 				= 29,
		Ak47 				= 30,
		M4 					= 31,
		Tec9 				= 32,
		Rifle 				= 33,
		Sniper 				= 34,
		RocketLauncher 		= 35,
		Heatseeker 			= 36,
		Flamethrower 		= 37,
		Minigun 			= 38,
		Satchel 			= 39,
		Bomb 				= 40,
		SprayCan 			= 41,
		FireExtinguisher 	= 42,
		Camera 				= 43,
		Parachute 			= 46,
		Vehicle 			= 49,
		Drown 				= 53,
		Collision 			= 54,
	};

	Weapon() = default;
	Weapon(Type type_, int32_t ammo_ = 1)
		: id(type_),
		ammo(ammo_)
	{
	}
	
	Type id 		= Weapon::None;
	int32_t ammo 	= 1;
};

}