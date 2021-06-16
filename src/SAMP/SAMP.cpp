#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/SAMP.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////
bool sendClientMessage(Player player_, Color color_, char const* message_)
{
	return sampgdk_SendClientMessage(player_.id(), color_, message_);
}

///////////////////////////////////////////////
bool sendClientMessageToAll(Color color_, char const* message_)
{
	return sampgdk_SendClientMessageToAll(color_, message_);
}

///////////////////////////////////////////////
bool sendPlayerMessageToPlayer(Player player_, Player sender_, char const* message_)
{
	return sampgdk_SendPlayerMessageToPlayer(player_.id(), sender_.id(), message_);
}

///////////////////////////////////////////////
bool sendPlayerMessageToAll(Player sender_, char const* message_)
{
	return sampgdk_SendPlayerMessageToAll(sender_.id(), message_);
}

///////////////////////////////////////////////
bool sendDeathMessage(Player killer_, Player killee_, Weapon::Type weapon_)
{
	return sampgdk_SendDeathMessage(killer_.id(), killee_.id(), static_cast<int>(weapon_));
}

///////////////////////////////////////////////
bool sendDeathMessageToPlayer(Player player_, Player killer_, Player killee_, Weapon::Type weapon_)
{
	return sampgdk_SendDeathMessageToPlayer(player_.id(), killer_.id(), killee_.id(), static_cast<int>(weapon_));
}

///////////////////////////////////////////////
bool gameTextForAll(char const* text_, int time_, int style_)
{
	return sampgdk_GameTextForAll(text_, time_, style_);
}

///////////////////////////////////////////////
bool gameTextForPlayer(Player player_, char const* text_, int time_, int style_)
{
	return sampgdk_GameTextForPlayer(player_.id(), text_, time_, style_);
}

///////////////////////////////////////////////
int getTickCount()
{
	return sampgdk_GetTickCount();
}

///////////////////////////////////////////////
int getMaxPlayers()
{
	return sampgdk_GetMaxPlayers();
}

///////////////////////////////////////////////
int getPlayerPoolSize()
{
	return sampgdk_GetPlayerPoolSize();
}

///////////////////////////////////////////////
int getVehiclePoolSize()
{
	return sampgdk_GetVehiclePoolSize();
}

///////////////////////////////////////////////
int getActorPoolSize()
{
	return sampgdk_GetActorPoolSize();
}

///////////////////////////////////////////////
bool setSVar(char const* varName_, int value_)
{
	return sampgdk_SetSVarInt(varName_, value_);
}

///////////////////////////////////////////////
bool setSVar(std::string const& varName_, int value_)
{
	return setSVar(varName_.c_str(), value_);
}

///////////////////////////////////////////////
int getSVarInt(char const* varName_)
{
	return sampgdk_GetSVarInt(varName_);
}

///////////////////////////////////////////////
bool setSVar(char const* varName_, char const* value_)
{
	return sampgdk_SetSVarString(varName_, value_);
}

///////////////////////////////////////////////
bool setSVar(std::string const& varName_, std::string const& value_)
{
	return setSVar(varName_.c_str(), value_.c_str());
}

///////////////////////////////////////////////
bool setSVar(char const* varName_, float value)
{
	return sampgdk_SetSVarFloat(varName_, value);
}

///////////////////////////////////////////////
bool setSVar(std::string const& varName_, float value_)
{
	return setSVar(varName_.c_str(), value_);
}

///////////////////////////////////////////////
float getSVarFloat(char const* varName_)
{
	return sampgdk_GetSVarFloat(varName_);
}

///////////////////////////////////////////////
bool deleteSVar(char const* varName_)
{
	return sampgdk_DeleteSVar(varName_);
}

///////////////////////////////////////////////
int getSVarsUpperIndex()
{
	return sampgdk_GetSVarsUpperIndex();
}

///////////////////////////////////////////////
ServerVarType getSVarType(char const* varName_)
{
	return static_cast<ServerVarType>(sampgdk_GetSVarType(varName_));
}

///////////////////////////////////////////////
bool setGameModeText(char const* text_)
{
	return sampgdk_SetGameModeText(text_);
}

///////////////////////////////////////////////
bool setGameModeText(std::string const& text_)
{
	return sampgdk_SetGameModeText(text_.c_str());
}

///////////////////////////////////////////////
bool setTeamCount(int count_)
{
	return sampgdk_SetTeamCount(count_);
}

///////////////////////////////////////////////
int addPlayerClass(int modelIdx_, Vec3f const& spawnPos_, float zAngle_, Weapon weapon1_, Weapon weapon2_, Weapon weapon3_)
{
	return sampgdk_AddPlayerClass(
			modelIdx_,
			spawnPos_.x, spawnPos_.y, spawnPos_.z, zAngle_,
			weapon1_.id, weapon1_.ammo,
			weapon2_.id, weapon2_.ammo,
			weapon3_.id, weapon3_.ammo
		);
}

