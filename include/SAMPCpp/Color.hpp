#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

struct Color
{
	uint32_t value = 0;

	constexpr Color() = default;

	constexpr Color(uint32_t value_)
		: value(value_)
	{
	}

	constexpr Color(int32_t value_)
		: value(static_cast<uint32_t>(value_))
	{
	}

	constexpr Color(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_ = 255)
		:
		value(
			int32_t(a_) + 
			(int32_t(b_) << (1*8)) +
			(int32_t(g_) << (2*8)) +
			(int32_t(r_) << (3*8))
		)
	{
	}

	constexpr uint8_t r() const { return value & 0xFF000000; }
	constexpr uint8_t g() const { return value & 0x00FF0000; }
	constexpr uint8_t b() const { return value & 0x0000FF00; }
	constexpr uint8_t a() const { return value & 0x000000FF; }

	constexpr void set(uint8_t r_, uint8_t g_, uint8_t b_, uint8_t a_ = 255)
	{
		value = int32_t(a_) + 
			(int32_t(b_) << (1*8)) +
			(int32_t(g_) << (2*8)) +
			(int32_t(r_) << (3*8));
	}

	constexpr void r(uint8_t newValue_)
	{
		value = (value & 0x00FFFFFF) + (uint32_t(newValue_) << (3 * 8));
	}
	constexpr void g(uint8_t newValue_)
	{
		value = (value & 0xFF00FFFF) + (uint32_t(newValue_) << (2 * 8));
	}
	constexpr void b(uint8_t newValue_)
	{
		value = (value & 0xFFFF00FF) + (uint32_t(newValue_) << (1 * 8));
	}
	constexpr void a(uint8_t newValue_)
	{
		value = (value & 0xFFFFFF00) + (uint32_t(newValue_));
	}

	constexpr Color argb() const {
		return Color{ a(), r(), g(), b() };
	}

	constexpr Color fromArgb() const {
		return Color{ g(), b(), a(), r() };
	}

	constexpr operator uint32_t() const { return value; }
	constexpr operator int32_t() const 	{ return static_cast<int32_t>(value); }
};

namespace colors
{

constexpr Color red 			= 0xFF0000FF;
constexpr Color green 			= 0x00FF00FF;
constexpr Color blue 			= 0x0000FFFF;

constexpr Color white 			= 0xFFFFFFFF;
constexpr Color black 			= 0x000000FF;
constexpr Color transparent		= 0xFFFFFF00;

constexpr Color yellow			= 0xFFFF00FF;
constexpr Color cyan			= 0x00FFFFFF;
constexpr Color magenta			= 0xFF00FFFF;

}

}