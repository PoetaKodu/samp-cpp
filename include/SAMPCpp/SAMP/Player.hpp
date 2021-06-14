#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Weapon.hpp>
#include <SAMPCpp/Core/Color.hpp>
#include <SAMPCpp/Core/String.hpp>
#include <SAMPCpp/Core/Formatting.hpp>

namespace samp_cpp
{

// Forward declarations:
class Vehicle;

// Constants:
constexpr const int32_t MaxPlayerAttachedObjects 	= 10;
constexpr const int32_t MaxChatbubbleLength 		= 144;
constexpr const int32_t IpAddressSize 				= 15; /// Warning, without zero at the end!


/////////////////////////////
enum class PlayerState
{
	None 					= 0,
	OnFoot 					= 1,
	Driver 					= 2,
	Passenger 				= 3,
	ExitVehicle 			= 4,
	EnterVehicleDriver 		= 5,
	EnterVehiclePassenger 	= 6,
	Wasted 					= 7,
	Spawned 				= 8,
	Spectating 				= 9,
};

/////////////////////////////
enum class PlayerSpecialAction
{
	None				= 0,
	Duck				= 1,
	UseJetpack			= 2,
	EnterVehicle		= 3,
	ExitVehicle			= 4,
	Dance1				= 5,
	Dance2				= 6,
	Dance3				= 7,
	Dance4				= 8,
	HandsUp				= 10,
	UseCellphone		= 11,
	Sitting				= 12,
	StopUseCellphone	= 13,
	DrinkBeer			= 20,
	SmokeCiggy			= 21,
	DrinkWine			= 22,
	DrinkSprunk			= 23,
	Cuffed				= 24,
	Carry				= 25,
	Pissing				= 68
};

/////////////////////////////
enum class FightStyle
{
	Normal				= 4,
	Boxing				= 5,
	KungFu				= 6,
	KneeHead			= 7,
	GrabKick			= 15,
	Elbow				= 16
};

/////////////////////////////
enum class WeaponSkill
{
	Pistol				= 0,
	PistolSilenced		= 1,
	DesertEagle			= 2,
	Shotgun				= 3,
	SawnoffShotgun		= 4,
	Spas12Shotgun		= 5,
	MicroUzi			= 6,
	Mp5					= 7,
	Ak47				= 8,
	M4					= 9,
	SniperRifle			= 10
};

/////////////////////////////
enum class WeaponState
{
	Unknown				= -1,
	NoBullets			= 0,
	LastBullet			= 1,
	MoreBullets			= 2,
	Reloading			= 3
};

/////////////////////////////
enum class PlayerVarType
{
	None				= 0,
	Int					= 1,
	String				= 2,
	Float				= 3
};

/////////////////////////////
enum class MapIconType
{
	Local				= 0,
	Global				= 1,
	LocalCheckpoint		= 2,
	GlobalCheckpoint	= 3
};

/////////////////////////////
enum class SpectateMode
{
	Normal				= 1,
	Fixed				= 2,
	Side				= 3
};

/////////////////////////////
enum class PlayerRecordingType
{
	None				= 0,
	Driver				= 1,
	OnFoot				= 2
};

/////////////////////////////
enum class CameraMove
{
	Move = 1,
	Cut = 2
};

struct GameTime
{
	GameTime() = default;
	GameTime(int32_t hour_, int32_t minute_ = 0)
		: 
		hour(hour_), minute(minute_)
	{
	}

	int32_t hour 	= 12;
	int32_t minute 	= 0;
};

struct ShotVectors
{
	math::Vector3f origin;
	math::Vector3f hitPos;
};

struct PlayerAnimation
{
	std::string libName;
	std::string animName;
};

class Player
{
public:
	using VarType = PlayerVarType;

	Player(int32_t id_)
		: _id(id_)
	{
	}

	bool valid() const { return _id >= 0 && _id != INVALID_PLAYER_ID; }
	int32_t id() const { return _id; }

	template <typename TFirstArg, typename... TArgs>
	void msg(ChatFmtColorPair const& colorPair_, TFirstArg && firstArg_, TArgs &&... args_)
	{
		std::string msgContent = fmt::format(
				colorPair_.second,
				std::forward<TFirstArg>(firstArg_),
				std::forward<TArgs>(args_)...
			);

		this->msg(colorPair_.first, msgContent);
	}
	
