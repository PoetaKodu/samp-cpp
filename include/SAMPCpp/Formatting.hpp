#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Color.hpp>

namespace samp_cpp
{

namespace details
{

template <typename T>
constexpr std::string parseColoredArg(T) = delete;

template <>
constexpr std::string parseColoredArg<char const*>(char const* str_)
{
	return str_;
}


template <>
constexpr std::string parseColoredArg<std::string>(std::string str_)
{
	return str_;
}

template <>
constexpr std::string parseColoredArg<std::string_view>(std::string_view  str_)
{
	return std::string(str_);
}

template <>
constexpr std::string parseColoredArg<Color>(Color color_)
{
	return "{" + toChatColorString(color_) + "}";
}


}

template <typename... TArgs>
constexpr std::string colored(TArgs const&... args_)
{
	return (details::parseColoredArg(args_) + ...);
}

using ChatFmtColorPair = std::pair<Color, std::string>;

template <typename... TArgs>
constexpr ChatFmtColorPair colored(Color const& chatColor_, TArgs const&... args_)
{
	return { chatColor_, (details::parseColoredArg(args_) + ...) };
}

}