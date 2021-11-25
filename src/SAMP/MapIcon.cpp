#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Player.hpp>
#include <SAMPCpp/SAMP/MapIcon.hpp>

namespace samp_cpp
{

///////////////////////////////////
MapIcon::MapIcon(Player player_, int32_t id_)
	: _playerId{ player_.id() }
	, _id{ id_ }
{
}

///////////////////////////////////
bool MapIcon::destroy()
{
	return sampgdk_RemovePlayerMapIcon(_playerId, _id);
}

///////////////////////////////////
MapIcon MapIcon::create(int32_t iconIdx_, Player player_, Type type_, Vec3f const& pos_, Color color_, Style style_)
{
	return MapIcon::create(iconIdx_, player_, type_, pos_.x, pos_.y, pos_.z, color_, style_);
}

///////////////////////////////////
MapIcon MapIcon::create(int32_t iconIdx_, Player player_, Type type_, float x_, float y_, float z_, Color color_, Style style_)
{
	sampgdk_SetPlayerMapIcon(player_.id(), iconIdx_, x_, y_, z_, color_, static_cast<int>(type_), static_cast<int>(style_));
	return MapIcon{ player_, iconIdx_ };
}

}