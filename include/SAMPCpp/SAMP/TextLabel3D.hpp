#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

namespace samp_cpp
{

class Player;
class Vehicle;

class TextLabel3D
{
public:
	TextLabel3D(int32_t id_)
		: _id(id_)
	{
	}

	static TextLabel3D create(std::string const& text_, Color color_, Vec3f const& pos_, float drawDistance_, int virtualWorld_, bool testLos_);
	static TextLabel3D create(char const* text_, Color color_, float x_, float y_, float z_, float drawDistance_, int virtualWorld_, bool testLos_);
	bool destroy();
	bool attachTo(Player player_, Vec3f const& offset_);
	bool attachTo(Player player_, float offsetX_, float offsetY_, float offsetZ_);
	bool attachTo(Vehicle vehicle_, Vec3f const& offset_);
	bool attachTo(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_);
	bool updateText(Color color_, std::string const& text_);
	bool updateText(Color color_, char const* text_);

private:
	int32_t _id;
};

class PlayerTextLabel3D
{
public:
	PlayerTextLabel3D(Player player_, int32_t id_);

	static PlayerTextLabel3D create(Player player_, std::string const& text_, Color color_, Vec3f const& pos_, float drawDistance_, Player attachedPlayer_, Vehicle attachedVehicle_, bool testLos_);
	static PlayerTextLabel3D create(Player player_, char const* text_, Color color_, float x_, float y_, float z_, float drawDistance_, Player attachedPlayer_, Vehicle attachedVehicle_, bool testLos_);
	bool destroy();
	bool updateText(Color color_, std::string const& text_);
	bool updateText(Color color_, char const* text_);
	

private:
	int32_t _id;
	int32_t _playerId;
};



}