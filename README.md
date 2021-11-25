# samp-cpp

A SAMP C++ extension of SAMPGDK.

## 🚀 Installation

This library uses [pacc](https://github.com/PoetaKodu/pacc) package manager.

1. Download pacc
2. Add `github:PoetaKodu/samp-cpp@0.1.0` as a [dependency](https://github.com/PoetaKodu/pacc/blob/main/docs/GettingStarted.md#dependency-handling) to your project
3. Type `pacc install`

Done.
## 👀 Overview

Spawning vehicle example:

```pawn
spawnVehicleFor(playerid, modelid)
{
	if (IsPlayerInAnyVehicle(playerid))
	{
		DestroyVehicle(GetPlayerVehicleID(playerid));
	}

	new Float:pos[3];
	new Float:rot;

	GetPlayerPos(playerid, pos[0], pos[1], pos[2]);
	GetPlayerFacingAngle(playerid, rot);

	new vehid = CreateVehicle(modelid, pos[0], pos[1], pos[2], rot, 3, 4, 5000);

	PutPlayerInVehicle(playerid, vehid, 0);
}
```

C++ version using this library:

```cpp
void spawnVehicleFor(Player player, Vehicle::Model model)
{
	if (player.isInAnyVehicle())
		player.getVehicle().destroy();

	auto veh = Vehicle::create(model, player.pos(), player.rot(), 3, 4, 5000);

	player.putInVehicle(veh, 0);
}
```