	template <typename TFormat, typename TFirstArg, typename... TArgs>
	void msg(Color color_, TFormat && fmt_, TFirstArg && firstArg_, TArgs &&... args_)
	{
		std::string msgContent = fmt::format(
				std::forward<TFormat>(fmt_),
				std::forward<TFirstArg>(firstArg_),
				std::forward<TArgs>(args_)...
			);

		this->msg(color_, msgContent);
	}

	bool msg(ChatFmtColorPair const& coloredMsg_);

	bool msg(Color color_, std::string const& content_);
	bool msg(Color color_, char const* content_);

	template <typename TFirstArg, typename... TArgs>
	static void msgAll(ChatFmtColorPair const& colorPair_, TFirstArg && firstArg_, TArgs &&... args_)
	{
		std::string msgContent = fmt::format(
				colorPair_.second,
				std::forward<TFirstArg>(firstArg_),
				std::forward<TArgs>(args_)...
			);

		Player::msgAll(colorPair_.first, msgContent);
	}
	
	template <typename TFormat, typename TFirstArg, typename... TArgs>
	static void msgAll(Color color_, TFormat && fmt_, TFirstArg && firstArg_, TArgs &&... args_)
	{
		std::string msgContent = fmt::format(
				std::forward<TFormat>(fmt_),
				std::forward<TFirstArg>(firstArg_),
				std::forward<TArgs>(args_)...
			);

		Player::msgAll(color_, msgContent);
	}

	static bool msgAll(ChatFmtColorPair const& coloredMsg_);

	static bool msgAll(Color color_, std::string const& content_);
	static bool msgAll(Color color_, char const* content_);

	///////////////////////////////
	/// Rich functions
	///////////////////////////////

	bool setPosition(math::Vector3f const& pos_);
	bool setPositionFindZ(math::Vector3f const& pos_);
	
	math::Vector3f getPosition() const;

	std::string getName() const;
	void getIpAddress(char buf_[IpAddressSize + 1]) const;
	std::string getIpAddress() const;

	bool setCameraPosition(math::Vector3f const& pos_);
	bool setCameraPosition(float x_, float y_, float z_);

	bool setCameraLookAt(math::Vector3f const& lookAt_, CameraMove moveMethod_ = CameraMove::Cut);
	bool setCameraLookAt(float x_, float y_, float z_, CameraMove moveMethod_ = CameraMove::Cut);

	bool isInRangeOfPoint(float range_, math::Vector3f const& point_) const;
	float getDistanceFromPoint(math::Vector3f const& pos_) const;
	bool setVelocity(math::Vector3f const& velocity_);
	math::Vector3f getVelocity() const;

	// A shorthand for this->getDistanceFromPoint
	float dist(math::Vector3f const& pos_) const { return this->getDistanceFromPoint(pos_); }

	// A shorthand for this->getVelocity()
	math::Vector3f vel() const { return this->getVelocity(); }

	// Calculates speed (based on velocity). Much slower than "speedSq"!
	float speed() const { return this->vel().length(); }

	// Calculated speed squared (based on velocity)
	float speedSq() const { return this->vel().lengthSquared(); }

	// A shorthand for this->getFacingAngle()
	float rot() const { return this->getFacingAngle(); }

	// A shorthand for this->getPosition()
	math::Vector3f pos() const { return this->getPosition(); }

	// A shorthand for this->getVirtualWorld()
	int32_t world() const { return this->getVirtualWorld(); }

	// A shorthand for this->getInterior()
	int32_t interior() const { return this->getInterior(); }

	// A shorthand for this->getHealth()
	float hp() const { return this->getHealth(); }

	// A shorthand for this->getArmour()
	float ap() const { return this->getArmour(); }

	// A shorthand for this->getIpAddress()
	std::string ip() const { return this->getIpAddress(); }


	///////////////////////////////
	/// RAW FUNCTIONS
	///////////////////////////////

