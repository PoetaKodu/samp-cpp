#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Vehicle.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////////////
bool Vehicle::valid() const
{
	return _id != INVALID_VEHICLE_ID && sampgdk_IsValidVehicle(_id);
}

///////////////////////////////////////////////////////
float Vehicle::getDistanceFromPoint(Vec3f const& point_) const
{
	return this->getDistanceFromPoint(point_.x, point_.y, point_.z);
}

///////////////////////////////////////////////////////
float Vehicle::getDistanceFromPoint(float x_, float y_, float z_) const
{
	return sampgdk_GetVehicleDistanceFromPoint(_id, x_, y_, z_);
}

///////////////////////////////////////////////
Vehicle Vehicle::addStatic(Model model_, Vec3f const& spawnPos_, float zAngle_, int color1_, int color2_)
{
	return sampgdk_AddStaticVehicle(model_, spawnPos_.x, spawnPos_.y, spawnPos_.z, zAngle_, color1_, color2_);
}

///////////////////////////////////////////////
Vehicle Vehicle::addStatic(Model model_, float spawnX_, float spawnY_, float spawnZ_, float zAngle_, int color1_, int color2_)
{
	return sampgdk_AddStaticVehicle(model_, spawnX_, spawnY_, spawnZ_, zAngle_, color1_, color2_);
}

///////////////////////////////////////////////
Vehicle Vehicle::addStatic(Model model_, Vec3f const& spawnPos_, float zAngle_, int color1_, int color2_, int respawnDelay_, bool addSiren_)
{
	return sampgdk_AddStaticVehicleEx(model_, spawnPos_.x, spawnPos_.y, spawnPos_.z, zAngle_, color1_, color2_, respawnDelay_, addSiren_);
}

///////////////////////////////////////////////
Vehicle Vehicle::addStatic(Model model_, float spawnX_, float spawnY_, float spawnZ_, float zAngle_, int color1_, int color2_, int respawnDelay_, bool addSiren_)
{
	return sampgdk_AddStaticVehicleEx(model_, spawnX_, spawnY_, spawnZ_, zAngle_, color1_, color2_, respawnDelay_, addSiren_);
}

///////////////////////////////////////////////////////
Vehicle Vehicle::create(Vehicle::Model model_,  Vec3f const& pos_, float rotation_, int color1_, int color2_, int respawnDelay_, bool addSiren_)
{
	return Vehicle::create(model_, pos_.x, pos_.y, pos_.z, rotation_, color1_, color2_, respawnDelay_, addSiren_);
}

///////////////////////////////////////////////////////
Vehicle Vehicle::create(Vehicle::Model model_, float x_, float y_, float z_, float rotation_, int color1_, int color2_, int respawnDelay_, bool addSiren_)
{
	return Vehicle{
			sampgdk_CreateVehicle(static_cast<int>(model_),
					x_, y_, z_, rotation_,
					color1_, color2_,
					respawnDelay_, addSiren_
				)
		};
}

///////////////////////////////////////////////////////
bool Vehicle::destroy()
{
	return sampgdk_DestroyVehicle(_id);
}

///////////////////////////////////////////////////////
bool Vehicle::isStreamedIn(int forPlayerIdx_) const
{
	return sampgdk_IsVehicleStreamedIn(_id, forPlayerIdx_);
}

///////////////////////////////////////////////////////
Vec3f Vehicle::getPosition() const
{
	Vec3f result;
	sampgdk_GetVehiclePos(_id, &result.x, &result.y, &result.z);
	return result;
}

///////////////////////////////////////////////////////
bool Vehicle::setPosition(Vec3f const& pos_)
{
	return this->setPosition(pos_.x, pos_.y, pos_.z);
}

///////////////////////////////////////////////////////
bool Vehicle::setPosition(float x_, float y_, float z_)
{
	return sampgdk_SetVehiclePos(_id, x_, y_, z_);
}

///////////////////////////////////////////////////////
float Vehicle::getZAngle() const
{
	float result;
	sampgdk_GetVehicleZAngle(_id, &result);
	return result;
}

///////////////////////////////////////////////////////
Quat Vehicle::getRotationQuat() const
{
	Quat result;
	sampgdk_GetVehicleRotationQuat(_id, &result.w, &result.x, &result.y, &result.z);
	return result;
}

