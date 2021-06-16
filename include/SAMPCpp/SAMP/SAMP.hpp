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


enum class ServerVarType
{
	None	= 0,
	Int		= 1,
	String	= 2,
	Float	= 3,
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


///////////////////////////////////////////////
bool sendClientMessage(Player player_, Color color_, char const* message_);

///////////////////////////////////////////////
bool sendClientMessageToAll(Color color_, char const* message_);

///////////////////////////////////////////////
bool sendPlayerMessageToPlayer(Player player_, Player sender_, char const* message_);

///////////////////////////////////////////////
bool sendPlayerMessageToAll(Player sender_, char const* message_);

///////////////////////////////////////////////
bool sendDeathMessage(Player killer_, Player killee_, Weapon::Type weapon_);

///////////////////////////////////////////////
bool sendDeathMessageToPlayer(Player player_, Player killer_, Player killee_, Weapon::Type weapon_);

///////////////////////////////////////////////
bool gameTextForAll(char const* text_, int time_, int style_);

///////////////////////////////////////////////
bool gameTextForPlayer(Player player_, char const* text_, int time_, int style_);

///////////////////////////////////////////////
int getTickCount();

///////////////////////////////////////////////
int getMaxPlayers();

///////////////////////////////////////////////
int getPlayerPoolSize();

///////////////////////////////////////////////
int getVehiclePoolSize();

///////////////////////////////////////////////
int getActorPoolSize();

///////////////////////////////////////////////
template <size_t MaxHashLength = (256 / 8)>
std::string sha256PassHash(std::string const& password_, std::string const& salt_)
{
	char buf[MaxHashLength]{};
	sampgdk_SHA256_PassHash(password_.c_str(), salt_.c_str(), buf, MaxHashLength);
	return std::string{buf, buf + strnlen_s(buf, MaxHashLength) };
}

///////////////////////////////////////////////
bool setSVar(char const* varName_, int value_);

///////////////////////////////////////////////
bool setSVar(std::string const& varName_, int value_);

///////////////////////////////////////////////
int getSVarInt(char const* varName_);

///////////////////////////////////////////////
bool setSVar(char const* varName_, char const* value_);

///////////////////////////////////////////////
bool setSVar(std::string const& varName_, std::string const& value_);

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getSVarString(char const* varName_)
{
	char buf[MaxLength]{};
	sampgdk_GetSVarString(varName_, buf, MaxLength);
	return std::string{buf, buf + strnlen_s(buf, MaxLength) };
}

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getSVarString(std::string const& varName_)
{
	return getSVarString<MaxLength>(varName_.c_str());
}

///////////////////////////////////////////////
bool setSVar(char const* varName_, float value);

///////////////////////////////////////////////
bool setSVar(std::string const& varName_, float value_);

///////////////////////////////////////////////
float getSVarFloat(char const* varName_);

///////////////////////////////////////////////
bool deleteSVar(char const* varName_);

///////////////////////////////////////////////
int getSVarsUpperIndex();

///////////////////////////////////////////////
template <size_t MaxNameLength = 1024>
inline bool getSVarNameAtIndex(int index_)
{
	char buf[MaxNameLength]{};
	sampgdk_GetSVarNameAtIndex(index_, buf, MaxNameLength);
	return std::string{buf, buf + strnlen_s(buf, MaxNameLength) };
}

///////////////////////////////////////////////
ServerVarType getSVarType(char const* varName_);

///////////////////////////////////////////////
bool setGameModeText(char const* text_);

///////////////////////////////////////////////
bool setGameModeText(std::string const& text_);

///////////////////////////////////////////////
bool setTeamCount(int count_);

///////////////////////////////////////////////
int addPlayerClass(int modelIdx_, Vec3f const& spawnPos_, float zAngle_, Weapon weapon1_ = Weapon::None, Weapon weapon2_ = Weapon::None, Weapon weapon3_ = Weapon::None);

///////////////////////////////////////////////
int addPlayerClass(int modelIdx_, float spawnX_, float spawnY_, float spawnZ_, float zAngle_, Weapon weapon1_ = Weapon::None, Weapon weapon2_ = Weapon::None, Weapon weapon3_ = Weapon::None);

///////////////////////////////////////////////
int addPlayerClassEx(int teamIdx_, int modelIdx_, Vec3f const& spawnPos_, float zAngle_, Weapon weapon1_ = Weapon::None, Weapon weapon2_ = Weapon::None, Weapon weapon3_ = Weapon::None);

///////////////////////////////////////////////
int addPlayerClassEx(int teamIdx_, int modelIdx_, float spawnX_, float spawnY_, float spawnZ_, float zAngle_, Weapon weapon1_ = Weapon::None, Weapon weapon2_ = Weapon::None, Weapon weapon3_ = Weapon::None);

///////////////////////////////////////////////
bool showNameTags(bool show_);

///////////////////////////////////////////////
bool showPlayerMarkers(int mode_);

///////////////////////////////////////////////
bool gameModeExit();

///////////////////////////////////////////////
bool setWorldTime(int hour_);

///////////////////////////////////////////////
bool getWeaponName(int weaponIdx_, char * name_, int size_);

///////////////////////////////////////////////
bool enableTirePopping(bool enable_);

///////////////////////////////////////////////
bool enableVehicleFriendlyFire();

///////////////////////////////////////////////
bool allowInteriorWeapons(bool allow_);

///////////////////////////////////////////////
bool setWeather(int weatherIdx_);

///////////////////////////////////////////////
bool setGravity(float gravity_);

///////////////////////////////////////////////
float getGravity();

///////////////////////////////////////////////
bool allowAdminTeleport(bool allow_);

// NOTE:
// Removed because it does not work with the current SAMP version:
// see: https://open.mp/docs/scripting/functions/SetDeathDropAmount
///////////////////////////////////////////////
// bool setDeathDropAmount(int amount_)
// {
// 	return sampgdk_SetDeathDropAmount(amount_);
// }

///////////////////////////////////////////////
bool createExplosion(float x_, float y_, float z_, int type_, float radius_);

///////////////////////////////////////////////
bool createExplosion(Vec3f const& pos_, int type_, float radius_);

///////////////////////////////////////////////
bool enableZoneNames(bool enable_);

///////////////////////////////////////////////
bool usePlayerPedAnims();

///////////////////////////////////////////////
bool disableInteriorEnterExits();

///////////////////////////////////////////////
bool setNameTagDrawDistance(float distance_);

///////////////////////////////////////////////
bool disableNameTagLos();

///////////////////////////////////////////////
bool limitGlobalChatRadius(float chatRadius_);

///////////////////////////////////////////////
bool limitPlayerMarkerRadius(float markerRadius_);

///////////////////////////////////////////////
bool connectNpc(char const* name_, char const* script_);

///////////////////////////////////////////////
bool connectNpc(std::string const& name_, std::string const& script_);

///////////////////////////////////////////////
bool sendRconCommand(char const* command_);

///////////////////////////////////////////////
bool sendRconCommand(std::string const& command_);

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getNetworkStats()
{
	char buf[MaxLength]{};
	sampgdk_GetNetworkStats(buf, MaxLength);
	return std::string{ buf, buf + strnlen_s(buf, MaxLength) };
}

///////////////////////////////////////////////
bool blockIpAddress(char const* ipAddress_, int timeMs_);

///////////////////////////////////////////////
bool blockIpAddress(std::string const& ipAddress_, int timeMs_);

///////////////////////////////////////////////
bool unblockIpAddress(char const* ipAddress_);

///////////////////////////////////////////////
bool unblockIpAddress(std::string const& ipAddress_);

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getServerVarAsString(char const* varName_)
{
	char buf[MaxLength]{};
	sampgdk_GetServerVarAsString(varName_, buf, MaxLength);
	return std::string{ buf, buf + strnlen_s(buf, MaxLength) };
}

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getServerVarAsString(std::string const& varName_)
{
	return getServerVarAsString<MaxLength>(varName_.c_str());
}

///////////////////////////////////////////////
int getServerVarAsInt(char const* varName_);

///////////////////////////////////////////////
int getServerVarAsInt(std::string const& varName_);

///////////////////////////////////////////////
bool getServerVarAsBool(char const* varName_);

///////////////////////////////////////////////
bool getServerVarAsBool(std::string const& varName_);

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getConsoleVarAsString(char const* varName_)
{
	char buf[MaxLength]{};
	sampgdk_GetConsoleVarAsString(varName_, buf, MaxLength);
	return std::string{ buf, buf + strnlen_s(buf, MaxLength) };
}

///////////////////////////////////////////////
template <size_t MaxLength = 4 * 1024>
inline std::string getConsoleVarAsString(std::string const& varName_)
{
	return getConsoleVarAsString<MaxLength>(varName_.c_str());
}

///////////////////////////////////////////////
int getConsoleVarAsInt(char const* varName_);

///////////////////////////////////////////////
int getConsoleVarAsInt(std::string const& varName_);

///////////////////////////////////////////////
bool getConsoleVarAsBool(char const* varName_);

///////////////////////////////////////////////
bool getConsoleVarAsBool(std::string const& varName_);

///////////////////////////////////////////////
int getServerTickRate();

///////////////////////////////////////////////
bool showPlayerDialog(Player player_, int dialogIdx_, int style_, char const* caption_, char const* info_, char const* button1_, char const* button2_);

///////////////////////////////////////////////
int addCharModel(int baseIdx_, int newIdx_, char const* dffName_, char const* txdName_);

///////////////////////////////////////////////
int addSimpleModel(int virtualWorld_, int baseIdx_, int newIdx_, char const* dffName_, char const* txdName_);

///////////////////////////////////////////////
int addSimpleModelTimed(int virtualWorld_, int baseIdx_, int newIdx_, char const* dffName_, char const* txdName_, int timeon_, int timeoff_);

///////////////////////////////////////////////
bool findModelFileNameFromCrc(int crc_, char * modelStr_, int modelStrLen_);

///////////////////////////////////////////////
bool findTextureFileNameFromCrc(int crc_, char * textureStr_, int textureStrLen_);

///////////////////////////////////////////////
bool redirectDownload(Player player_, char const* url_);



}