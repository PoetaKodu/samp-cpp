#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Core/Color.hpp>

namespace samp_cpp
{

namespace details
{

template <typename Type>
struct ColoredArgParser;
template <>
struct ColoredArgParser<const char*>
{
	template <typename OutputIt>
	static constexpr OutputIt parse(const char* value_, OutputIt it_)
	{
		if (value_ == nullptr)
			return it_;

		for(auto c = value_; *c != '\0'; ++c)
			*it_++ = *c;

		return it_;
	}
};

template <>
struct ColoredArgParser<Color>
{
	template <typename OutputIt>
	static constexpr OutputIt parse(Color value_, OutputIt it_)
	{
		*it_++ = '{';
		it_ = toChatColorChars(value_, it_);
		*it_++ = '}';
		return it_; 
	}
};

template <>
struct ColoredArgParser<std::string_view>
{
	template <typename OutputIt>
	static constexpr OutputIt parse(std::string_view value_, OutputIt it_)
	{
		return ColoredArgParser<const char*>::parse(value_.data(), it_);
	}
};

template <>
struct ColoredArgParser<std::string>
{
	template <typename OutputIt>
	static OutputIt parse(std::string value_, OutputIt it_)
	{
		for(size_t i = 0; i < value_.size(); ++i)
			*it_++ = value_[i];

		return it_;
	}
};

template <typename T, typename OutputIt>
inline OutputIt parseArg(T value_, OutputIt it_)
{
	return ColoredArgParser<T>::parse(value_, it_);
}


}

template <typename... TArgs>
std::string colored(TArgs const&... args_)
{
	std::string str;
	str.reserve(1024);

	// Requires left to right evaluation order
	std::initializer_list{ details::parseArg(args_, std::back_inserter(str))... };
	str.shrink_to_fit();
	return str;
}

using ChatFmtColorPair 		= std::pair<Color, std::string>;

template <typename... TArgs>
constexpr ChatFmtColorPair colored(Color const& chatColor_, TArgs const&... args_)
{
	return { chatColor_, colored(args_...) };
}

}