///////////////////////////////////////////////////////
bool Vehicle::setZAngle(float angle_)
{
	return sampgdk_SetVehicleZAngle(_id, angle_);
}

///////////////////////////////////////////////////////
bool Vehicle::setParamsForPlayer(int playerIdx_, int objective_, int doorslocked_)
{
	return sampgdk_SetVehicleParamsForPlayer(_id, playerIdx_, objective_, doorslocked_);
}

///////////////////////////////////////////////////////
bool Vehicle::manualEngineAndLights()
{
	return sampgdk_ManualVehicleEngineAndLights();
}

///////////////////////////////////////////////////////
bool Vehicle::setParamsEx(int engine_, int lights_, int alarm_, int doors_, int bonnet_, int boot_, int objective_)
{
	return sampgdk_SetVehicleParamsEx(_id, engine_, lights_, alarm_, doors_, bonnet_, boot_, objective_);
}

///////////////////////////////////////////////////////
bool Vehicle::getParamsEx(int * engine, int * lights, int * alarm, int * doors, int * bonnet, int * boot, int * objective) const
{
	return sampgdk_GetVehicleParamsEx(_id, engine, lights, alarm, doors, bonnet, boot, objective);
}

///////////////////////////////////////////////////////
int Vehicle::getSirenState() const
{
	return sampgdk_GetVehicleParamsSirenState(_id);
}

///////////////////////////////////////////////////////
bool Vehicle::setCarDoorParams(int driver_, int passenger_, int backleft_, int backright_)
{
	return sampgdk_SetVehicleParamsCarDoors(_id, driver_, passenger_, backleft_, backright_);
}

///////////////////////////////////////////////////////
bool Vehicle::getCarDoorParams(int * driver, int * passenger, int * backleft, int * backright) const
{
	return sampgdk_GetVehicleParamsCarDoors(_id, driver, passenger, backleft, backright);
}

///////////////////////////////////////////////////////
bool Vehicle::setCarWindowParams(int driver_, int passenger_, int backleft_, int backright_)
{
	return sampgdk_SetVehicleParamsCarWindows(_id, driver_, passenger_, backleft_, backright_);
}

///////////////////////////////////////////////////////
bool Vehicle::getCarWindowParams(int * driver, int * passenger, int * backleft, int * backright) const
{
	return sampgdk_GetVehicleParamsCarWindows(_id, driver, passenger, backleft, backright);
}

///////////////////////////////////////////////////////
bool Vehicle::setToRespawn()
{
	return sampgdk_SetVehicleToRespawn(_id);
}

///////////////////////////////////////////////////////
bool Vehicle::linkToInterior(int interiorIdx_)
{
	return sampgdk_LinkVehicleToInterior(_id, interiorIdx_);
}

///////////////////////////////////////////////////////
bool Vehicle::addComponent(int componentIdx_)
{
	return sampgdk_AddVehicleComponent(_id, componentIdx_);
}

///////////////////////////////////////////////////////
bool Vehicle::removeComponent(int componentIdx_)
{
	return sampgdk_RemoveVehicleComponent(_id, componentIdx_);
}

///////////////////////////////////////////////////////
bool Vehicle::changeColor(int color1_, int color2_)
{
	return sampgdk_ChangeVehicleColor(_id, color1_, color2_);
}

///////////////////////////////////////////////////////
bool Vehicle::changePaintjob(int paintjobIdx_)
{
	return sampgdk_ChangeVehiclePaintjob(_id, paintjobIdx_);
}

///////////////////////////////////////////////////////
bool Vehicle::setHealth(float health_)
{
	return sampgdk_SetVehicleHealth(_id, health_);
}

///////////////////////////////////////////////////////
float Vehicle::getHealth() const
{
	float result;
	sampgdk_GetVehicleHealth(_id, &result);
	return result;
}

///////////////////////////////////////////////////////
bool Vehicle::attachTrailer(Vehicle trailer_)
{
	return sampgdk_AttachTrailerToVehicle(trailer_.id(), _id);
}

///////////////////////////////////////////////////////
bool Vehicle::detachTrailer()
{
	return sampgdk_DetachTrailerFromVehicle(_id);
}

///////////////////////////////////////////////////////
bool Vehicle::isTrailerAttached() const
{
	return sampgdk_IsTrailerAttachedToVehicle(_id);
}

