#include SAMPCPP_PCH

#include <SAMPCpp/AMX/Helper.hpp>
#include <SAMPCpp/AMX/NativeLoader.hpp>

namespace samp_cpp
{

////////////////////////////////////
bool NativeLoader::load(AMX* amx_, char const* nativeName_)
{
	auto it = natives.find(nativeName_);
	
	if (it == natives.end() || it->second->native != nullptr)
		return false;
			
	it->second->native = sampgdk_FindNative(nativeName_);
	if (it->second->native == nullptr)
		return false;

	return true;
}

}