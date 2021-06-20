#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/AMX/ParamEvaluation.hpp>

namespace samp_cpp
{

//////////////////////////////////////
template <typename... TArgs>
inline cell callNativeOn(AMX* amx_, AMX_NATIVE native, TArgs&&... args_)
{
	constexpr int NumNativeArgs = sizeof...(TArgs);
	using Expander = int[];

	// Array of allocated resources 
	cell resources[NumNativeArgs];

	// Array of physical addreses 
	cell* physicalAddresses[NumNativeArgs];

	// Initialize resource to -1 (none)
	for(int i = 0; i < NumNativeArgs; ++i)
	{
		resources[i] = -1;
		physicalAddresses[i] = nullptr;
	}

	// Prepare native parameters array:
	cell params[NumNativeArgs + 1];
	// First param is required to contain information about total params size:
	params[0] = sizeof(params) - sizeof(cell);

	// Evaluate all parameters to `params` array, in order:
	{
		int paramIdx		= 1;
		int resourceIdx		= 0;
		int physicalAddrIdx	= 0;

		// Initializer list to expand in order
		Expander{ ((params[paramIdx++] = evalAmxParam(amx_,
				std::forward<TArgs>(args_),
				resources[resourceIdx++],
				physicalAddresses[physicalAddrIdx++]
			)), 0)... };
	}

	// Execute and collect return value
	cell returnValue = native(amx_, params);

	// Handle physical addresses (used when using pointers)
	{
		int paramIdx		= 1;
		int resourceIdx		= 0;
		int physicalAddrIdx	= 0;
		
		// Initializer list to expand in order
		Expander{ ((handlePhysicalAddress(
				std::forward<TArgs>(args_),
				physicalAddresses[physicalAddrIdx++]
			)), 0)... };
	}

	// Free allocated resources:
	for(int i = 0; i < NumNativeArgs; ++i)
	{
		if (resources[i] != -1)
			amx_Release(amx_, resources[i]);
	}

	return returnValue;
}


}