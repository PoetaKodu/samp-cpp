#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

cell amx_NewString(AMX *amx, char const *str, int len = -1);

AMX_NATIVE amx_FindNative(AMX *amx, const char *func);

}