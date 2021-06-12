#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

/// Constexpr version of this code:
/// https://stackoverflow.com/a/33447587
template <typename TInteger>
constexpr std::string intToHexString(TInteger number_, size_t hexLength_ = sizeof(TInteger)<<1)
{
	constexpr const char* digits = "0123456789ABCDEF";

	std::string rc(hexLength_, '0');
	for (size_t i = 0, j = (hexLength_ - 1)*4; i< hexLength_; ++i, j -= 4)
		rc[i] = digits[ (number_ >> j) & 0x0f];

	return rc;
}

}