///////////////////////////////////////////////
int addPlayerClass(int modelIdx_, float spawnX_, float spawnY_, float spawnZ_, float zAngle_, Weapon weapon1_, Weapon weapon2_, Weapon weapon3_)
{
	return sampgdk_AddPlayerClass(
			modelIdx_,
			spawnX_, spawnY_, spawnZ_, zAngle_,
			weapon1_.id, weapon1_.ammo,
			weapon2_.id, weapon2_.ammo,
			weapon3_.id, weapon3_.ammo
		);
}

///////////////////////////////////////////////
int addPlayerClassEx(int teamIdx_, int modelIdx_, Vec3f const& spawnPos_, float zAngle_, Weapon weapon1_, Weapon weapon2_, Weapon weapon3_)
{
	return sampgdk_AddPlayerClassEx(
			teamIdx_, modelIdx_,
			spawnPos_.x, spawnPos_.y, spawnPos_.z, zAngle_,
			weapon1_.id, weapon1_.ammo,
			weapon2_.id, weapon2_.ammo,
			weapon3_.id, weapon3_.ammo
		);
}

///////////////////////////////////////////////
int addPlayerClassEx(int teamIdx_, int modelIdx_, float spawnX_, float spawnY_, float spawnZ_, float zAngle_, Weapon weapon1_, Weapon weapon2_, Weapon weapon3_)
{
	return sampgdk_AddPlayerClassEx(
			teamIdx_, modelIdx_,
			spawnX_, spawnY_, spawnZ_, zAngle_,
			weapon1_.id, weapon1_.ammo,
			weapon2_.id, weapon2_.ammo,
			weapon3_.id, weapon3_.ammo
		);
}

///////////////////////////////////////////////
bool showNameTags(bool show_)
{
	return sampgdk_ShowNameTags(show_);
}

///////////////////////////////////////////////
bool showPlayerMarkers(int mode_)
{
	return sampgdk_ShowPlayerMarkers(mode_);
}

///////////////////////////////////////////////
bool gameModeExit()
{
	return sampgdk_GameModeExit();
}

///////////////////////////////////////////////
bool setWorldTime(int hour_)
{
	return sampgdk_SetWorldTime(hour_);
}

///////////////////////////////////////////////
bool getWeaponName(int weaponIdx_, char * name_, int size_)
{
	return sampgdk_GetWeaponName(weaponIdx_, name_, size_);
}

///////////////////////////////////////////////
bool enableTirePopping(bool enable_)
{
	return sampgdk_EnableTirePopping(enable_);
}

///////////////////////////////////////////////
bool enableVehicleFriendlyFire()
{
	return sampgdk_EnableVehicleFriendlyFire();
}

///////////////////////////////////////////////
bool allowInteriorWeapons(bool allow_)
{
	return sampgdk_AllowInteriorWeapons(allow_);
}

///////////////////////////////////////////////
bool setWeather(int weatherIdx_)
{
	return sampgdk_SetWeather(weatherIdx_);
}

///////////////////////////////////////////////
bool setGravity(float gravity_)
{
	return sampgdk_SetGravity(gravity_);
}

///////////////////////////////////////////////
float getGravity()
{
	return sampgdk_GetGravity();
}

///////////////////////////////////////////////
bool allowAdminTeleport(bool allow_)
{
	return sampgdk_AllowAdminTeleport(allow_);
}

// NOTE:
// Removed because it does not work with the current SAMP version:
// see: https://open.mp/docs/scripting/functions/SetDeathDropAmount
///////////////////////////////////////////////
// bool setDeathDropAmount(int amount_)
// {
// 	return sampgdk_SetDeathDropAmount(amount_);
// }

///////////////////////////////////////////////
bool createExplosion(float x_, float y_, float z_, int type_, float radius_)
{
	return sampgdk_CreateExplosion(x_, y_, z_, type_, radius_);
}

///////////////////////////////////////////////
bool createExplosion(Vec3f const& pos_, int type_, float radius_)
{
	return createExplosion(pos_.x, pos_.y, pos_.z, type_, radius_);
}

///////////////////////////////////////////////
bool enableZoneNames(bool enable_)
{
	return sampgdk_EnableZoneNames(enable_);
}

///////////////////////////////////////////////
bool usePlayerPedAnims()
{
	return sampgdk_UsePlayerPedAnims();
}

///////////////////////////////////////////////
bool disableInteriorEnterExits()
{
	return sampgdk_DisableInteriorEnterExits();
}

///////////////////////////////////////////////
bool setNameTagDrawDistance(float distance_)
{
	return sampgdk_SetNameTagDrawDistance(distance_);
}

///////////////////////////////////////////////
bool disableNameTagLos()
{
	return sampgdk_DisableNameTagLOS();
}

