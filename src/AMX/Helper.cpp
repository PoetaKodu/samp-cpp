#include SAMPCPP_PCH

#include <SAMPCpp/AMX/Helper.hpp>

namespace samp_cpp
{

////////////////////////////////
cell amx_NewString(AMX *amx, char const *str, int len)
{
    cell amx_str, *amx_str_phys;
    if (len < 0) len = (int) (strlen(str) + 1);

    amx_Allot(amx, len, &amx_str, &amx_str_phys);
    amx_SetString(amx_str_phys, str, 0, 0, (size_t) len);

    return amx_str;
}

////////////////////////////////
AMX_NATIVE amx_FindNative(AMX *amx, const char *func)
{
    if (!amx) return nullptr;

    int index;
    amx_FindNative(amx, func, &index);
    if (index == 0x7FFFFFFF) return nullptr;

	auto hdr = (AMX_HEADER *) amx->base;
	auto funcstub = (AMX_FUNCSTUB *) ((char *) (hdr) + hdr->natives + hdr->defsize * index);

    return (AMX_NATIVE) funcstub->address;
}

}