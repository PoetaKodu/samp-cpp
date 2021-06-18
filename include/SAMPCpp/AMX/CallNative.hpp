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

	// Array of allocated resources 
	cell resources[NumNativeArgs];
	// Initialize resource to -1 (none)
	for(int i = 0; i < NumNativeArgs; ++i)
		resources[i] = -1;

	// Prepare native parameters array:
	cell params[NumNativeArgs + 1];
	// First param is required to contain information about total params size:
	params[0] = sizeof(params) - sizeof(cell);

	// Evaluate all parameters to `params` array, in order:
	{
		int paramIdx	= 1;
		int resourceIdx	= 0;

		using Expander = int[];
		// Initializer list to expand in order
		Expander{ ((params[paramIdx++] = evalAmxParam(amx_, std::forward<TArgs>(args_), resources[resourceIdx++])), 0)... };
	}

	// Execute and collect return value
	cell returnValue = native(amx_, params);

	// Free allocated resources:
	for(int i = 0; i < NumNativeArgs; ++i)
	{
		if (resources[i] != -1)
			amx_Release(amx_, resources[i]);
	}

	return returnValue;
}


}