///////////////////////////////////////////////
bool limitGlobalChatRadius(float chatRadius_)
{
	return sampgdk_LimitGlobalChatRadius(chatRadius_);
}

///////////////////////////////////////////////
bool limitPlayerMarkerRadius(float markerRadius_)
{
	return sampgdk_LimitPlayerMarkerRadius(markerRadius_);
}

///////////////////////////////////////////////
bool connectNpc(char const* name_, char const* script_)
{
	return sampgdk_ConnectNPC(name_, script_);
}

///////////////////////////////////////////////
bool connectNpc(std::string const& name_, std::string const& script_)
{
	return connectNpc(name_.c_str(), script_.c_str());
}

///////////////////////////////////////////////
bool sendRconCommand(char const* command_)
{
	return sampgdk_SendRconCommand(command_);
}

///////////////////////////////////////////////
bool sendRconCommand(std::string const& command_)
{
	return sendRconCommand(command_.c_str());
}

///////////////////////////////////////////////
bool blockIpAddress(char const* ipAddress_, int timeMs_)
{
	return sampgdk_BlockIpAddress(ipAddress_, timeMs_);
}

///////////////////////////////////////////////
bool blockIpAddress(std::string const& ipAddress_, int timeMs_)
{
	return blockIpAddress(ipAddress_.c_str(), timeMs_);
}

///////////////////////////////////////////////
bool unblockIpAddress(char const* ipAddress_)
{
	return sampgdk_UnBlockIpAddress(ipAddress_);
}

///////////////////////////////////////////////
bool unblockIpAddress(std::string const& ipAddress_)
{
	return unblockIpAddress(ipAddress_.c_str());
}

///////////////////////////////////////////////
int getServerVarAsInt(char const* varName_)
{
	return sampgdk_GetServerVarAsInt(varName_);
}

///////////////////////////////////////////////
int getServerVarAsInt(std::string const& varName_)
{
	return getServerVarAsInt(varName_.c_str());
}

///////////////////////////////////////////////
bool getServerVarAsBool(char const* varName_)
{
	return sampgdk_GetServerVarAsBool(varName_);
}

///////////////////////////////////////////////
bool getServerVarAsBool(std::string const& varName_)
{
	return getServerVarAsBool(varName_.c_str());
}

///////////////////////////////////////////////
int getConsoleVarAsInt(char const* varName_)
{
	return sampgdk_GetConsoleVarAsInt(varName_);
}

///////////////////////////////////////////////
int getConsoleVarAsInt(std::string const& varName_)
{
	return getConsoleVarAsInt(varName_.c_str());
}

///////////////////////////////////////////////
bool getConsoleVarAsBool(char const* varName_)
{
	return sampgdk_GetConsoleVarAsBool(varName_);
}

///////////////////////////////////////////////
bool getConsoleVarAsBool(std::string const& varName_)
{
	return getConsoleVarAsBool(varName_.c_str());
}

///////////////////////////////////////////////
int getServerTickRate()
{
	return sampgdk_GetServerTickRate();
}

///////////////////////////////////////////////
bool showPlayerDialog(Player player_, int dialogIdx_, int style_, char const* caption_, char const* info_, char const* button1_, char const* button2_)
{
	return sampgdk_ShowPlayerDialog(player_.id(), dialogIdx_, style_, caption_, info_, button1_, button2_);
}

///////////////////////////////////////////////
int addCharModel(int baseIdx_, int newIdx_, char const* dffName_, char const* txdName_)
{
	return sampgdk_AddCharModel(baseIdx_, newIdx_, dffName_, txdName_);
}

///////////////////////////////////////////////
int addSimpleModel(int virtualWorld_, int baseIdx_, int newIdx_, char const* dffName_, char const* txdName_)
{
	return sampgdk_AddSimpleModel(virtualWorld_, baseIdx_, newIdx_, dffName_, txdName_);
}

///////////////////////////////////////////////
int addSimpleModelTimed(int virtualWorld_, int baseIdx_, int newIdx_, char const* dffName_, char const* txdName_, int timeon_, int timeoff_)
{
	return sampgdk_AddSimpleModelTimed(virtualWorld_, baseIdx_, newIdx_, dffName_, txdName_, timeon_, timeoff_);
}

///////////////////////////////////////////////
bool findModelFileNameFromCrc(int crc_, char * modelStr_, int modelStrLen_)
{
	return sampgdk_FindModelFileNameFromCRC(crc_, modelStr_, modelStrLen_);
}

///////////////////////////////////////////////
bool findTextureFileNameFromCrc(int crc_, char * textureStr_, int textureStrLen_)
{
	return sampgdk_FindTextureFileNameFromCRC(crc_, textureStr_, textureStrLen_);
}

///////////////////////////////////////////////
bool redirectDownload(Player player_, char const* url_)
{
	return sampgdk_RedirectDownload(player_.id(), url_);
}

}