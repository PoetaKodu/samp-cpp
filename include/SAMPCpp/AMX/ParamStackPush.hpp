#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/AMX/Helper.hpp>

namespace samp_cpp
{


template <typename T>
inline void pushAmxParam(AMX* amx_, T value_, cell& resourceCell_) = delete;

template <>
inline void pushAmxParam<int>(AMX* amx_, int value_, cell& resourceCell_)
{
	amx_Push(amx_, value_);
}

template <>
inline void pushAmxParam<float>(AMX* amx_, float value_, cell& resourceCell_)
{
	amx_Push(amx_, amx_ftoc(value_));
}

template <>
inline void pushAmxParam<std::string const&>(AMX* amx_, std::string const& value_, cell& resourceCell_)
{
	cell* physAddr;
	amx_PushString(amx_, &resourceCell_, &physAddr, value_.c_str(), 0, 0);
}

template <>
inline void pushAmxParam<const char*>(AMX* amx_, const char* value_, cell& resourceCell_)
{
	cell* physAddr;
	amx_PushString(amx_, &resourceCell_, &physAddr, value_, 0, 0);
}

}