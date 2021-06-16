#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Menu.hpp>

#include <SAMPCpp/SAMP/Player.hpp>

namespace samp_cpp
{

///////////////////////////////////////////////
Menu Menu::create(std::string const& title_, int columns_, Vec2f const& pos_, float col1width_, float col2width_)
{
	return Menu::create(title_.c_str(), columns_, pos_.x, pos_.y, col1width_, col2width_);
}

///////////////////////////////////////////////
Menu Menu::create(char const* title_, int columns_, float x_, float y_, float col1width_, float col2width_)
{
	return Menu{ sampgdk_CreateMenu(title_, columns_, x_, y_, col1width_, col2width_) };
}

///////////////////////////////////////////////
bool Menu::destroy()
{
	return sampgdk_DestroyMenu(_id);
}

///////////////////////////////////////////////
int Menu::addItem(int column_, std::string const& menuText_)
{
	return this->addItem(column_, menuText_.c_str());
}

///////////////////////////////////////////////
int Menu::addItem(int column_, char const* menuText_)
{
	return sampgdk_AddMenuItem(_id, column_, menuText_);
}

///////////////////////////////////////////////
bool Menu::setColumnHeader(int column_, std::string const& columnHeader_)
{
	return this->setColumnHeader(column_, columnHeader_.c_str());
}

///////////////////////////////////////////////
bool Menu::setColumnHeader(int column_, char const* columnHeader_)
{
	return sampgdk_SetMenuColumnHeader(_id, column_, columnHeader_);
}

///////////////////////////////////////////////
bool Menu::showForPlayer(Player player_)
{
	return sampgdk_ShowMenuForPlayer(_id, player_.id());
}

///////////////////////////////////////////////
bool Menu::hideForPlayer(Player player_)
{
	return sampgdk_HideMenuForPlayer(_id, player_.id());
}

///////////////////////////////////////////////
bool Menu::valid() const
{
	return sampgdk_IsValidMenu(_id);
}

///////////////////////////////////////////////
bool Menu::disable()
{
	return sampgdk_DisableMenu(_id);
}

///////////////////////////////////////////////
bool Menu::disableRow(int row_)
{
	return sampgdk_DisableMenuRow(_id, row_);
}

	
}