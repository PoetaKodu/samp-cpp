#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

#include <SAMPCpp/SAMP/Vehicle.hpp>


namespace samp_cpp
{

class Player;

enum class TextDrawAlign
{
	Left 	= 1,
	Center 	= 2,
	Right 	= 3,
};

enum class TextDrawFontType
{
	SpriteDraw		= 4,
	ModelPreview	= 5,
};

class TextDraw
{
public:
	TextDraw() = default;

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
	bool setLetterSize(Vec2f const& size_);
	bool setLetterSize(float x_, float y_);
	bool setTextSize(Vec2f const& size_);
	bool setTextSize(float x_, float y_);
	bool setAlignment(TextDrawAlign alignment_);
	bool setColor(Color color_);
	bool setUseBox(bool use_);
	bool setBoxColor(Color color_);
	bool setShadowSize(int size_);
	bool setOutlineSize(int size_);
	bool setBackgroundColor(Color color_);
	bool setFont(int font_);
	bool setProportional(bool set_);
	bool setSelectable(bool set_);
	bool showForPlayer(Player player_);
	bool hideForPlayer(Player player_);
	bool showForAll();
	bool hideForAll();
	bool setString(std::string const& string_);
	bool setString(char const* string_);
	bool setPreviewModel(Vehicle::Model model_);
	bool setPreviewModel(int modelIndex_);
	bool setPreviewRot(Vec3f const& rot_, float zoom_);
	bool setPreviewRot(float rotX_, float rotY_, float rotZ_, float zoom_);
	bool setPreviewVehCol(int color1_, int color2_);

private:
	int32_t _id = -1;
};

class PlayerTextDraw
{
public:
	PlayerTextDraw() = default;
	PlayerTextDraw(Player player_, int32_t id_);

	bool operator==(PlayerTextDraw const& other_) const { return (_playerId == other_._playerId && _id == other_._id); }
	bool operator!=(PlayerTextDraw const& other_) const { return !(*this == other_); }


	int32_t id() const { return _id; }
	Player owner() const;

	static PlayerTextDraw create(Player player_, Vec2f const& pos_, std::string const& text_);
	static PlayerTextDraw create(Player player_, float x_, float y_, char const* text_);
	bool destroy();
	bool setLetterSize(Vec2f const& size_);
	bool setLetterSize(float x_, float y_);
	bool setTextSize(Vec2f const& size_);
	bool setTextSize(float x_, float y_);
	bool setAlignment(TextDrawAlign alignment_);
	bool setColor(Color color_);
	bool setUseBox(bool use_);
	bool setBoxColor(Color color_);
	bool setShadowSize(int size_);
	bool setOutlineSize(int size_);
	bool setBackgroundColor(Color color_);
	bool setFont(int font_);
	bool setProportional(bool set_);
	bool setSelectable(bool set_);
	bool show();
	bool hide();
	bool setString(std::string const& string_);
	bool setString(char const* string_);
	bool setPreviewModel(Vehicle::Model model_);
	bool setPreviewModel(int modelIndex_);
	bool setPreviewRot(Vec3f const& rot_, float zoom_);
	bool setPreviewRot(float rotX_, float rotY_, float rotZ_, float zoom_);
	bool setPreviewVehCol(int color1_, int color2_);

private:
	int32_t _id = -1, _playerId = -1;
};

}