#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/AMX/Helper.hpp>

namespace samp_cpp
{

template <typename T>
inline cell evalAmxParam(AMX* amx_, T value_, cell& resourceCell_) = delete;

template <>
inline cell evalAmxParam<int>(AMX* amx_, int value_, cell& resourceCell_)
{
	return value_;
}

template <>
inline cell evalAmxParam<float>(AMX* amx_, float value_, cell& resourceCell_)
{
	return amx_ftoc(value_);
}

template <>
inline cell evalAmxParam<std::string const&>(AMX* amx_, std::string const& value_, cell& resourceCell_)
{
	cell cellIdx = amx_NewString(amx_, value_.c_str());
	resourceCell_ = cellIdx;
	return cellIdx;
}

template <>
inline cell evalAmxParam<const char*>(AMX* amx_, const char* value_, cell& resourceCell_)
{
	cell cellIdx = amx_NewString(amx_, value_);
	resourceCell_ = cellIdx;
	return cellIdx;
}

}