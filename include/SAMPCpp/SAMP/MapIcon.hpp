#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

namespace samp_cpp
{
	
class Player;

struct MapIcon
{
	/////////////////////////////
	enum Style : int
	{
		Local				= 0,
		Global				= 1,
		LocalCheckpoint		= 2,
		GlobalCheckpoint	= 3
	};

	enum Type : int
	{
		// convert table below to enum values
		ColoredSquareOrTriangle	= 0,
		WhiteSquare				= 1,
		PlayerPosition			= 2,
		PlayerMenuMap			= 3,
		North					= 4,
		AirYard					= 5,
		AmmuNation				= 6,
		Barbers					= 7,
		BigSmoke				= 8,
		BoatYard				= 9,
		BurgerShot				= 10,
		Quarry					= 11,
		Catalina				= 12,
		Cesar					= 13,
		CluckinBell				= 14,
		CarlJohnson				= 15,
		CRASH					= 16,
		Diner					= 17,
		Emmet					= 18,
		EnemyAttack				= 19,
		Fire					= 20,
		Girlfriend				= 21,
		Hospital				= 22,
		Loco					= 23,
		MaddDogg				= 24,
		Caligulas				= 25,
		MCStrap					= 26,
		ModGarage				= 27,
		OGLoc					= 28,
		WellStackedPizzaCo		= 29,
		Police					= 30,
		PropertyForSale			= 31,
		PropertyNotForSale		= 32,
		Race					= 33,
		Ryder					= 34,
		SaveHouse				= 35,
		School					= 36,
		Mystery					= 37,
		Sweet					= 38,
		Tattoo					= 39,
		TheTruth				= 40,
		Waypoint				= 41,
		TorenosRanch			= 42,
		Triads					= 43,
		TriadsCasino			= 44,
		ClothesShop				= 45,
		Woozie					= 46,
		Zero					= 47,
		DiscoDate				= 48,
		DrinkingDate			= 49,
		Restaurant				= 50,
		Trucking				= 51,
		Robbery					= 52,
		RaceTournament			= 53,
		Gym						= 54,
		CarImpound				= 55,
		Light					= 56,
		NearestAirStrip			= 57,
		VarriosLosAztecas		= 58,
		Ballas					= 59,
		LosSantosVagos			= 60,
		SanFierroRifa			= 61,
		GroveStreetFamilies		= 62,
		PayNSpray				= 63,
	};

	MapIcon() = default;
	MapIcon(Player player_, int32_t id_);

	static MapIcon create(int32_t iconIdx_, Player player_, Type type_, Vec3f const& pos_, Color color_, Style style_ = Style::Local);
	static MapIcon create(int32_t iconIdx_, Player player_, Type type_, float x_, float y_, float z_, Color color_, Style style_ = Style::Local);

	bool operator==(MapIcon const& other_) const { return (_playerId == other_._playerId && _id == other_._id); }
	bool operator!=(MapIcon const& other_) const { return !(*this == other_); }

	bool valid() const {
		return _playerId != -1 && _id != -1;
	}
	
	bool destroy();

private:
	int32_t _playerId	= -1;
	int32_t _id			= -1;
};


using MapIconType	= MapIcon::Type;
using MapIconStyle	= MapIcon::Style;

} // namespace samp_cpp
