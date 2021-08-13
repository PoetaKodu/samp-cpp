#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

struct SmartNative
{
	AMX_NATIVE 	native = nullptr;
};

#define DECLARE_SMART_NATIVE(NativeName, Params, CallParams) \
	struct NativeName##_Impl : samp_cpp::SmartNative \
	{ \
		cell operator() Params const \
		{ \
			return ([&](auto&&... args) { return samp_cpp::callNativeOn(native, std::forward<decltype(args)>(args)...); }) CallParams;\
		} \
	};\
	inline NativeName##_Impl NativeName{};

}