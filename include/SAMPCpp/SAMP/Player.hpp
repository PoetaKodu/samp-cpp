#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>
#include <SAMPCpp/Core/Formatting.hpp>

namespace samp_cpp
{

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

class Player
{
public:
	Player(int32_t id_)
		: _id(id_)
	{
	}

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

	///////////////////////////////
	/// RAW FUNCTIONS
	///////////////////////////////

	bool setSpawnInfo(int team, int skin, float x, float y, float z, float rotation, int weapon1, int weapon1_ammo, int weapon2, int weapon2_ammo, int weapon3, int weapon3_ammo);
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
	bool giveWeapon(int weaponid, int ammo);
	bool resetWeapons();
	bool setArmedWeapon(int weaponid);
	bool getWeaponData(int slot, int * weapon, int * ammo) const;
	bool givePlayerMoney(int money);
	bool resetMoney();
	int setName(const char * name);
	int getMoney() const;
	PlayerState getState() const;
	bool getIpAddress(char * ip, int size) const;
	int getPing() const;
	int getWeapon() const;
	bool getKeys(int * keys, int * updown, int * leftright) const;
	int getName(char * name, int size) const;
	bool setTime(int hour, int minute);
	bool getTime(int * hour, int * minute) const;
	bool toggleClock(bool toggle);
	bool setWeather(int weather);
	bool forceClassSelection();
	bool setWantedLevel(int level);
	int getWantedLevel() const;
	bool setFightingStyle(FightStyle style_);
	FightStyle getFightingStyle() const;
	bool setVelocity(float x, float y, float z);
	bool playCrimeReport(int suspectid, int crime);
	bool playAudioStream(const char * url, float posX, float posY, float posZ, float distance, bool usepos);
	bool stopAudioStream();
	bool setShopName(const char * shopname);
	bool setSkillLevel(int skill, int level);
	int getSurfingVehicleId() const;
	int getSurfingObjectId() const;
	bool removeBuilding(int modelid, float fX, float fY, float fZ, float fRadius);
	bool getLastShotVectors(float * fOriginX, float * fOriginY, float * fOriginZ, float * fHitPosX, float * fHitPosY, float * fHitPosZ) const;
	bool setAttachedObject(int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ, int materialcolor1, int materialcolor2);
	bool removeAttachedObject(int index);
	bool isAttachedObjectSlotUsed(int index) const;
	bool editAttachedObject(int index);
	bool setPVarInt(const char * varname, int value);
	int getPVarInt(const char * varname) const;
	bool setPVarString(const char * varname, const char * value);
	bool getPVarString(const char * varname, char * value, int size) const;
	bool setPVarFloat(const char * varname, float value);
	float getPVarFloat(const char * varname) const;
	bool deletePVar(const char * varname);
	int getPVarsUpperIndex() const;
	bool getPVarNameAtIndex(int index, char * varname, int size) const;
	int getPVarType(const char * varname) const;
	bool setChatBubble(const char * text, int color, float drawdistance, int expiretime);
	bool putInVehicle(int vehicleid, int seatid);
	int getVehicleId() const;
	int getVehicleSeat() const;
	bool removeFromVehicle();
	bool toggleControllable(bool toggle);
	bool playSound(int soundid, float x, float y, float z);
	bool applyAnimation(const char * animlib, const char * animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time, bool forcesync);
	bool clearAnimations(bool forcesync);
	int getAnimationIndex() const;
	bool getAnimationName(char * animlib, int animlib_size, char * animname, int animname_size) const;
	int getSpecialAction() const;
	bool setSpecialAction(int actionid);
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
	bool interpolateCameraPos(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut);
	bool interpolateCameraLookAt(float FromX, float FromY, float FromZ, float ToX, float ToY, float ToZ, int time, int cut);
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
	bool startRecordingData(int recordtype, const char * recordname);
	bool stopRecordingData();
	bool createExplosion(float X, float Y, float Z, int type, float Radius);

private:
	int32_t _id;
};

}