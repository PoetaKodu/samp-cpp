#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/TextLabel3D.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////
TextLabel3D TextLabel3D::create(std::string const& text_, Color color_, Vec3f const& pos_, float drawDistance_, int virtualWorld_, bool testLos_)
{
	return TextLabel3D::create(text_.c_str(), color_, pos_.x, pos_.y, pos_.z, drawDistance_, virtualWorld_, testLos_);
}

///////////////////////////////////////////////
TextLabel3D TextLabel3D::create(char const* text_, Color color_, float x_, float y_, float z_, float drawDistance_, int virtualWorld_, bool testLos_)
{
	return TextLabel3D{ sampgdk_Create3DTextLabel(text_, color_, x_, y_, z_, drawDistance_, virtualWorld_, testLos_) };
}

///////////////////////////////////////////////
bool TextLabel3D::destroy()
{
	return sampgdk_Delete3DTextLabel(_id);
}

///////////////////////////////////////////////
bool TextLabel3D::attachTo(Player player_, Vec3f const& offset_)
{
	return this->attachTo(player_, offset_.x, offset_.y, offset_.z);
}

///////////////////////////////////////////////
bool TextLabel3D::attachTo(Player player_, float offsetX_, float offsetY_, float offsetZ_)
{
	return sampgdk_Attach3DTextLabelToPlayer(_id, player_.id(), offsetX_, offsetY_, offsetZ_);
}

///////////////////////////////////////////////
bool TextLabel3D::attachTo(Vehicle vehicle_, Vec3f const& offset_)
{
	return this->attachTo(vehicle_, offset_.x, offset_.y, offset_.z);
}

///////////////////////////////////////////////
bool TextLabel3D::attachTo(Vehicle vehicle_, float offsetX_, float offsetY_, float offsetZ_)
{
	return sampgdk_Attach3DTextLabelToVehicle(_id, vehicle_.id(), offsetX_, offsetY_, offsetZ_);
}

///////////////////////////////////////////////
bool TextLabel3D::updateText(Color color_, std::string const& text_)
{
	return this->updateText(color_, text_.c_str());
}

///////////////////////////////////////////////
bool TextLabel3D::updateText(Color color_, char const* text_)
{
	return sampgdk_Update3DTextLabelText(_id, color_, text_);
}



///////////////////////////////////////////////
PlayerTextLabel3D::PlayerTextLabel3D(Player player_, int32_t id_)
	: _id(id_), _playerId(player_.id())
{
}

///////////////////////////////////////////////
PlayerTextLabel3D PlayerTextLabel3D::create(Player player_, std::string const& text_, Color color_, Vec3f const& pos_, float drawDistance_, Player attachedPlayer_, Vehicle attachedVehicle_, bool testLos_)
{
	return PlayerTextLabel3D::create(player_, text_.c_str(), color_, pos_.x, pos_.y, pos_.z, drawDistance_, attachedPlayer_, attachedVehicle_, testLos_);
}

///////////////////////////////////////////////
PlayerTextLabel3D PlayerTextLabel3D::create(Player player_, char const* text_, Color color_, float x_, float y_, float z_, float drawDistance_, Player attachedPlayer_, Vehicle attachedVehicle_, bool testLos_)
{
	return PlayerTextLabel3D{ player_, sampgdk_CreatePlayer3DTextLabel(player_.id(), text_, color_, x_, y_, z_, drawDistance_, attachedPlayer_.id(), attachedVehicle_.id(), testLos_) };
}

///////////////////////////////////////////////
bool PlayerTextLabel3D::destroy()
{
	return sampgdk_DeletePlayer3DTextLabel(_playerId, _id);
}

///////////////////////////////////////////////
bool PlayerTextLabel3D::updateText(Color color_, std::string const& text_)
{
	return this->updateText(color_, text_.c_str());
}

///////////////////////////////////////////////
bool PlayerTextLabel3D::updateText(Color color_, char const* text_)
{
	return sampgdk_UpdatePlayer3DTextLabelText(_playerId, _id, color_, text_);
}


}