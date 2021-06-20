#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/TextDraw.hpp>

#include <SAMPCpp/SAMP/Player.hpp>
#include <SAMPCpp/Core/TextAlign.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////
TextDraw TextDraw::create(Vec2f const& pos_, std::string const& text_)
{
	return TextDraw::create(pos_.x, pos_.y, text_.c_str());
}

///////////////////////////////////////////////
TextDraw TextDraw::create(float x_, float y_, char const* text_)
{
	return sampgdk_TextDrawCreate(x_, y_, text_);
}

///////////////////////////////////////////////
bool TextDraw::destroy()
{
	return sampgdk_TextDrawDestroy(_id);
}

///////////////////////////////////////////////
bool TextDraw::setLetterSize(Vec2f const& size_)
{
	return this->setLetterSize(size_.x, size_.y);
}

///////////////////////////////////////////////
bool TextDraw::setLetterSize(float x_, float y_)
{
	return sampgdk_TextDrawLetterSize(_id, x_, y_);
}

///////////////////////////////////////////////
bool TextDraw::setTextSize(Vec2f const& size_)
{
	return this->setTextSize(size_.x, size_.y);
}

///////////////////////////////////////////////
bool TextDraw::setTextSize(float x_, float y_)
{
	return sampgdk_TextDrawTextSize(_id, x_, y_);
}

///////////////////////////////////////////////
bool TextDraw::setAlignment(TextAlign alignment_)
{
	return sampgdk_TextDrawAlignment(_id, toTextDrawTextAlign(alignment_));
}

///////////////////////////////////////////////
bool TextDraw::setColor(Color color_)
{
	return sampgdk_TextDrawColor(_id, color_);
}

///////////////////////////////////////////////
bool TextDraw::setUseBox(bool use_)
{
	return sampgdk_TextDrawUseBox(_id, use_);
}

///////////////////////////////////////////////
bool TextDraw::setBoxColor(Color color_)
{
	return sampgdk_TextDrawBoxColor(_id, color_);
}

///////////////////////////////////////////////
bool TextDraw::setShadowSize(int size_)
{
	return sampgdk_TextDrawSetShadow(_id, size_);
}

///////////////////////////////////////////////
bool TextDraw::setOutlineSize(int size_)
{
	return sampgdk_TextDrawSetOutline(_id, size_);
}

///////////////////////////////////////////////
bool TextDraw::setBackgroundColor(Color color_)
{
	return sampgdk_TextDrawBackgroundColor(_id, color_);
}

///////////////////////////////////////////////
bool TextDraw::setFont(int font_)
{
	return sampgdk_TextDrawFont(_id, font_);
}

///////////////////////////////////////////////
bool TextDraw::setProportional(bool set_)
{
	return sampgdk_TextDrawSetProportional(_id, set_);
}

///////////////////////////////////////////////
bool TextDraw::setSelectable(bool set_)
{
	return sampgdk_TextDrawSetSelectable(_id, set_);
}

///////////////////////////////////////////////
bool TextDraw::showForPlayer(Player player_)
{
	return sampgdk_TextDrawShowForPlayer(player_.id(), _id);
}

///////////////////////////////////////////////
bool TextDraw::hideForPlayer(Player player_)
{
	return sampgdk_TextDrawHideForPlayer(player_.id(), _id);
}

///////////////////////////////////////////////
bool TextDraw::showForAll()
{
	return sampgdk_TextDrawShowForAll(_id);
}

///////////////////////////////////////////////
bool TextDraw::hideForAll()
{
	return sampgdk_TextDrawHideForAll(_id);
}

///////////////////////////////////////////////
bool TextDraw::setString(std::string const& string_)
{
	return this->setString(string_.c_str());
}

