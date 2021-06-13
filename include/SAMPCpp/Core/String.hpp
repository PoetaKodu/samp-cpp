#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

template <typename OutputIt>
constexpr OutputIt byteToChars(uint8_t byte_, OutputIt it_)
{
	constexpr const char* digits = "0123456789ABCDEF";
	
	*it_++ = byte_ > 0x0F ? digits[(byte_ >> 4)] : '0';
	*it_++ = digits[byte_ & 0x0F];
	return it_;
}


}