#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

namespace samp_cpp
{

class Player;

enum class TextDrawFontType
{
	SpriteDraw		= 4,
	ModelPreview	= 5,
};

class TextDraw
{
public:
	TextDraw(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(TextDraw const& other_) const { return _id == other_._id; }
	bool operator!=(TextDraw const& other_) const { return !(*this == other_); }

	int32_t id() const { return _id; }


	static TextDraw create(Vec2f const& pos_, std::string const& text_);
	static TextDraw create(float x_, float y_, char const* text_);
	bool destroy();
	bool setLetterSize(float x_, float y_);
	bool setTextSize(float x_, float y_);
	bool setAlignment(int alignment_);
	bool setColor(Color color_);
	bool setUseBox(bool use_);
	bool setBoxColor(Color color_);
	bool setShadow(int size_);
	bool setOutline(int size_);
	bool setBackgroundColor(Color color_);
	bool setFont(int font_);
	bool setProportional(bool set_);
	bool setSelectable(bool set_);
	bool showForPlayer(Player player_);
	bool hideForPlayer(Player player_);
	bool showForAll();
	bool hideForAll();
	bool setString(char const* string_);
	bool setPreviewModel(int modelIndex_);
	bool setPreviewRot(float rotX_, float rotY_, float rotZ_, float zoom_);
	bool setPreviewVehCol(Color color1_, Color color2_);

private:
	int32_t _id;
};

}