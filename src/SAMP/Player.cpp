#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Player.hpp>

#include <SAMPCpp/SAMP/Vehicle.hpp>

namespace samp_cpp
{

/////////////////////////////////
bool Player::msg(ChatFmtColorPair const& coloredMsg_)
{
	return this->msg(coloredMsg_.first, coloredMsg_.second);
}

/////////////////////////////////
bool Player::msg(Color color_, std::string const& content_)
{
	return this->msg(color_, content_.c_str());
}

//////////////////////////////////////
bool Player::msg(Color color_, char const* content_)
{
	return sampgdk_SendClientMessage(_id, color_, content_);
}

/////////////////////////////////
bool Player::msgAll(ChatFmtColorPair const& coloredMsg_)
{
	return msgAll(coloredMsg_.first, coloredMsg_.second);
}

/////////////////////////////////
bool Player::msgAll(Color color_, std::string const& content_)
{
	return msgAll(color_, content_.c_str());
}

//////////////////////////////////////
bool Player::msgAll(Color color_, char const* content_)
{
	return sampgdk_SendClientMessageToAll(color_, content_);
}

//////////////////////////////////////
bool Player::setPosition(math::Vector3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////
bool Player::setPositionFindZ(math::Vector3f const& pos_)
{
	return this->setPositionFindZ(pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////
bool Player::setPosition(float x_, float y_, float z_)
{
	return sampgdk_SetPlayerPos(_id, x_, y_, z_);
}

//////////////////////////////////////
void Player::getIpAddress(char buf_[IpAddressSize + 1]) const
{
	this->getIpAddress(buf_, IpAddressSize + 1);
}

//////////////////////////////////////
std::string Player::getIpAddress() const
{
	char buf[IpAddressSize + 1];
	this->getIpAddress(buf);
	return std::string(buf, buf + IpAddressSize); // without zero at the end
}

//////////////////////////////////////
math::Vector3f Player::getPosition() const
{
	math::Vector3f result;

	sampgdk_GetPlayerPos(_id, &result.x, &result.y, &result.z);
		
	return result;
}

//////////////////////////////////////
bool Player::setCameraPosition(math::Vector3f const& pos_)
{
	return this->setCameraPosition(pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////
bool Player::setCameraPosition(float x_, float y_, float z_)
{
	return sampgdk_SetPlayerCameraPos(_id, x_, y_, z_);
}

//////////////////////////////////////
bool Player::setCameraLookAt(math::Vector3f const& lookAt_, CameraMove moveMethod_)
{
	return this->setCameraLookAt(lookAt_.x, lookAt_.y, lookAt_.z, moveMethod_);
}

//////////////////////////////////////
bool Player::setCameraLookAt(float x_, float y_, float z_, CameraMove moveMethod_)
{
	return sampgdk_SetPlayerCameraLookAt(_id, x_, y_, z_, static_cast<int>(moveMethod_));
}

//////////////////////////////////////
std::string Player::getName() const
{
	char buf[MAX_PLAYER_NAME];
	int len = sampgdk_GetPlayerName(_id, buf, MAX_PLAYER_NAME);
	if (len == 0)
		return {};
	
	return std::string(buf, buf + len);
}

//////////////////////////////////////
bool Player::setSpawnInfo(int team_, int skin_, math::Vector3f const& spawnPos_, float rotation_, Weapon weapons_[3])
{
	return sampgdk_SetSpawnInfo(_id, 
			team_, skin_,
			spawnPos_.x, spawnPos_.y, spawnPos_.z, rotation_,
			weapons_[0].id, weapons_[0].ammo,
			weapons_[1].id, weapons_[1].ammo,
			weapons_[2].id, weapons_[2].ammo
		);
}

//////////////////////////////////////
bool Player::spawn()
{
	return sampgdk_SpawnPlayer(_id);
}

//////////////////////////////////////
bool Player::setPositionFindZ(float x, float y, float z)
{
	return sampgdk_SetPlayerPosFindZ(_id, x, y, z);
}

//////////////////////////////////////
bool Player::setFacingAngle(float angle)
{
	return sampgdk_SetPlayerFacingAngle(_id, angle);
}

//////////////////////////////////////
float Player::getFacingAngle() const
{
	float angle = 0.0f;
	sampgdk_GetPlayerFacingAngle(_id, &angle);
	return angle;
}

//////////////////////////////////////
bool Player::isInRangeOfPoint(float range_, math::Vector3f const& point_) const
{
	return this->isInRangeOfPoint(range_, point_.x, point_.y, point_.z);
}

//////////////////////////////////////
bool Player::isInRangeOfPoint(float range, float x, float y, float z) const
{
	return sampgdk_IsPlayerInRangeOfPoint(_id, range, x, y, z);
}

//////////////////////////////////////
float Player::getDistanceFromPoint(math::Vector3f const& point_) const
{
	return sampgdk_GetPlayerDistanceFromPoint(_id, point_.x, point_.y, point_.z);
}

//////////////////////////////////////
float Player::getDistanceFromPoint(float x, float y, float z) const
{
	return sampgdk_GetPlayerDistanceFromPoint(_id, x, y, z);
}

//////////////////////////////////////
bool Player::isStreamedInFor(Player const& other_) const
{
	return sampgdk_IsPlayerStreamedIn(_id, other_.id());
}

//////////////////////////////////////
bool Player::setInterior(int interiorIdx)
{
	return sampgdk_SetPlayerInterior(_id, interiorIdx);
}

//////////////////////////////////////
int Player::getInterior() const
{
	return sampgdk_GetPlayerInterior(_id);
}

//////////////////////////////////////
bool Player::setHealth(float health)
{
	return sampgdk_SetPlayerHealth(_id, health);
}

//////////////////////////////////////
float Player::getHealth() const
{
	float health = 0;
	sampgdk_GetPlayerHealth(_id, &health);
	return health;
}

//////////////////////////////////////
bool Player::setArmour(float armour)
{
	return sampgdk_SetPlayerArmour(_id, armour);
}

//////////////////////////////////////
float Player::getArmour() const
{
	float armour = 0;
	sampgdk_GetPlayerArmour(_id, &armour);
	return armour;
}

//////////////////////////////////////
bool Player::setAmmo(int weaponid, int ammo)
{
	return sampgdk_SetPlayerAmmo(_id, weaponid, ammo);
}

//////////////////////////////////////
int Player::getAmmo() const
{
	return sampgdk_GetPlayerAmmo(_id);
}

//////////////////////////////////////
WeaponState Player::getWeaponState() const
{
	return static_cast<WeaponState>(sampgdk_GetPlayerWeaponState(_id));
}

//////////////////////////////////////
Player Player::getTargetPlayer() const
{
	return Player{ sampgdk_GetPlayerTargetPlayer(_id) };
}

//////////////////////////////////////
int Player::getTargetActor() const
{
	return sampgdk_GetPlayerTargetActor(_id);
}

//////////////////////////////////////
bool Player::setTeam(int teamIdx_)
{
	return sampgdk_SetPlayerTeam(_id, teamIdx_);
}

//////////////////////////////////////
int Player::getTeam() const
{
	return sampgdk_GetPlayerTeam(_id);
}

//////////////////////////////////////
bool Player::setScore(int score_)
{
	return sampgdk_SetPlayerScore(_id, score_);
}

//////////////////////////////////////
int Player::getScore() const
{
	return sampgdk_GetPlayerScore(_id);
}

//////////////////////////////////////
int Player::getDrunkLevel() const
{
	return sampgdk_GetPlayerDrunkLevel(_id);
}

//////////////////////////////////////
bool Player::setDrunkLevel(int level_)
{
	return sampgdk_SetPlayerDrunkLevel(_id, level_);
}

//////////////////////////////////////
bool Player::setColor(Color color_)
{
	return sampgdk_SetPlayerColor(_id, color_);
}

//////////////////////////////////////
Color Player::getColor() const
{
	return sampgdk_GetPlayerColor(_id);
}

//////////////////////////////////////
bool Player::setSkin(int skinIdx_)
{
	return sampgdk_SetPlayerSkin(_id, skinIdx_);
}

//////////////////////////////////////
int Player::getSkin() const
{
	return sampgdk_GetPlayerSkin(_id);
}

//////////////////////////////////////
bool Player::giveWeapon(Weapon weapon_)
{
	return this->giveWeapon(weapon_.id, weapon_.ammo);
}

//////////////////////////////////////
bool Player::giveWeapon(Weapon::Type weaponType_, int32_t ammo_)
{
	return sampgdk_GivePlayerWeapon(_id, static_cast<int>(weaponType_), ammo_);
}

//////////////////////////////////////
bool Player::resetWeapons()
{
	return sampgdk_ResetPlayerWeapons(_id);
}

//////////////////////////////////////
bool Player::setArmedWeapon(Weapon::Type weaponType_)
{
	return sampgdk_SetPlayerArmedWeapon(_id, static_cast<int>(weaponType_));
}

//////////////////////////////////////
bool Player::getWeaponData(int slot, int * weapon, int * ammo) const
{
	return sampgdk_GetPlayerWeaponData(_id, slot, weapon, ammo);
}

//////////////////////////////////////
bool Player::givePlayerMoney(int money)
{
	return sampgdk_GivePlayerMoney(_id, money);
}

//////////////////////////////////////
bool Player::resetMoney()
{
	return sampgdk_ResetPlayerMoney(_id);
}

//////////////////////////////////////
int Player::setName(std::string const& name_)
{
	return sampgdk_SetPlayerName(_id, name_.c_str());
}

//////////////////////////////////////
int Player::setName(char const* name_)
{
	return sampgdk_SetPlayerName(_id, name_);
}

//////////////////////////////////////
int Player::getMoney() const
{
	return sampgdk_GetPlayerMoney(_id);
}

//////////////////////////////////////
PlayerState Player::getState() const
{
	return static_cast<PlayerState>( sampgdk_GetPlayerState(_id) );
}

//////////////////////////////////////
bool Player::getIpAddress(char * ip, int size) const
{
	return sampgdk_GetPlayerIp(_id, ip, size);
}

//////////////////////////////////////
int Player::getPing() const
{
	return sampgdk_GetPlayerPing(_id);
}

//////////////////////////////////////
int Player::getWeapon() const
{
	return sampgdk_GetPlayerWeapon(_id);
}

//////////////////////////////////////
bool Player::getKeys(int * keys, int * updown, int * leftright) const
{
	return sampgdk_GetPlayerKeys(_id, keys, updown, leftright);
}

//////////////////////////////////////
int Player::getName(char * name, int size) const
{
	return sampgdk_GetPlayerName(_id, name, size);
}

//////////////////////////////////////
bool Player::setTime(int hour, int minute)
{
	return sampgdk_SetPlayerTime(_id, hour, minute);
}

//////////////////////////////////////
GameTime Player::getTime() const
{
	GameTime result;
	sampgdk_GetPlayerTime(_id, &result.hour, &result.minute);
	return result;
}

//////////////////////////////////////
bool Player::toggleClock(bool toggle)
{
	return sampgdk_TogglePlayerClock(_id, toggle);
}

//////////////////////////////////////
bool Player::setWeather(int weather)
{
	return sampgdk_SetPlayerWeather(_id, weather);
}

//////////////////////////////////////
bool Player::forceClassSelection()
{
	return sampgdk_ForceClassSelection(_id);
}

//////////////////////////////////////
bool Player::setWantedLevel(int level)
{
	return sampgdk_SetPlayerWantedLevel(_id, level);
}

//////////////////////////////////////
int Player::getWantedLevel() const
{
	return sampgdk_GetPlayerWantedLevel(_id);
}

//////////////////////////////////////
bool Player::setFightingStyle(FightStyle style_)
{
	return sampgdk_SetPlayerFightingStyle(_id, static_cast<int>(style_));
}

//////////////////////////////////////
FightStyle Player::getFightingStyle() const
{
	return static_cast<FightStyle>(sampgdk_GetPlayerFightingStyle(_id));
}

//////////////////////////////////////
bool Player::setVelocity(math::Vector3f const& velocity_)
{
	return this->setVelocity(velocity_.x, velocity_.y, velocity_.z);
}

//////////////////////////////////////
bool Player::setVelocity(float x, float y, float z)
{
	return sampgdk_SetPlayerVelocity(_id, x, y, z);
}

//////////////////////////////////////
math::Vector3f Player::getVelocity() const
{
	math::Vector3f velocity;
	sampgdk_GetPlayerVelocity(_id, &velocity.x, &velocity.y, &velocity.z);
	return velocity;
}

//////////////////////////////////////
bool Player::playCrimeReport(int suspectid, int crime)
{
	return sampgdk_PlayCrimeReportForPlayer(_id, suspectid, crime);
}

//////////////////////////////////////
bool Player::playAudioStream(std::string const& url_, math::Vector3f pos_, float distance_, bool usePos_)
{
	return this->playAudioStream(url_.c_str(), pos_.x, pos_.y, pos_.z, distance_, usePos_);
}

//////////////////////////////////////
bool Player::playAudioStream(char const* url_, float posX_, float posY_, float posZ_, float distance_, bool usePos_)
{
	return sampgdk_PlayAudioStreamForPlayer(_id, url_, posX_, posY_, posZ_, distance_, usePos_);
}

//////////////////////////////////////
bool Player::stopAudioStream()
{
	return sampgdk_StopAudioStreamForPlayer(_id);
}

//////////////////////////////////////
bool Player::setShopName(std::string const& shopName_)
{
	return this->setShopName(shopName_.c_str());
}

//////////////////////////////////////
bool Player::setShopName(char const* shopName_)
{
	return sampgdk_SetPlayerShopName(_id, shopName_);
}

//////////////////////////////////////
bool Player::setSkillLevel(WeaponSkill skill_, int level_)
{
	return sampgdk_SetPlayerSkillLevel(_id, static_cast<int>(skill_), level_);
}

//////////////////////////////////////
Vehicle Player::getSurfingVehicle() const
{
	return sampgdk_GetPlayerSurfingVehicleID(_id);
}

//////////////////////////////////////
int Player::getSurfingObjectId() const
{
	return sampgdk_GetPlayerSurfingObjectID(_id);
}

//////////////////////////////////////
bool Player::removeBuilding(int modelid, float fX, float fY, float fZ, float fRadius)
{
	return sampgdk_RemoveBuildingForPlayer(_id, modelid, fX, fY, fZ, fRadius);
}

//////////////////////////////////////
ShotVectors Player::getLastShotVectors() const
{
	ShotVectors sv;
	sampgdk_GetPlayerLastShotVectors(_id, &sv.origin.x, &sv.origin.y, &sv.origin.z, &sv.hitPos.x, &sv.hitPos.y, &sv.hitPos.z);
	return sv;
}

//////////////////////////////////////
bool Player::setAttachedObject(int index, int modelid, int bone, float fOffsetX, float fOffsetY, float fOffsetZ, float fRotX, float fRotY, float fRotZ, float fScaleX, float fScaleY, float fScaleZ, int materialcolor1, int materialcolor2)
{
	return sampgdk_SetPlayerAttachedObject(_id, index, modelid, bone, fOffsetX, fOffsetY, fOffsetZ, fRotX, fRotY, fRotZ, fScaleX, fScaleY, fScaleZ, materialcolor1, materialcolor2);
}

//////////////////////////////////////
bool Player::removeAttachedObject(int index)
{
	return sampgdk_RemovePlayerAttachedObject(_id, index);
}

//////////////////////////////////////
bool Player::isAttachedObjectSlotUsed(int index) const
{
	return sampgdk_IsPlayerAttachedObjectSlotUsed(_id, index);
}

//////////////////////////////////////
bool Player::editAttachedObject(int index)
{
	return sampgdk_EditAttachedObject(_id, index);
}

//////////////////////////////////////
bool Player::setVarInt(std::string const& varName_, int value)
{
	return this->setVarInt(varName_.c_str(), value);
}

//////////////////////////////////////
bool Player::setVarInt(char const* varName_, int value)
{
	return sampgdk_SetPVarInt(_id, varName_, value);
}

//////////////////////////////////////
int Player::getVarInt(std::string const& varName_) const
{
	return this->getVarInt(varName_.c_str());
}

//////////////////////////////////////
int Player::getVarInt(char const* varName_) const
{
	return sampgdk_GetPVarInt(_id, varName_);
}

//////////////////////////////////////
bool Player::setVarString(std::string const& varName_, std::string const& value_)
{
	return this->setVarString(varName_.c_str(), value_.c_str());
}

//////////////////////////////////////
bool Player::setVarString(char const* varName_, char const* value)
{
	return sampgdk_SetPVarString(_id, varName_, value);
}

//////////////////////////////////////
bool Player::getVarString(char const* varName_, char * value_, int size_) const
{
	return sampgdk_GetPVarString(_id, varName_, value_, size_);
}

//////////////////////////////////////
bool Player::setVarFloat(std::string const& varName_, float value)
{
	return this->setVarFloat(varName_.c_str(), value);
}

//////////////////////////////////////
bool Player::setVarFloat(char const* varName_, float value)
{
	return sampgdk_SetPVarFloat(_id, varName_, value);
}

//////////////////////////////////////
float Player::getVarFloat(std::string const& varName_) const
{
	return this->getVarFloat(varName_.c_str());
}

//////////////////////////////////////
float Player::getVarFloat(char const* varName_) const
{
	return sampgdk_GetPVarFloat(_id, varName_);
}

//////////////////////////////////////
bool Player::deleteVar(std::string const& varName_)
{
	return this->deleteVar(varName_.c_str());
}

//////////////////////////////////////
bool Player::deleteVar(char const* varName_)
{
	return sampgdk_DeletePVar(_id, varName_);
}

//////////////////////////////////////
int Player::getVarsUpperIndex() const
{
	return sampgdk_GetPVarsUpperIndex(_id);
}

//////////////////////////////////////
bool Player::getVarNameAtIndex(int index_, char * varName_, int size_) const
{
	return sampgdk_GetPVarNameAtIndex(_id, index_, varName_, size_);
}

//////////////////////////////////////
PlayerVarType Player::getVarType(char const* varname) const
{
	return static_cast<PlayerVarType>(sampgdk_GetPVarType(_id, varname));
}

//////////////////////////////////////
bool Player::varExists(char const* varName_) const
{
	return this->getVarType(varName_) != PlayerVarType::None;
}

//////////////////////////////////////
bool Player::setChatBubble(std::string const& text_, Color color_, float drawDistance_, int expireTime_)
{
	return this->setChatBubble(text_.c_str(), static_cast<int>(color_), drawDistance_, expireTime_);
}

//////////////////////////////////////
bool Player::setChatBubble(char const* text, int color, float drawdistance, int expiretime)
{
	return sampgdk_SetPlayerChatBubble(_id, text, color, drawdistance, expiretime);
}

//////////////////////////////////////
bool Player::putInVehicle(Vehicle vehicle_, int seatIndex_)
{
	return sampgdk_PutPlayerInVehicle(_id, vehicle_.id(), seatIndex_);
}

//////////////////////////////////////
Vehicle Player::getVehicle() const
{
	return Vehicle{ sampgdk_GetPlayerVehicleID(_id) };
}

//////////////////////////////////////
int Player::getVehicleSeat() const
{
	return sampgdk_GetPlayerVehicleSeat(_id);
}

//////////////////////////////////////
bool Player::removeFromVehicle()
{
	return sampgdk_RemovePlayerFromVehicle(_id);
}

//////////////////////////////////////
bool Player::toggleControllable(bool toggle)
{
	return sampgdk_TogglePlayerControllable(_id, toggle);
}

//////////////////////////////////////
bool Player::playSound(int soundIdx_, math::Vector3f const& pos_)
{
	return this->playSound(soundIdx_, pos_.x, pos_.y, pos_.z);
}

//////////////////////////////////////
bool Player::playSound(int soundIdx_, float x_, float y_, float z_)
{
	return sampgdk_PlayerPlaySound(_id, soundIdx_, x_, y_, z_);
}

//////////////////////////////////////
bool Player::applyAnimation(char const* animlib, char const* animname, float fDelta, bool loop, bool lockx, bool locky, bool freeze, int time, bool forcesync)
{
	return sampgdk_ApplyAnimation(_id, animlib, animname, fDelta, loop, lockx, locky, freeze, time, forcesync);
}

//////////////////////////////////////
bool Player::clearAnimations(bool forcesync)
{
	return sampgdk_ClearAnimations(_id, forcesync);
}

//////////////////////////////////////
int Player::getAnimationIndex() const
{
	return sampgdk_GetPlayerAnimationIndex(_id);
}

//////////////////////////////////////
bool Player::getAnimationName(char * animlib, int animlib_size, char * animname, int animname_size) const
{
	return sampgdk_GetAnimationName(_id, animlib, animlib_size, animname, animname_size);
}

//////////////////////////////////////
PlayerSpecialAction Player::getSpecialAction() const
{
	return static_cast<PlayerSpecialAction>(sampgdk_GetPlayerSpecialAction(_id));
}

//////////////////////////////////////
bool Player::setSpecialAction(PlayerSpecialAction action_)
{
	return sampgdk_SetPlayerSpecialAction(_id, static_cast<int>(action_));
}

//////////////////////////////////////
bool Player::disableRemoteVehicleCollisions(bool disable)
{
	return sampgdk_DisableRemoteVehicleCollisions(_id, disable);
}

//////////////////////////////////////
bool Player::setCheckpoint(float x, float y, float z, float size)
{
	return sampgdk_SetPlayerCheckpoint(_id, x, y, z, size);
}

//////////////////////////////////////
bool Player::disableCheckpoint()
{
	return sampgdk_DisablePlayerCheckpoint(_id);
}

//////////////////////////////////////
bool Player::setRaceCheckpoint(int type, float x, float y, float z, float nextx, float nexty, float nextz, float size)
{
	return sampgdk_SetPlayerRaceCheckpoint(_id, type, x, y, z, nextx, nexty, nextz, size);
}

//////////////////////////////////////
bool Player::disableRaceCheckpoint()
{
	return sampgdk_DisablePlayerRaceCheckpoint(_id);
}

//////////////////////////////////////
bool Player::setWorldBounds(float x_max, float x_min, float y_max, float y_min)
{
	return sampgdk_SetPlayerWorldBounds(_id, x_max, x_min, y_max, y_min);
}

//////////////////////////////////////
bool Player::setMarkerForPlayer(int showplayerid, Color color_)
{
	return sampgdk_SetPlayerMarkerForPlayer(_id, showplayerid, color_);
}

//////////////////////////////////////
bool Player::showNameTagForPlayer(int showplayerid, bool show)
{
	return sampgdk_ShowPlayerNameTagForPlayer(_id, showplayerid, show);
}

//////////////////////////////////////
bool Player::setMapIcon(int iconid, float x, float y, float z, int markertype, int color, int style)
{
	return sampgdk_SetPlayerMapIcon(_id, iconid, x, y, z, markertype, color, style);
}

//////////////////////////////////////
bool Player::removeMapIcon(int iconid)
{
	return sampgdk_RemovePlayerMapIcon(_id, iconid);
}

//////////////////////////////////////
bool Player::allowTeleport(bool allow)
{
	return sampgdk_AllowPlayerTeleport(_id, allow);
}

//////////////////////////////////////
bool Player::setCameraBehindPlayer()
{
	return sampgdk_SetCameraBehindPlayer(_id);
}

//////////////////////////////////////
math::Vector3f Player::getCameraPosition() const
{
	math::Vector3f result;
	sampgdk_GetPlayerCameraPos(_id, &result.x, &result.y, &result.z);
	return result;
}

//////////////////////////////////////
math::Vector3f Player::getCameraFrontVector() const
{
	math::Vector3f result;
	sampgdk_GetPlayerCameraFrontVector(_id, &result.x, &result.y, &result.z);
	return result;
}

//////////////////////////////////////
int Player::getCameraMode() const
{
	return sampgdk_GetPlayerCameraMode(_id);
}

//////////////////////////////////////
bool Player::enableCameraTarget(bool enable)
{
	return sampgdk_EnablePlayerCameraTarget(_id, enable);
}

//////////////////////////////////////
int Player::getCameraTargetObject() const
{
	return sampgdk_GetPlayerCameraTargetObject(_id);
}

//////////////////////////////////////
int Player::getCameraTargetVehicle() const
{
	return sampgdk_GetPlayerCameraTargetVehicle(_id);
}

//////////////////////////////////////
Player Player::getCameraTargetPlayer() const
{
	return sampgdk_GetPlayerCameraTargetPlayer(_id);
}

//////////////////////////////////////
int Player::getCameraTargetActor() const
{
	return sampgdk_GetPlayerCameraTargetActor(_id);
}

//////////////////////////////////////
float Player::getCameraAspectRatio() const
{
	return sampgdk_GetPlayerCameraAspectRatio(_id);
}

//////////////////////////////////////
float Player::getCameraZoom() const
{
	return sampgdk_GetPlayerCameraZoom(_id);
}

//////////////////////////////////////
bool Player::attachCameraToObject(int objectid)
{
	return sampgdk_AttachCameraToObject(_id, objectid);
}

//////////////////////////////////////
bool Player::attachCameraToPlayerObject(int playerobjectid)
{
	return sampgdk_AttachCameraToPlayerObject(_id, playerobjectid);
}

//////////////////////////////////////
bool Player::interpolateCameraPos(math::Vector3f const& from_, math::Vector3f const& to_, int time_, CameraMove moveMode_)
{
	return this->interpolateCameraPos(from_.x, from_.y, from_.z, to_.x, to_.y, to_.z, time_, moveMode_);
}

//////////////////////////////////////
bool Player::interpolateCameraPos(float fromX_, float fromY_, float fromZ_, float toX_, float toY_, float toZ_, int time_, CameraMove moveMode_)
{
	return sampgdk_InterpolateCameraPos(_id, fromX_, fromY_, fromZ_, toX_, toY_, toZ_, time_, static_cast<int>(moveMode_));
}

//////////////////////////////////////
bool Player::interpolateCameraLookAt(math::Vector3f const& from_, math::Vector3f const& to_, int time_, CameraMove moveMode_)
{
	return this->interpolateCameraLookAt(from_.x, from_.y, from_.z, to_.x, to_.y, to_.z, time_, moveMode_);
}

//////////////////////////////////////
bool Player::interpolateCameraLookAt(float fromX_, float fromY_, float fromZ_, float toX_, float toY_, float toZ_, int time_, CameraMove moveMode_)
{
	return sampgdk_InterpolateCameraLookAt(_id, fromX_, fromY_, fromZ_, toX_, toY_, toZ_, time_, static_cast<int>(moveMode_));
}

//////////////////////////////////////
bool Player::isConnected(int playerIdx_)
{
	return sampgdk_IsPlayerConnected(playerIdx_);
}

//////////////////////////////////////
bool Player::isConnected() const
{
	return sampgdk_IsPlayerConnected(_id);
}

//////////////////////////////////////
bool Player::isInVehicle(int vehicleid) const
{
	return sampgdk_IsPlayerInVehicle(_id, vehicleid);
}

//////////////////////////////////////
bool Player::isInAnyVehicle() const
{
	return sampgdk_IsPlayerInAnyVehicle(_id);
}

//////////////////////////////////////
bool Player::isInCheckpoint() const
{
	return sampgdk_IsPlayerInCheckpoint(_id);
}

//////////////////////////////////////
bool Player::isInRaceCheckpoint() const
{
	return sampgdk_IsPlayerInRaceCheckpoint(_id);
}

//////////////////////////////////////
bool Player::setVirtualWorld(int worldid)
{
	return sampgdk_SetPlayerVirtualWorld(_id, worldid);
}

//////////////////////////////////////
int Player::getVirtualWorld() const
{
	return sampgdk_GetPlayerVirtualWorld(_id);
}

//////////////////////////////////////
bool Player::enableStuntBonus(bool enable)
{
	return sampgdk_EnableStuntBonusForPlayer(_id, enable);
}

//////////////////////////////////////
bool Player::enableStuntBonusForAll(bool enable_)
{
	return sampgdk_EnableStuntBonusForAll(enable_);
}

//////////////////////////////////////
bool Player::toggleSpectating(bool toggle)
{
	return sampgdk_TogglePlayerSpectating(_id, toggle);
}

//////////////////////////////////////
bool Player::spectateOtherPlayer(Player const& target_, SpectateMode mode_)
{
	return sampgdk_PlayerSpectatePlayer(_id, target_.id(), static_cast<int>(mode_));
}

//////////////////////////////////////
bool Player::spectateVehicle(int targetvehicleid, int mode)
{
	return sampgdk_PlayerSpectateVehicle(_id, targetvehicleid, mode);
}

//////////////////////////////////////
bool Player::startRecordingData(int recordtype, char const* recordname)
{
	return sampgdk_StartRecordingPlayerData(_id, recordtype, recordname);
}

//////////////////////////////////////
bool Player::stopRecordingData()
{
	return sampgdk_StopRecordingPlayerData(_id);
}

//////////////////////////////////////
bool Player::createExplosion(float X, float Y, float Z, int type, float radius)
{
	return sampgdk_CreateExplosionForPlayer(_id, X, Y, Z, type, radius);
}


}