#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

struct nstring : std::string
{
	using std::string::string;
};

}

namespace samp_cpp::native
{

template<typename T>
struct FuncArgs;

template<typename Result, typename... Args>
struct FuncArgs<Result(Args...)>
{
    using Types = std::tuple<Args...>;
};


template <typename T>
static T parse(AMX* amx_, cell* args_, size_t & baseIndex_) = delete;

template <>
static int parse<int>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	return args_[baseIndex_++];
}

template <>
static float parse<float>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	return amx_ctof(args_[baseIndex_++]);
}

template <>
static std::string parse<std::string>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	cell* str = nullptr;
	
	amx_GetAddr(amx_, args_[baseIndex_++], &str);
	if (!str)
		return {};
	
	int len = 0;
	amx_StrLen(str, &len);

	std::string result;
	if (len > 0)
	{
		result.resize(len - 1);
		amx_GetString(&result[0], str, false, len + 1);
	}

	return result;
}

template <>
static nstring parse<nstring>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	cell* str = nullptr;
	
	amx_GetAddr(amx_, args_[baseIndex_++], &str);
	if (!str)
		return {};
	
	int len = args_[baseIndex_++];

	nstring result;
	if (len > 0)
	{
		result.resize(len);
		for(int i = 0; i < len; ++i)
			result[i] = reinterpret_cast<char*>(str)[i * 4];
	}

	return result;
}

template <>
static std::vector<char> parse<std::vector<char>>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	cell* str = nullptr;
	
	amx_GetAddr(amx_, args_[baseIndex_++], &str);
	if (!str)
		return {};
	
	int len = args_[baseIndex_++];

	std::vector<char> result;
	if (len > 0)
	{
		result.resize(len);
		std::memcpy(&result[0], reinterpret_cast<char*>(str), len);
	}

	return result;
}

template <>
static std::vector<int> parse<std::vector<int>>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	cell* arr = nullptr;
	
	amx_GetAddr(amx_, args_[baseIndex_++], &arr);
	if (!arr)
		return {};
	
	int len = args_[baseIndex_++];

	std::vector<int> result;

	if (len > 0)
	{
		result.resize(len);
		for(int i = 0; i < len; ++i)
			result[i] = arr[i];
	}

	return result;
}

template <>
static std::vector<float> parse<std::vector<float>>(AMX* amx_, cell* args_, size_t & baseIndex_)
{
	cell* arr = nullptr;
	
	amx_GetAddr(amx_, args_[baseIndex_++], &arr);
	if (!arr)
		return {};
	
	int len = args_[baseIndex_++];

	std::vector<float> result;

	if (len > 0)
	{
		result.resize(len);
		for(int i = 0; i < len; ++i)
			result[i] = amx_ctof(arr[i]);
	}

	return result;
}


template <typename Func, size_t Index>
using FuncParam = typename std::tuple_element<Index, typename FuncArgs<Func>::Types >::type;


struct OrderedCall
{
    template <typename F, typename ...Args>
    OrderedCall(F && f, int & result, Args &&... args)
    {
        result = std::forward<F>(f)(std::forward<Args>(args)...);
    }
};

template<typename Function, typename Tuple, size_t ... I>
auto callWithParams(Function f, AMX* amx_, cell* params, size_t & baseIndex, std::index_sequence<I ...>)
{
	int result;
    OrderedCall{f, result, parse<std::tuple_element<I, Tuple>::type>(amx_, params, baseIndex)...};
	return result;
}

template<typename Function, typename Tuple>
auto callWithParams(Function f, AMX* amx_, cell* params, size_t & baseIndex)
{
    static constexpr auto size = std::tuple_size<Tuple>::value;
    return callWithParams<Function, Tuple>(f, amx_, params, baseIndex, std::make_index_sequence<size>{});
}

template <auto func, typename FuncArgType = decltype(func)>
auto make()
{
	using FuncType 		= std::remove_reference_t<FuncArgType>;
	using FuncParams 	= typename FuncArgs< FuncType >::Types;

	static auto native = [] AMX_NATIVE_CALL (AMX* amx, cell* params) -> cell
		{
			size_t baseIndex = 1;
			return callWithParams<FuncType, FuncParams>(func, amx, params, baseIndex);
		};
	return native;
}

}