///////////////////////////////////////////////////////
Vehicle Vehicle::getTrailer() const
{
	return Vehicle{ sampgdk_GetVehicleTrailer(_id) };
}

///////////////////////////////////////////////////////
bool Vehicle::setNumberPlate(std::string const& numberplate_)
{
	return this->setNumberPlate(numberplate_.c_str());
}

///////////////////////////////////////////////////////
bool Vehicle::setNumberPlate(char const* numberplate_)
{
	return sampgdk_SetVehicleNumberPlate(_id, numberplate_);
}

///////////////////////////////////////////////////////
Vehicle::Model Vehicle::getModel() const
{
	return static_cast<Model>(sampgdk_GetVehicleModel(_id));
}

///////////////////////////////////////////////////////
int Vehicle::getComponentInSlot(int slot_) const
{
	return sampgdk_GetVehicleComponentInSlot(_id, slot_);
}

///////////////////////////////////////////////////////
int Vehicle::getComponentType(int component_)
{
	return sampgdk_GetVehicleComponentType(component_);
}

///////////////////////////////////////////////////////
bool Vehicle::repair()
{
	return sampgdk_RepairVehicle(_id);
}

///////////////////////////////////////////////////////
Vec3f Vehicle::getVelocity() const
{
	Vec3f result;
	sampgdk_GetVehicleVelocity(_id, &result.x, &result.y, &result.z);
	return result;
}

///////////////////////////////////////////////////////
bool Vehicle::setVelocity(Vec3f const& vel_)
{
	return this->setVelocity(vel_.x, vel_.y, vel_.z);
}

///////////////////////////////////////////////////////
bool Vehicle::setVelocity(float x_, float y_, float z_)
{
	return sampgdk_SetVehicleVelocity(_id, x_, y_, z_);
}

///////////////////////////////////////////////////////
bool Vehicle::setAngularVelocity(Vec3f const& vel_)
{
	return this->setAngularVelocity(vel_.x, vel_.y, vel_.z);
}

///////////////////////////////////////////////////////
bool Vehicle::setAngularVelocity(float x_, float y_, float z_)
{
	return sampgdk_SetVehicleAngularVelocity(_id, x_, y_, z_);
}

///////////////////////////////////////////////////////
bool Vehicle::getDamageStatus(int * panels, int * doors, int * lights, int * tires) const
{
	return sampgdk_GetVehicleDamageStatus(_id, panels, doors, lights, tires);
}

///////////////////////////////////////////////////////
bool Vehicle::updateDamageStatus(int panels_, int doors_, int lights_, int tires_)
{
	return sampgdk_UpdateVehicleDamageStatus(_id, panels_, doors_, lights_, tires_);
}

///////////////////////////////////////////////////////
bool Vehicle::setVirtualWorld(int worldIdx_)
{
	return sampgdk_SetVehicleVirtualWorld(_id, worldIdx_);
}

///////////////////////////////////////////////////////
int Vehicle::getVirtualWorld() const
{
	return sampgdk_GetVehicleVirtualWorld(_id);
}

///////////////////////////////////////////////////////
bool Vehicle::getModelInfo(Model model_, VehicleModelInfo type_, float * X_, float * Y_, float * Z_)
{
	return sampgdk_GetVehicleModelInfo(static_cast<int>(model_), static_cast<int>(type_), X_, Y_, Z_);
}

///////////////////////////////////////////////////////
std::string_view Vehicle::name(Model model_)
{
	return Vehicle::ModelNames[static_cast<int>(model_) - Vehicle::BaseModelIndex];
}

///////////////////////////////////////////////////////
std::string_view Vehicle::prettyName(Model model_)
{
	return Vehicle::PrettyModelNames[static_cast<int>(model_) - Vehicle::BaseModelIndex];
}

///////////////////////////////////////////////////////
std::string_view Vehicle::name() const
{
	return Vehicle::ModelNames[static_cast<int>( this->getModel() ) - Vehicle::BaseModelIndex];
}

///////////////////////////////////////////////////////
std::string_view Vehicle::prettyName() const
{
	return Vehicle::PrettyModelNames[static_cast<int>( this->getModel() ) - Vehicle::BaseModelIndex];
}

}