#pragma once

#include SAMPCPP_PCH

// TODO: move this to .cpp file
#include <SAMPCpp/SAMP/Player.hpp>
#include <SAMPCpp/SAMP/Actor.hpp>
#include <SAMPCpp/SAMP/Vehicle.hpp>
#include <SAMPCpp/SAMP/Object.hpp>
#include <SAMPCpp/SAMP/PlayerObject.hpp>
#include <SAMPCpp/SAMP/Weapon.hpp>

namespace samp_cpp
{

// class Player;
// class Actor;
// class Vehicle;
// class Object;
// class PlayerObject;

constexpr const uint32_t 	MaxPlayerName		= 24;
constexpr const uint32_t 	MaxClientMessage	= 144;
constexpr const uint32_t 	MaxPlayers			= 1000;
constexpr const uint32_t 	MaxVehicles			= 2000;
constexpr const uint32_t 	MaxActors			= 1000;
constexpr const int32_t 	InvalidPlayerId		= 0xFFFF;
constexpr const int32_t 	InvalidVehicleId	= 0xFFFF;
constexpr const int32_t 	InvalidActorId		= 0xFFFF;
constexpr const int32_t 	NoTeam				= 255;
constexpr const uint32_t	MaxObjects			= 1000;
constexpr const int32_t		InvalidObjectId		= 0xFFFF;
constexpr const uint32_t	MaxGangZones		= 1024;
constexpr const uint32_t	MaxTextDraws		= 2048;
constexpr const uint32_t	MaxPlayerTextDraws	= 256;
constexpr const uint32_t	MaxMenus			= 128;
constexpr const uint32_t	Max3DTextGlobal		= 1024;
constexpr const uint32_t	Max3DTextPlayer		= 1024;
constexpr const uint32_t	MaxPickups			= 4096;
constexpr const int32_t		InvalidMenu			= 0xFF;
constexpr const int32_t		InvalidTextDraw		= 0xFFFF;
constexpr const int32_t		InvalidGangZone		= -1;
constexpr const int32_t		Invalid3DTextId		= 0xFFFF;


enum class ServerValType
{
	None	= 0,
	Int		= 1,
	String	= 2,
	Float	= 3,
};

enum class TextDrawFontType
{
	SpriteDraw		= 4,
	ModelPreview	= 5,
};

enum class DialogStyle
{
	MessageBox		= 0,
	Input			= 1,
	List			= 2,
	Password		= 3,
	TabList			= 4,
	TabListHeaders	= 5,
};


enum class PlayerMarkersMode
{
	Off			= 0,
	Global		= 1,
	Streamed	= 2,
};

namespace GameKey
{
	enum Key : int32_t
	{
		Action				= 1,
		Crouch				= 2,
		Fire				= 4,
		Sprint				= 8,
		SecondaryAttack		= 16,
		Jump				= 32,
		LookRight			= 64,
		Handbrake			= 128,
		LookLeft			= 256,
		Submission			= 512,
		LookBehind			= 512,
		Walk				= 1024,
		AnalogUp			= 2048,
		AnalogDown			= 4096,
		AnalogLeft			= 8192,
		AnalogRight			= 16384,
		Yes					= 65536,
		No					= 131072,
		CtrlBack			= 262144,
		Up					= -128,
		Down				= 128,
		Left				= -128,
		Right				= 128,
	};
};

enum class BodyPart
{
	Torso		= 3,
	Groin		= 4,
	LeftArm		= 5,
	RightArm	= 6,
	LeftLeg		= 7,
	RightLeg	= 8,
	Head		= 9,
};

enum class ClickSource
{
	Scoreboard	= 0,
};

enum class EditResponse
{
	Cancel		= 0,
	Final		= 1,
	Update		= 2,
};

enum class SelectObjectChoice
{
	None		= 0,
	Global		= 1,
	Player		= 2
};

enum class BulletHitType
{
	None			= 0,
	Player			= 1,
	Vehicle			= 2,
	Object			= 3,
	PlayerObject	= 4,
};

enum class DownloadRequest
{
	Empty			= 0,
	ModelFile		= 1,
	TextureFile		= 2,
};

enum class ObjectMaterialSize
{
	Size_32x32		= 10,
	Size_64x32		= 20,
	Size_64x64		= 30,
	Size_128x32		= 40,
	Size_128x64		= 50,
	Size_128x128	= 60,
	Size_256x32		= 70,
	Size_256x64		= 80,
	Size_256x128	= 90,
	Size_256x256	= 100,
	Size_512x64		= 110,
	Size_512x128	= 120,
	Size_512x256	= 130,
	Size_512x512	= 140,
};

enum class ObjectMaterialTextAlign
{
	Left		= 0,
	Center		= 1,
	Right		= 2,
};


bool sendClientMessage(Player player_, int color, const char * message)
{
	return sampgdk_SendClientMessage(player_.id(), color, message);
}

bool sendClientMessageToAll(int color, const char * message)
{
	return sampgdk_SendClientMessageToAll(color, message);
}

bool sendPlayerMessageToPlayer(Player player_, Player sender_, const char * message)
{
	return sampgdk_SendPlayerMessageToPlayer(player_.id(), sender_.id(), message);
}

bool sendPlayerMessageToAll(Player sender_, const char * message)
{
	return sampgdk_SendPlayerMessageToAll(sender_.id(), message);
}

bool sendDeathMessage(Player killer_, Player killee_, Weapon::Type weapon_)
{
	return sampgdk_SendDeathMessage(killer_.id(), killee_.id(), static_cast<int>(weapon_));
}

bool sendDeathMessageToPlayer(Player player_, Player killer_, Player killee_, Weapon::Type weapon_)
{
	return sampgdk_SendDeathMessageToPlayer(player_.id(), killer_.id(), killee_.id(), static_cast<int>(weapon_));
}

bool gameTextForAll(const char * text, int time, int style)
{
	return sampgdk_GameTextForAll(text, time, style);
}

bool gameTextForPlayer(Player player_, const char * text, int time, int style)
{
	return sampgdk_GameTextForPlayer(player_.id(), text, time, style);
}

int getTickCount()
{
	return sampgdk_GetTickCount();
}

int getMaxPlayers()
{
	return sampgdk_GetMaxPlayers();
}

int getPlayerPoolSize()
{
	return sampgdk_GetPlayerPoolSize();
}

int getVehiclePoolSize()
{
	return sampgdk_GetVehiclePoolSize();
}

int getActorPoolSize()
{
	return sampgdk_GetActorPoolSize();
}

bool sha256PassHash(const char * password, const char * salt, char * ret_hash, int ret_hash_len)
{
	return sampgdk_SHA256_PassHash(password, salt, ret_hash, ret_hash_len);
}

bool setSVarInt(const char * varname, int int_value)
{
	return sampgdk_SetSVarInt(varname, int_value);
}

int getSVarInt(const char * varname)
{
	return sampgdk_GetSVarInt(varname);
}

bool setSVarString(const char * varname, const char * string_value)
{
	return sampgdk_SetSVarString(varname, string_value);
}

bool getSVarString(const char * varname, char * string_return, int len)
{
	return sampgdk_GetSVarString(varname, string_return, len);
}

bool setSVarFloat(const char * varname, float float_value)
{
	return sampgdk_SetSVarFloat(varname, float_value);
}

float getSVarFloat(const char * varname)
{
	return sampgdk_GetSVarFloat(varname);
}

bool deleteSVar(const char * varname)
{
	return sampgdk_DeleteSVar(varname);
}

int getSVarsUpperIndex()
{
	return sampgdk_GetSVarsUpperIndex();
}

bool getSVarNameAtIndex(int index, char * ret_varname, int ret_len)
{
	return sampgdk_GetSVarNameAtIndex(index, ret_varname, ret_len);
}

int getSVarType(const char * varname)
{
	return sampgdk_GetSVarType(varname);
}

bool setGameModeText(const char * text)
{
	return sampgdk_SetGameModeText(text);
}

bool setTeamCount(int count)
{
	return sampgdk_SetTeamCount(count);
}

int addPlayerClass(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
	return sampgdk_AddPlayerClass(modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

int addPlayerClassEx(int teamid, int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo)
{
	return sampgdk_AddPlayerClassEx(teamid, modelid, spawn_x, spawn_y, spawn_z, z_angle, weapon1, weapon1_ammo, weapon2, weapon2_ammo, weapon3, weapon3_ammo);
}

int addStaticVehicle(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2)
{
	return sampgdk_AddStaticVehicle(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2);
}

int addStaticVehicleEx(int modelid, float spawn_x, float spawn_y, float spawn_z, float z_angle, int color1, int color2, int respawn_delay, bool addsiren)
{
	return sampgdk_AddStaticVehicleEx(modelid, spawn_x, spawn_y, spawn_z, z_angle, color1, color2, respawn_delay, addsiren);
}

int addStaticPickup(int model, int type, float x, float y, float z, int virtualworld)
{
	return sampgdk_AddStaticPickup(model, type, x, y, z, virtualworld);
}

int createPickup(int model, int type, float x, float y, float z, int virtualworld)
{
	return sampgdk_CreatePickup(model, type, x, y, z, virtualworld);
}

bool destroyPickup(int pickup)
{
	return sampgdk_DestroyPickup(pickup);
}

bool showNameTags(bool show)
{
	return sampgdk_ShowNameTags(show);
}

bool showPlayerMarkers(int mode)
{
	return sampgdk_ShowPlayerMarkers(mode);
}

bool gameModeExit()
{
	return sampgdk_GameModeExit();
}

bool setWorldTime(int hour)
{
	return sampgdk_SetWorldTime(hour);
}

bool getWeaponName(int weaponid, char * name, int size)
{
	return sampgdk_GetWeaponName(weaponid, name, size);
}

bool enableTirePopping(bool enable)
{
	return sampgdk_EnableTirePopping(enable);
}

bool enableVehicleFriendlyFire()
{
	return sampgdk_EnableVehicleFriendlyFire();
}

bool allowInteriorWeapons(bool allow)
{
	return sampgdk_AllowInteriorWeapons(allow);
}

bool setWeather(int weatherid)
{
	return sampgdk_SetWeather(weatherid);
}

bool setGravity(float gravity)
{
	return sampgdk_SetGravity(gravity);
}

float getGravity()
{
	return sampgdk_GetGravity();
}

bool allowAdminTeleport(bool allow)
{
	return sampgdk_AllowAdminTeleport(allow);
}

bool setDeathDropAmount(int amount)
{
	return sampgdk_SetDeathDropAmount(amount);
}

bool createExplosion(float x, float y, float z, int type, float radius)
{
	return sampgdk_CreateExplosion(x, y, z, type, radius);
}

bool enableZoneNames(bool enable)
{
	return sampgdk_EnableZoneNames(enable);
}

bool usePlayerPedAnims()
{
	return sampgdk_UsePlayerPedAnims();
}

bool disableInteriorEnterExits()
{
	return sampgdk_DisableInteriorEnterExits();
}

bool setNameTagDrawDistance(float distance)
{
	return sampgdk_SetNameTagDrawDistance(distance);
}

bool disableNameTagLos()
{
	return sampgdk_DisableNameTagLOS();
}

bool limitGlobalChatRadius(float chat_radius)
{
	return sampgdk_LimitGlobalChatRadius(chat_radius);
}

bool limitPlayerMarkerRadius(float marker_radius)
{
	return sampgdk_LimitPlayerMarkerRadius(marker_radius);
}

bool connectNpc(const char * name, const char * script)
{
	return sampgdk_ConnectNPC(name, script);
}

bool isPlayerNpc(Player player_)
{
	return sampgdk_IsPlayerNPC(player_.id());
}

bool isPlayerAdmin(Player player_)
{
	return sampgdk_IsPlayerAdmin(player_.id());
}

bool kick(Player player_)
{
	return sampgdk_Kick(player_.id());
}

bool ban(Player player_)
{
	return sampgdk_Ban(player_.id());
}

bool banEx(Player player_, const char * reason)
{
	return sampgdk_BanEx(player_.id(), reason);
}

bool sendRconCommand(const char * command)
{
	return sampgdk_SendRconCommand(command);
}

bool getPlayerNetworkStats(Player player_, char * retstr, int size)
{
	return sampgdk_GetPlayerNetworkStats(player_.id(), retstr, size);
}

bool getNetworkStats(char * retstr, int size)
{
	return sampgdk_GetNetworkStats(retstr, size);
}

bool getPlayerVersion(Player player_, char * version, int len)
{
	return sampgdk_GetPlayerVersion(player_.id(), version, len);
}

bool blockIpAddress(const char * ip_address, int timems)
{
	return sampgdk_BlockIpAddress(ip_address, timems);
}

bool unBlockIpAddress(const char * ip_address)
{
	return sampgdk_UnBlockIpAddress(ip_address);
}

bool getServerVarAsString(const char * varname, char * value, int size)
{
	return sampgdk_GetServerVarAsString(varname, value, size);
}

int getServerVarAsInt(const char * varname)
{
	return sampgdk_GetServerVarAsInt(varname);
}

bool getServerVarAsBool(const char * varname)
{
	return sampgdk_GetServerVarAsBool(varname);
}

bool getConsoleVarAsString(const char * varname, char * buffer, int len)
{
	return sampgdk_GetConsoleVarAsString(varname, buffer, len);
}

int getConsoleVarAsInt(const char * varname)
{
	return sampgdk_GetConsoleVarAsInt(varname);
}

bool getConsoleVarAsBool(const char * varname)
{
	return sampgdk_GetConsoleVarAsBool(varname);
}

int getServerTickRate()
{
	return sampgdk_GetServerTickRate();
}

int netStatsGetConnectedTime(Player player_)
{
	return sampgdk_NetStats_GetConnectedTime(player_.id());
}

int netStatsMessagesReceived(Player player_)
{
	return sampgdk_NetStats_MessagesReceived(player_.id());
}

int netStatsBytesReceived(Player player_)
{
	return sampgdk_NetStats_BytesReceived(player_.id());
}

int netStatsMessagesSent(Player player_)
{
	return sampgdk_NetStats_MessagesSent(player_.id());
}

int netStatsBytesSent(Player player_)
{
	return sampgdk_NetStats_BytesSent(player_.id());
}

int netStatsMessagesRecvPerSecond(Player player_)
{
	return sampgdk_NetStats_MessagesRecvPerSecond(player_.id());
}

float netStatsPacketLossPercent(Player player_)
{
	return sampgdk_NetStats_PacketLossPercent(player_.id());
}

int netStatsConnectionStatus(Player player_)
{
	return sampgdk_NetStats_ConnectionStatus(player_.id());
}

bool netStatsGetIpPort(Player player_, char * ip_port, int ip_port_len)
{
	return sampgdk_NetStats_GetIpPort(player_.id(), ip_port, ip_port_len);
}

int createMenu(const char * title, int columns, float x, float y, float col1width, float col2width)
{
	return sampgdk_CreateMenu(title, columns, x, y, col1width, col2width);
}

bool destroyMenu(int menuid)
{
	return sampgdk_DestroyMenu(menuid);
}

int addMenuItem(int menuid, int column, const char * menutext)
{
	return sampgdk_AddMenuItem(menuid, column, menutext);
}

bool setMenuColumnHeader(int menuid, int column, const char * columnheader)
{
	return sampgdk_SetMenuColumnHeader(menuid, column, columnheader);
}

bool showMenuForPlayer(int menuid, Player player_)
{
	return sampgdk_ShowMenuForPlayer(menuid, player_.id());
}

bool hideMenuForPlayer(int menuid, Player player_)
{
	return sampgdk_HideMenuForPlayer(menuid, player_.id());
}

bool isValidMenu(int menuid)
{
	return sampgdk_IsValidMenu(menuid);
}

bool disableMenu(int menuid)
{
	return sampgdk_DisableMenu(menuid);
}

bool disableMenuRow(int menuid, int row)
{
	return sampgdk_DisableMenuRow(menuid, row);
}

int getPlayerMenu(Player player_)
{
	return sampgdk_GetPlayerMenu(player_.id());
}

int textDrawCreate(float x, float y, const char * text)
{
	return sampgdk_TextDrawCreate(x, y, text);
}

bool textDrawDestroy(int text)
{
	return sampgdk_TextDrawDestroy(text);
}

bool textDrawLetterSize(int text, float x, float y)
{
	return sampgdk_TextDrawLetterSize(text, x, y);
}

bool textDrawTextSize(int text, float x, float y)
{
	return sampgdk_TextDrawTextSize(text, x, y);
}

bool textDrawAlignment(int text, int alignment)
{
	return sampgdk_TextDrawAlignment(text, alignment);
}

bool textDrawColor(int text, int color)
{
	return sampgdk_TextDrawColor(text, color);
}

bool textDrawUseBox(int text, bool use)
{
	return sampgdk_TextDrawUseBox(text, use);
}

bool textDrawBoxColor(int text, int color)
{
	return sampgdk_TextDrawBoxColor(text, color);
}

bool textDrawSetShadow(int text, int size)
{
	return sampgdk_TextDrawSetShadow(text, size);
}

bool textDrawSetOutline(int text, int size)
{
	return sampgdk_TextDrawSetOutline(text, size);
}

bool textDrawBackgroundColor(int text, int color)
{
	return sampgdk_TextDrawBackgroundColor(text, color);
}

bool textDrawFont(int text, int font)
{
	return sampgdk_TextDrawFont(text, font);
}

bool textDrawSetProportional(int text, bool set)
{
	return sampgdk_TextDrawSetProportional(text, set);
}

bool textDrawSetSelectable(int text, bool set)
{
	return sampgdk_TextDrawSetSelectable(text, set);
}

bool textDrawShowForPlayer(Player player_, int text)
{
	return sampgdk_TextDrawShowForPlayer(player_.id(), text);
}

bool textDrawHideForPlayer(Player player_, int text)
{
	return sampgdk_TextDrawHideForPlayer(player_.id(), text);
}

bool textDrawShowForAll(int text)
{
	return sampgdk_TextDrawShowForAll(text);
}

bool textDrawHideForAll(int text)
{
	return sampgdk_TextDrawHideForAll(text);
}

bool textDrawSetString(int text, const char * string)
{
	return sampgdk_TextDrawSetString(text, string);
}

bool textDrawSetPreviewModel(int text, int modelindex)
{
	return sampgdk_TextDrawSetPreviewModel(text, modelindex);
}

bool textDrawSetPreviewRot(int text, float fRotX, float fRotY, float fRotZ, float fZoom)
{
	return sampgdk_TextDrawSetPreviewRot(text, fRotX, fRotY, fRotZ, fZoom);
}

bool textDrawSetPreviewVehCol(int text, int color1, int color2)
{
	return sampgdk_TextDrawSetPreviewVehCol(text, color1, color2);
}

bool selectTextDraw(Player player_, int hovercolor)
{
	return sampgdk_SelectTextDraw(player_.id(), hovercolor);
}

bool cancelSelectTextDraw(Player player_)
{
	return sampgdk_CancelSelectTextDraw(player_.id());
}

int gangZoneCreate(float minx, float miny, float maxx, float maxy)
{
	return sampgdk_GangZoneCreate(minx, miny, maxx, maxy);
}

bool gangZoneDestroy(int zone)
{
	return sampgdk_GangZoneDestroy(zone);
}

bool gangZoneShowForPlayer(Player player_, int zone, int color)
{
	return sampgdk_GangZoneShowForPlayer(player_.id(), zone, color);
}

bool gangZoneShowForAll(int zone, int color)
{
	return sampgdk_GangZoneShowForAll(zone, color);
}

bool gangZoneHideForPlayer(Player player_, int zone)
{
	return sampgdk_GangZoneHideForPlayer(player_.id(), zone);
}

bool gangZoneHideForAll(int zone)
{
	return sampgdk_GangZoneHideForAll(zone);
}

bool gangZoneFlashForPlayer(Player player_, int zone, int flashcolor)
{
	return sampgdk_GangZoneFlashForPlayer(player_.id(), zone, flashcolor);
}

bool gangZoneFlashForAll(int zone, int flashcolor)
{
	return sampgdk_GangZoneFlashForAll(zone, flashcolor);
}

bool gangZoneStopFlashForPlayer(Player player_, int zone)
{
	return sampgdk_GangZoneStopFlashForPlayer(player_.id(), zone);
}

bool gangZoneStopFlashForAll(int zone)
{
	return sampgdk_GangZoneStopFlashForAll(zone);
}

int create3DTextLabel(const char * text, int color, float x, float y, float z, float DrawDistance, int virtualworld, bool testLOS)
{
	return sampgdk_Create3DTextLabel(text, color, x, y, z, DrawDistance, virtualworld, testLOS);
}

bool delete3DTextLabel(int id)
{
	return sampgdk_Delete3DTextLabel(id);
}

bool attach3DTextLabelToPlayer(int id, Player player_, float OffsetX, float OffsetY, float OffsetZ)
{
	return sampgdk_Attach3DTextLabelToPlayer(id, player_.id(), OffsetX, OffsetY, OffsetZ);
}

bool attach3DTextLabelToVehicle(int id, int vehicleid, float OffsetX, float OffsetY, float OffsetZ)
{
	return sampgdk_Attach3DTextLabelToVehicle(id, vehicleid, OffsetX, OffsetY, OffsetZ);
}

bool update3DTextLabelText(int id, int color, const char * text)
{
	return sampgdk_Update3DTextLabelText(id, color, text);
}

int createPlayer3DTextLabel(Player player_, const char * text, int color, float x, float y, float z, float DrawDistance, int attachedplayer, int attachedvehicle, bool testLOS)
{
	return sampgdk_CreatePlayer3DTextLabel(player_.id(), text, color, x, y, z, DrawDistance, attachedplayer, attachedvehicle, testLOS);
}

bool deletePlayer3DTextLabel(Player player_, int id)
{
	return sampgdk_DeletePlayer3DTextLabel(player_.id(), id);
}

bool updatePlayer3DTextLabelText(Player player_, int id, int color, const char * text)
{
	return sampgdk_UpdatePlayer3DTextLabelText(player_.id(), id, color, text);
}

bool showPlayerDialog(Player player_, int dialogid, int style, const char * caption, const char * info, const char * button1, const char * button2)
{
	return sampgdk_ShowPlayerDialog(player_.id(), dialogid, style, caption, info, button1, button2);
}

int setTimer(int interval, bool repeat, TimerCallback callback, void * param)
{
	return sampgdk_SetTimer(interval, repeat, callback, param);
}

bool killTimer(int timerid)
{
	return sampgdk_KillTimer(timerid);
}

bool gpci(Player player_, char * buffer, int size)
{
	return sampgdk_gpci(player_.id(), buffer, size);
}

int addCharModel(int baseid, int newid, const char * dffname, const char * txdname)
{
	return sampgdk_AddCharModel(baseid, newid, dffname, txdname);
}

int addSimpleModel(int virtualworld, int baseid, int newid, const char * dffname, const char * txdname)
{
	return sampgdk_AddSimpleModel(virtualworld, baseid, newid, dffname, txdname);
}

int addSimpleModelTimed(int virtualworld, int baseid, int newid, const char * dffname, const char * txdname, int timeon, int timeoff)
{
	return sampgdk_AddSimpleModelTimed(virtualworld, baseid, newid, dffname, txdname, timeon, timeoff);
}

bool findModelFileNameFromCrc(int crc, char * model_str, int model_str_len)
{
	return sampgdk_FindModelFileNameFromCRC(crc, model_str, model_str_len);
}

bool findTextureFileNameFromCrc(int crc, char * texture_str, int texture_str_len)
{
	return sampgdk_FindTextureFileNameFromCRC(crc, texture_str, texture_str_len);
}

bool redirectDownload(Player player_, const char * url)
{
	return sampgdk_RedirectDownload(player_.id(), url);
}



}