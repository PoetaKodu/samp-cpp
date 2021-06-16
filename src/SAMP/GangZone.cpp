#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/GangZone.hpp>

#include <SAMPCpp/SAMP/Player.hpp>


namespace samp_cpp
{


///////////////////////////////////////////////
GangZone GangZone::create(Vec2f const& min_, Vec2f const& max_)
{
	return GangZone::create(min_.x, min_.y, max_.x, max_.y);
}

///////////////////////////////////////////////
GangZone GangZone::create(float minX_, float minY_, float maxX_, float maxY_)
{
	return GangZone{ sampgdk_GangZoneCreate(minX_, minY_, maxX_, maxY_) };
}

///////////////////////////////////////////////
bool GangZone::destroy(int zone_)
{
	return sampgdk_GangZoneDestroy(zone_);
}

///////////////////////////////////////////////
bool GangZone::showForPlayer(Player player_, Color color_)
{
	return sampgdk_GangZoneShowForPlayer(player_.id(), _id, color_);
}

///////////////////////////////////////////////
bool GangZone::showForAll(Color color_)
{
	return sampgdk_GangZoneShowForAll(_id, color_);
}

///////////////////////////////////////////////
bool GangZone::hideForPlayer(Player player_)
{
	return sampgdk_GangZoneHideForPlayer(player_.id(), _id);
}

///////////////////////////////////////////////
bool GangZone::hideForAll()
{
	return sampgdk_GangZoneHideForAll(_id);
}

///////////////////////////////////////////////
bool GangZone::flashForPlayer(Player player_, Color flashColor_)
{
	return sampgdk_GangZoneFlashForPlayer(player_.id(), _id, flashColor_);
}

///////////////////////////////////////////////
bool GangZone::flashForAll(Color flashColor_)
{
	return sampgdk_GangZoneFlashForAll(_id, flashColor_);
}

///////////////////////////////////////////////
bool GangZone::stopFlashForPlayer(Player player_)
{
	return sampgdk_GangZoneStopFlashForPlayer(player_.id(), _id);
}

///////////////////////////////////////////////
bool GangZone::stopFlashForAll()
{
	return sampgdk_GangZoneStopFlashForAll(_id);
}

}