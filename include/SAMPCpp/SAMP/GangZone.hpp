#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

namespace samp_cpp
{

class Player;

class GangZone
{
public:
	GangZone(int32_t id_)
		: _id(id_)
	{
	}

	static GangZone create(Vec2f const& min_, Vec2f const& max_);
	static GangZone create(float minX_, float minY_, float maxX_, float maxY_);
	bool destroy(int zone_);
	bool showForPlayer(Player player_, Color color_);
	bool showForAll(Color color_);
	bool hideForPlayer(Player player_);
	bool hideForAll();
	bool flashForPlayer(Player player_, Color flashColor_);
	bool flashForAll(Color flashColor_);
	bool stopFlashForPlayer(Player player_);
	bool stopFlashForAll();

private:
	int32_t _id;
};


}