	bool setSpawnInfo(int team_, int skin_, math::Vector3f const& spawnPos_, float rotation_, Weapon weapons_[3]);
	bool spawn();
	bool setPosition(float x_, float y_, float z_);
	bool setPositionFindZ(float x, float y, float z);
	bool setFacingAngle(float angle);
	float getFacingAngle() const;
	bool isInRangeOfPoint(float range, float x, float y, float z) const;
	float getDistanceFromPoint(float x, float y, float z) const;
	bool isStreamedInFor(Player const& other_) const;
	bool setInterior(int interiorid);
	int getInterior() const;
	bool setHealth(float health);
	float getHealth() const;
	bool setArmour(float armour);
	float getArmour() const;
	bool setAmmo(int weaponid, int ammo);
	int getAmmo() const;
	WeaponState getWeaponState() const;
	Player getTargetPlayer() const;
	int getTargetActor() const;
	bool setTeam(int teamid);
	int getTeam() const;
	bool setScore(int score);
	int getScore() const;
	int getDrunkLevel() const;
	bool setDrunkLevel(int level);
	bool setColor(Color color_);
	Color getColor() const;
	bool setSkin(int skinid);
	int getSkin() const;
	bool giveWeapon(Weapon weapon_);
	bool giveWeapon(Weapon::Type weaponType_, int32_t ammo);
	bool resetWeapons();
	bool setArmedWeapon(Weapon::Type weapon_);
	bool getWeaponData(int slot, int * weapon, int * ammo) const;
	bool givePlayerMoney(int money);
	bool resetMoney();
	int setName(std::string const& name_);
	int setName(char const* name_);
	int getMoney() const;
	PlayerState getState() const;
	bool getIpAddress(char * ip, int size) const;
	int getPing() const;
	int getWeapon() const;
	bool getKeys(int * keys, int * updown, int * leftright) const;
	int getName(char * name, int size) const;
	bool setTime(GameTime time_);
	bool setTime(int32_t hour_, int32_t minute_);
	GameTime getTime() const;
	bool toggleClock(bool toggle);
	bool setWeather(int weather);
	bool forceClassSelection();
	bool setWantedLevel(int level);
	int getWantedLevel() const;
	bool setFightingStyle(FightStyle style_);
	FightStyle getFightingStyle() const;
	bool setVelocity(float x, float y, float z);
	bool playCrimeReport(int suspectid, int crime);
	bool playAudioStream(std::string const& url_, math::Vector3f pos_, float distance_, bool usePos_);
	bool playAudioStream(char const* url_, float posX_, float posY_, float posZ_, float distance_, bool usePos_);
	bool stopAudioStream();
	bool setShopName(std::string const& shopName_);
	bool setShopName(char const* shopName_);
	bool setSkillLevel(WeaponSkill skill, int level);
	Vehicle getSurfingVehicle() const;
	int getSurfingObjectId() const;
	bool removeBuilding(int modelid, float fX, float fY, float fZ, float fRadius);
	ShotVectors getLastShotVectors() const;
	bool setAttachedObject(int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ, int materialcolor1, int materialcolor2);
	bool removeAttachedObject(int index);
	bool isAttachedObjectSlotUsed(int index) const;
	bool editAttachedObject(int index);

	/////////////////////////////////////
	/// Dynamic player variables (PVars)
	/////////////////////////////////////

	/////////
	// Int
	/////////
	bool 		setVarInt(std::string const& varName_, int value_);
	bool 		setVarInt(char const* varName_, int value_);
	int 		getVarInt(std::string const& varName_) const;
	int 		getVarInt(char const* varName_) const;

	/////////
	// Float
	/////////
	bool 		setVarFloat(std::string const& varName_, float value);
	bool 		setVarFloat(char const* varName_, float value);
	float 		getVarFloat(std::string const& varName_) const;
	float 		getVarFloat(char const* varName_) const;

	/////////
	// String
	/////////
	bool 		setVarString(std::string const& varName_, std::string const& value_);
	bool 		setVarString(char const* varName_, char const* value_);
	bool 		getVarString(char const* varName_, char * buf_, int size_) const;
	template <size_t MaxLength = 4 * 1024>
	std::string	getVarString(char const* varName_) const
	{
		char buf[MaxLength]{};
		if (this->getVarString(varName_, buf, MaxLength))
			return std::string{ buf, buf + strnlen_s(buf, MaxLength) };

		return {};
	}
	template <size_t MaxLength = 4 * 1024>
	std::string	getVarString(std::string const& varName_) const
	{
		return this->getVarString<MaxLength>(varName_.c_str());
	}

	
	/////////
	// Other
	/////////
	bool 		deleteVar(std::string const& varName_);
	bool 		deleteVar(char const* varName_);

	int 		getVarsUpperIndex() const;

	template <size_t MaxLength = 4 * 1024>
	std::string getVarNameAtIndex(int index_) const
	{
		char buf[MaxLength]{};
		if (this->getVarNameAtIndex(index_, buf, MaxLength))
			return std::string{ buf, buf + strnlen_s(buf, MaxLength) };

		return {};
	}
	bool 		getVarNameAtIndex(int index_, char * varName_, int size_) const;
	VarType 	getVarType(char const* varName_) const;
	bool 		varExists(char const* varName_) const;

