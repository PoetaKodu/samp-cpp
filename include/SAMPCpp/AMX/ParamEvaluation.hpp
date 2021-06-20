#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/AMX/Helper.hpp>

namespace samp_cpp
{

template <typename T>
inline cell evalAmxParam(AMX* amx_, T value_, cell& resourceCell_, cell*& physicalAddress_) = delete;

template <>
inline cell evalAmxParam<int>(AMX* amx_, int value_, cell& resourceCell_, cell*& physicalAddress_)
{
	return value_;
}

template <>
inline cell evalAmxParam<int*>(AMX* amx_, int* value_, cell& resourceCell_, cell*& physicalAddress_)
{
	amx_Allot(amx_, 1, &resourceCell_, &physicalAddress_);
	return resourceCell_;
}

template <>
inline cell evalAmxParam<float>(AMX* amx_, float value_, cell& resourceCell_, cell*& physicalAddress_)
{
	return amx_ftoc(value_);
}

template <>
inline cell evalAmxParam<float*>(AMX* amx_, float* value_, cell& resourceCell_, cell*& physicalAddress_)
{
	amx_Allot(amx_, 1, &resourceCell_, &physicalAddress_);
	return resourceCell_;
}

template <>
inline cell evalAmxParam<std::string const&>(AMX* amx_, std::string const& value_, cell& resourceCell_, cell*& physicalAddress_)
{
	resourceCell_ = amx_NewString(amx_, value_.c_str());
	return resourceCell_;
}

template <>
inline cell evalAmxParam<const char*>(AMX* amx_, const char* value_, cell& resourceCell_, cell*& physicalAddress_)
{
	resourceCell_ = amx_NewString(amx_, value_);
	return resourceCell_;
}





template <typename T>
inline void handlePhysicalAddress(T value_, cell* physicalAddress_) = delete;

template <>
inline void handlePhysicalAddress<int>(int value_, cell* physicalAddress_)
{
}

template <>
inline void handlePhysicalAddress<int*>(int* value_, cell* physicalAddress_)
{
	*value_ = *physicalAddress_;
}

template <>
inline void handlePhysicalAddress<float>(float value_, cell* physicalAddress_)
{
}

template <>
inline void handlePhysicalAddress<float*>(float* value_, cell* physicalAddress_)
{
	*value_ = *reinterpret_cast<float*>(physicalAddress_);
}

template <>
inline void handlePhysicalAddress<std::string const&>(std::string const& value_, cell* physicalAddress_)
{
}

template <>
inline void handlePhysicalAddress<const char*>(const char* value_, cell* physicalAddress_)
{
}

}