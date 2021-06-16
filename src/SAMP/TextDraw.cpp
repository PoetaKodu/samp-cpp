#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/TextDraw.hpp>

#include <SAMPCpp/SAMP/Player.hpp>

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
bool TextDraw::setLetterSize(float x_, float y_)
{
	return sampgdk_TextDrawLetterSize(_id, x_, y_);
}

///////////////////////////////////////////////
bool TextDraw::setTextSize(float x_, float y_)
{
	return sampgdk_TextDrawTextSize(_id, x_, y_);
}

///////////////////////////////////////////////
bool TextDraw::setAlignment(int alignment_)
{
	return sampgdk_TextDrawAlignment(_id, alignment_);
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
bool TextDraw::setShadow(int size_)
{
	return sampgdk_TextDrawSetShadow(_id, size_);
}

///////////////////////////////////////////////
bool TextDraw::setOutline(int size_)
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
bool TextDraw::setString(char const* string_)
{
	return sampgdk_TextDrawSetString(_id, string_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewModel(int modelIndex_)
{
	return sampgdk_TextDrawSetPreviewModel(_id, modelIndex_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewRot(float rotX_, float rotY_, float rotZ_, float zoom_)
{
	return sampgdk_TextDrawSetPreviewRot(_id, rotX_, rotY_, rotZ_, zoom_);
}

///////////////////////////////////////////////
bool TextDraw::setPreviewVehCol(Color color1_, Color color2_)
{
	return sampgdk_TextDrawSetPreviewVehCol(_id, color1_, color2_);
}

}