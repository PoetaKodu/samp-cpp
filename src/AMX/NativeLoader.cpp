#include SAMPCPP_PCH

#include <SAMPCpp/AMX/Helper.hpp>
#include <SAMPCpp/AMX/NativeLoader.hpp>

namespace samp_cpp
{

////////////////////////////////////
bool NativeLoader::load(AMX* amx_, char const* nativeName_)
{
	auto it = natives.find(nativeName_);
	
	if (it == natives.end() || it->second->amx != nullptr)
		return false;
			
	it->second->native = amx_FindNative(amx_, nativeName_);
	if (it->second->native == nullptr)
		return false;

	it->second->amx = amx_;
	return true;
}

////////////////////////////////////
size_t NativeLoader::loadFromAmx(AMX* amx_)
{
	size_t loaded = 0;

	int numNatives;
	if (amx_NumNatives(amx_, &numNatives) == AMX_ERR_NONE)
	{
		for(int i = 0; i < numNatives; i++)
		{
			char nativeName[64]{};
			if (amx_GetNative(amx_, i, nativeName) == AMX_ERR_NONE)
			{
				if (this->load(amx_, nativeName))
					++loaded;
			}
		}
	}

	return loaded;
}

}