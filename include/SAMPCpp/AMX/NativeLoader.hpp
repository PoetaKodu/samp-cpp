#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/AMX/SmartNative.hpp>

namespace samp_cpp
{

struct NativeLoader
{
public:
	using NativeMap = std::map<std::string, SmartNative *>;

	NativeLoader() = default;
	NativeLoader(NativeMap natives_)
		: natives(std::move(natives_))
	{
	}

	bool load(AMX* amx_, char const* nativeName_);
	size_t loadFromAmx(AMX* amx_);

	NativeMap natives;
};

}