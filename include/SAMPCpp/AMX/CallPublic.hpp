#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/AMX/ParamStackPush.hpp>

namespace samp_cpp
{

using AmxCollection = std::set<AMX*>;

//////////////////////////////////////
template <typename... TArgs>
inline cell callPublicOn(AMX* amx_, int publicIdx_, TArgs&&... args_)
{
	constexpr int NumPubArgs = sizeof...(TArgs);

	// Array of allocated resources 
	cell resources[NumPubArgs];
	// Initialize resource to -1 (none)
	for(int i = 0; i < NumPubArgs; ++i)
		resources[i] = -1;

	// Push every param in reverse order
	{
		int resourceIdx = 0;
		int unused;
		// This syntax reverses evaluation order of expression unfold
		(unused = ... = (pushAmxParam(amx_, std::forward<TArgs>(args_), resources[resourceIdx++]), 0) );
	}

	// Execute and collect return value:
	cell returnValue;
	amx_Exec(amx_, &returnValue, publicIdx_);

	// Free allocated resources
	for(int i = 0; i < NumPubArgs; ++i)
	{
		if (resources[i] != -1)
			amx_Release(amx_, resources[i]);
	}

	return returnValue;
}

//////////////////////////////////////
template <typename... TArgs>
inline std::optional<cell> callPublicOn(AMX* amx_, char const* publicName_, TArgs&&... args_)
{
	cell publicIdx = -1;

	int result = amx_FindPublic(amx_, publicName_, &publicIdx);

	if (result != AMX_ERR_NONE) {
		return std::nullopt;
	}

	return callPublicOn(amx_, publicIdx, std::forward<TArgs>(args_)...);
}

//////////////////////////////////////
template <typename... TArgs>
inline cell callPublicOn(AmxCollection const& collection_, char const* publicName_, TArgs&&... args_)
{
	size_t numCalled = 0;
	for(auto amx : collection_)
	{
		auto result = callPublicOn(amx, publicName_, std::forward<TArgs>(args_)...);
		if (result.has_value())
			++numCalled;
	}

	return numCalled;
}

}