///////////////////////////////////////////////
bool TextDraw::setString(char const* string_)
{
	return sampgdk_TextDrawSetString(_id, string_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewModel(Vehicle::Model model_)
{
	return this->setPreviewModel(static_cast<int>(model_));
}

///////////////////////////////////////////////
bool TextDraw::setPreviewModel(int modelIndex_)
{
	return sampgdk_TextDrawSetPreviewModel(_id, modelIndex_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewRot(Vec3f const& rot_, float zoom_)
{
	return this->setPreviewRot(rot_.x, rot_.y, rot_.z, zoom_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewRot(float rotX_, float rotY_, float rotZ_, float zoom_)
{
	return sampgdk_TextDrawSetPreviewRot(_id, rotX_, rotY_, rotZ_, zoom_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewVehCol(int color1_, int color2_)
{
	return sampgdk_TextDrawSetPreviewVehCol(_id, color1_, color2_);
}


////////////////////////////////////////////////////////
PlayerTextDraw::PlayerTextDraw(Player player_, int32_t id_)
	: _id(id_), _playerId(player_.id())
{
}

////////////////////////////////////////////////////////
Player PlayerTextDraw::owner() const
{
	return Player{ _playerId };
}

////////////////////////////////////////////////////////
PlayerTextDraw PlayerTextDraw::create(Player player_, Vec2f const& pos_, std::string const& text_)
{
	return PlayerTextDraw::create(player_, pos_.x, pos_.y, text_.c_str());
}

////////////////////////////////////////////////////////
PlayerTextDraw PlayerTextDraw::create(Player player_, float x_, float y_, char const* text_)
{
	return PlayerTextDraw{ player_, sampgdk_CreatePlayerTextDraw(player_.id(), x_, y_, text_) };
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::destroy()
{
	return sampgdk_PlayerTextDrawDestroy(_playerId, _id);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setLetterSize(Vec2f const& size_)
{
	return this->setLetterSize(size_.x, size_.y);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setLetterSize(float x_, float y_)
{
	return sampgdk_PlayerTextDrawLetterSize(_playerId, _id, x_, y_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setTextSize(Vec2f const& size_)
{
	return this->setTextSize(size_.x, size_.y);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setTextSize(float x_, float y_)
{
	return sampgdk_PlayerTextDrawTextSize(_playerId, _id, x_, y_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setAlignment(TextAlign alignment_)
{
	return sampgdk_PlayerTextDrawAlignment(_playerId, _id, toTextDrawTextAlign(alignment_));
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setColor(Color color_)
{
	return sampgdk_PlayerTextDrawColor(_playerId, _id, color_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setUseBox(bool use_)
{
	return sampgdk_PlayerTextDrawUseBox(_playerId, _id, use_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setBoxColor(Color color_)
{
	return sampgdk_PlayerTextDrawBoxColor(_playerId, _id, color_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setShadowSize(int size_)
{
	return sampgdk_PlayerTextDrawSetShadow(_playerId, _id, size_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setOutlineSize(int size_)
{
	return sampgdk_PlayerTextDrawSetOutline(_playerId, _id, size_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setBackgroundColor(Color color_)
{
	return sampgdk_PlayerTextDrawBackgroundColor(_playerId, _id, color_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setFont(int font_)
{
	return sampgdk_PlayerTextDrawFont(_playerId, _id, font_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setProportional(bool set_)
{
	return sampgdk_PlayerTextDrawSetProportional(_playerId, _id, set_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setSelectable(bool set_)
{
	return sampgdk_PlayerTextDrawSetSelectable(_playerId, _id, set_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::show()
{
	return sampgdk_PlayerTextDrawShow(_playerId, _id);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::hide()
{
	return sampgdk_PlayerTextDrawHide(_playerId, _id);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setString(std::string const& string_)
{
	return this->setString(string_.c_str());
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setString(char const* string_)
{
	return sampgdk_PlayerTextDrawSetString(_playerId, _id, string_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setPreviewModel(Vehicle::Model model_)
{
	return this->setPreviewModel(static_cast<int>(model_));
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setPreviewModel(int modelIndex_)
{
	return sampgdk_PlayerTextDrawSetPreviewModel(_playerId, _id, modelIndex_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setPreviewRot(Vec3f const& rot_, float zoom_)
{
	return this->setPreviewRot(rot_.x, rot_.y, rot_.z, zoom_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setPreviewRot(float rotX_, float rotY_, float rotZ_, float zoom_)
{
	return sampgdk_PlayerTextDrawSetPreviewRot(_playerId, _id, rotX_, rotY_, rotZ_, zoom_);
}

////////////////////////////////////////////////////////
bool PlayerTextDraw::setPreviewVehCol(int color1_, int color2_)
{
	return sampgdk_PlayerTextDrawSetPreviewVehCol(_playerId, _id, color1_, color2_);
}



}