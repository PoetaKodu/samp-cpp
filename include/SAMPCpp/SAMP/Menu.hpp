#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class Player;

class Menu
{
public:
	Menu() = default;
	Menu(int32_t id_)
		: _id(id_)
	{
	}

	bool operator==(Menu const& other_) const { return _id == other_._id; }
	bool operator!=(Menu const& other_) const { return !(*this == other_); }

	bool valid() const;

	static Menu create(std::string const& title_, int columns_, Vec2f const& pos_, float col1width_, float col2width_);
	static Menu create(char const* title_, int columns_, float x_, float y_, float col1width_, float col2width_);
	
	bool destroy();

	int addItem(int column_, std::string const& menuText_);
	int addItem(int column_, char const* menuText_);

	bool setColumnHeader(int column_, std::string const& columnHeader_);
	bool setColumnHeader(int column_, char const* columnHeader_);

	bool showForPlayer(Player player_);
	bool hideForPlayer(Player player_);

	bool disable();
	bool disableRow(int row_);

private:
	int32_t _id = -1;
};

}