	bool setChatBubble(std::string const& text_, Color color_, float drawDistance_, int expireTime_);
	bool setChatBubble(char const* text, int color, float drawdistance, int expiretime);
	bool putInVehicle(Vehicle vehicle_, int seatIndex_);
	Vehicle getVehicle() const;
	int getVehicleSeat() const;
	bool removeFromVehicle();
	bool toggleControllable(bool toggle);
	bool playSound(int soundIdx_, math::Vector3f const& pos_);
	bool playSound(int soundIdx_, float x_, float y_, float z_);
	bool applyAnimation(char const* animlib, char const* animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time, bool forcesync);
	bool clearAnimations(bool forcesync);
	int getAnimationIndex() const;

	template <size_t MaxLibLength = 4 * 1024, size_t MaxAnimLength = 4 * 1024>
	PlayerAnimation getAnimationName(char * animlib, int animlib_size, char * animname, int animname_size) const
	{
		PlayerAnimation result;

		char bufLib[MaxLibLength]{};
		char bufAnim[MaxAnimLength]{};

		if (this->getAnimationName(bufLib, MaxLibLength, bufAnim, MaxAnimLength))
		{
			result.libName 	= std::string{ bufLib, bufLib + strnlen_s(bufLib, MaxLibLength) };
			result.animName	= std::string{ bufAnim, bufAnim + strnlen_s(bufAnim, MaxAnimLength) };
		}

		return result;
	}

	bool getAnimationName(char * animlib, int animlib_size, char * animname, int animname_size) const;
	PlayerSpecialAction getSpecialAction() const;
	bool setSpecialAction(PlayerSpecialAction action_);
	bool disableRemoteVehicleCollisions(bool disable);
	bool setCheckpoint(float x, float y, float z, float size);
	bool disableCheckpoint();
	bool setRaceCheckpoint(int type, float x, float y, float z, float nextx, float nexty, float nextz, float size);
	bool disableRaceCheckpoint();
	bool setWorldBounds(float x_max, float x_min, float y_max, float y_min);
	bool setMarkerForPlayer(int showplayerid, Color color_);
	bool showNameTagForPlayer(int showplayerid, bool show);
	bool setMapIcon(int iconid, float x, float y, float z, int markertype, int color, int style);
	bool removeMapIcon(int iconid);
	bool allowTeleport(bool allow);
	bool setCameraBehindPlayer();
	math::Vector3f getCameraPosition() const;
	math::Vector3f getCameraFrontVector() const;
	int getCameraMode() const;
	bool enableCameraTarget(bool enable);
	int getCameraTargetObject() const;
	int getCameraTargetVehicle() const;
	Player getCameraTargetPlayer() const;
	int getCameraTargetActor() const;
	float getCameraAspectRatio() const;
	float getCameraZoom() const;
	bool attachCameraToObject(int objectid);
	bool attachCameraToPlayerObject(int playerobjectid);
	bool interpolateCameraPos(math::Vector3f const& from_, math::Vector3f const& to_, int time_, CameraMove moveMode_);
	bool interpolateCameraPos(float fromX_, float fromY_, float fromZ_, float toX_, float toY_, float toZ_, int time_, CameraMove moveMode_);
	bool interpolateCameraLookAt(math::Vector3f const& from_, math::Vector3f const& to_, int time_, CameraMove moveMode_);
	bool interpolateCameraLookAt(float fromX_, float fromY_, float fromZ_, float toX_, float toY_, float toZ_, int time_, CameraMove moveMode_);
	static bool isConnected(int playerIdx_);
	bool isConnected() const;
	bool isInVehicle(int vehicleid) const;
	bool isInAnyVehicle() const;
	bool isInCheckpoint() const;
	bool isInRaceCheckpoint() const;
	bool setVirtualWorld(int worldid);
	int getVirtualWorld() const;
	bool enableStuntBonus(bool enable);
	static bool enableStuntBonusForAll(bool enable_);
	bool toggleSpectating(bool toggle);
	bool spectateOtherPlayer(Player const& target_, SpectateMode mode_);
	bool spectateVehicle(int targetvehicleid, int mode);
	bool startRecordingData(int recordtype, char const* recordname);
	bool stopRecordingData();
	bool createExplosion(float X, float Y, float Z, int type, float Radius);

private:
	int32_t _id;
};

}