#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class StaticPickup final
{
public:
	static bool add(int modelIdx_, int type_, Vec3f const& pos_, int virtualWorld_);
	static bool add(int modelIdx_, int type_, float x_, float y_, float z_, int virtualWorld_);
};

class Pickup
{
public:

	/// Types of pickups
	/// Most other IDs are either undocumented or are similar to type 1 (but do not use them just because they seem similar to ID 1, they might have side-effects like ID 18 and 20).
	/// Source: https://sampwiki.blast.hk/wiki/PickupTypes
	enum Type
	{
		Type_0 			= 0, 			// The pickup does not always display. If displayed, it can't be picked up and does not trigger OnPlayerPickUpPickup and it will stay after server shutdown.
		Type_1 			= 1, 			// Exists always. Disables pickup scripts such as horseshoes and oysters to allow for scripted actions ONLY. Will trigger OnPlayerPickUpPickup every few seconds.
		Type_2 			= 2, 			// Disappears after pickup, respawns after 30 seconds if the player is at a distance of at least 15 meters.
		Type_3 			= 3, 			// Disappears after pickup, respawns after death.
		Type_4 			= 4, 			// Disappears after 15 to 20 seconds. Respawns after death.
		Type_8 			= 8, 			// Disappears after pickup, but has no effect.
		Type_11 		= 11, 			// Blows up a few seconds after being created (bombs?)
		Type_12 		= 12, 			// Blows up a few seconds after being created.
		Type_13 		= 13, 			// Invisible. Triggers checkpoint sound when picked up with a vehicle, but doesn't trigger OnPlayerPickUpPickup.
		Type_14 		= 14, 			// Disappears after pickup, can only be picked up with a vehicle. Triggers checkpoint sound.
		Type_15 		= 15, 			// Same as type 2.
		Type_18 		= 18, 			// Similar to type 1. Pressing Tab (KEY_ACTION) makes it disappear but the key press doesn't trigger OnPlayerPickUpPickup.
		Type_19 		= 19, 			// Disappears after pickup, but doesn't respawn. Makes "cash pickup" sound if picked up.
		Type_20 		= 20, 			// Similar to type 1. Disappears when you take a picture of it with the Camera weapon, which triggers "Snapshot # out of 0" message. Taking a picture doesn't trigger OnPlayerPickUpPickup.
		Type_22 		= 22, 			// Same as type 3.

		// Useful aliases
		Trigger 			= Type_1, 	// (ALIAS FOR TYPE 1) Exists always. Disables pickup scripts such as horseshoes and oysters to allow for scripted actions ONLY. Will trigger OnPlayerPickUpPickup every few seconds.
		Respawn30s 			= Type_2, 	// (ALIAS FOR TYPE 2) Disappears after pickup, respawns after 30 seconds if the player is at a distance of at least 15 meters.
		RespawnDeath 		= Type_3, 	// (ALIAS FOR TYPE 3) Disappears after pickup, respawns after death.
		BlowUp 				= Type_11, 	// (ALIAS FOR TYPE 11) Blows up a few seconds after being created (bombs?)
		CheckpointSound 	= Type_13, 	// (ALIAS FOR TYPE 13) Invisible. Triggers checkpoint sound when picked up with a vehicle, but doesn't trigger OnPlayerPickUpPickup.
		VehicleCheckpoint 	= Type_14, 	// (ALIAS FOR TYPE 14) Disappears after pickup, can only be picked up with a vehicle. Triggers checkpoint sound.
		Cash 				= Type_19, 	// (ALIAS FOR TYPE 19) Disappears after pickup, but doesn't respawn. Makes "cash pickup" sound if picked up.
		Snapshot 			= Type_19, 	// (ALIAS FOR TYPE 20) Similar to type 1. Disappears when you take a picture of it with the Camera weapon, which triggers "Snapshot # out of 0" message. Taking a picture doesn't trigger OnPlayerPickUpPickup.
	};

	Pickup() = default;
	Pickup(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(Pickup const& other_) const { return _id == other_._id; }
	bool operator!=(Pickup const& other_) const { return !(*this == other_); }

	int32_t id() const { return _id; }

	static Pickup create(int modelIdx_, Type type_, Vec3f const& pos_, int virtualWorld_);
	static Pickup create(int modelIdx_, Type type_, float x_, float y_, float z_, int virtualWorld_);
	bool destroy();

private:
	int32_t _id = -1;
};

using PickupType = Pickup::Type;

}