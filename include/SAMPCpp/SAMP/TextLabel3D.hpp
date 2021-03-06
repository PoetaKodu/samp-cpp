#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

#include <SAMPCpp/SAMP/Player.hpp>
#include <SAMPCpp/SAMP/Vehicle.hpp>

namespace samp_cpp
{

class TextLabel3D
{
public:
	TextLabel3D() = default;
	TextLabel3D(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(TextLabel3D const& other_) const { return _id == other_._id; }
	bool operator!=(TextLabel3D const& other_) const { return !(*this == other_); }

	static TextLabel3D create(std::string const& text_, Color color_, Vec3f const& pos_, float drawDistance_ = 100, int virtualWorld_ = 0, bool testLos_ = true);
	static TextLabel3D create(char const* text_, Color color_, float x_, float y_, float z_, float drawDistance_ = 100, int virtualWorld_ = 0, bool testLos_ = true);
	bool destroy();
	bool attachTo(Player player_, Vec3f const& offset_);
	bool attachTo(Player player_, float offsetX_, float offsetY_, float offsetZ_);
	bool attachTo(Vehicle vehicle_, Vec3f const& offset_);
	bool attachTo(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_);
	bool updateText(Color color_, std::string const& text_);
	bool updateText(Color color_, char const* text_);

private:
	int32_t _id = -1;
};

class PlayerTextLabel3D
{
public:
	PlayerTextLabel3D() = default;
	PlayerTextLabel3D(Player player_, int32_t id_);

	bool operator==(PlayerTextLabel3D const& other_) const { return _id == other_._id && _playerId == other_._playerId; }
	bool operator!=(PlayerTextLabel3D const& other_) const { return !(*this == other_); }

	static PlayerTextLabel3D create(Player player_, std::string const& text_, Color color_, Vec3f const& pos_, float drawDistance_ = 100, Player attachedPlayer_ = {}, Vehicle attachedVehicle_ = {}, bool testLos_ = true);
	static PlayerTextLabel3D create(Player player_, char const* text_, Color color_, float x_, float y_, float z_, float drawDistance_ = 100, Player attachedPlayer_ = {}, Vehicle attachedVehicle_ = {}, bool testLos_ = true);
	bool destroy();
	bool updateText(Color color_, std::string const& text_);
	bool updateText(Color color_, char const* text_);
	

private:
	int32_t _id = -1, _playerId = -1;
};

}