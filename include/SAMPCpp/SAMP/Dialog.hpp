#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

class Dialog
{
public:
	enum Style
	{
		MessageBox		= 0,
		Input			= 1,
		List			= 2,
		Password		= 3,
		TabList			= 4,
		TabListHeaders	= 5,
	};

	enum Response
	{
		Right 	= 0,
		Left  	= 1,
		Default = 1,
		Cancel 	= 0,
		Return 	= 1,
	};


	Dialog() = default;
	~Dialog() = default;

	virtual bool onResponseInternal(Response response_, int listItem_, char const* inputText_) = 0;

	Style style() const { return _style; }

	int					id = 1;
	std::string_view 	caption;
	std::string_view 	text;
	std::string_view 	buttons[2];
protected:
	Style 				_style;
};

using DialogStyle = Dialog::Style;

class MessageBox
	: public Dialog
{
public:
	MessageBox() {
		_style = Dialog::MessageBox;
	}

	virtual bool onResponseInternal(Response response_, int listItem_, char const* inputText_)
	{
		return this->onResponse(response_);
	}

	virtual bool onResponse(Response response_) { return false; }
};

class TextBoxBase
	: public Dialog
{
public:
	virtual bool onResponseInternal(Response response_, int listItem_, char const* inputText_)
	{
		return this->onResponse(response_, std::string_view(inputText_, strlen(inputText_)) );
	}

	virtual bool onResponse(Response response_, std::string_view inputText_) { return false; }
};

class InputBox
	: public TextBoxBase
{
public:
	InputBox() {
		_style = Dialog::Input;
	}
};

class PasswordBox
	: public TextBoxBase
{
public:
	PasswordBox() {
		_style = Dialog::Password;
	}
};

class ListBoxBase
	: public Dialog
{
public:
	virtual bool onResponseInternal(Response response_, int listItem_, char const* inputText_)
	{
		return this->onResponse(response_, listItem_);
	}

	virtual bool onResponse(Response response_, int listItem_) { return false; }
};

class ListBox
	: public ListBoxBase
{
public:
	ListBox() {
		_style = Dialog::List;
	}
};

class TabListBox
	: public ListBoxBase
{
public:
	TabListBox() {
		_style = Dialog::TabList;
	}
};

class TabListBoxHeaders
	: public ListBoxBase
{
public:
	TabListBoxHeaders() {
		_style = Dialog::TabListHeaders;
	}
};


}