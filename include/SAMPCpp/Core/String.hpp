#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

template <size_t MaxChars>
class InplaceStr
	: public std::array<char, MaxChars>
{
public:
	// Use the same constructors.
	using std::array<char, MaxChars>::array;

	std::string str(size_t maxLen = MaxChars) const
	{
		if ((*this)[0] == 0)
			return {};
		size_t numChars = strnlen_s(this->data(), std::min(maxLen, MaxChars));
		return std::string{ this->data(), this->data() + numChars };
	}

	std::string_view view(size_t maxLen = MaxChars) const
	{
		if ((*this)[0] == 0)
			return {};

		size_t numChars = strnlen_s(this->data(), std::min(maxLen, MaxChars));
		return std::string_view{ this->data(), numChars };
	}
};

template <typename OutputIt>
constexpr inline OutputIt byteToChars(uint8_t byte_, OutputIt it_)
{
	constexpr const char* digits = "0123456789ABCDEF";
	
	*it_++ = byte_ > 0x0F ? digits[(byte_ >> 4)] : '0';
	*it_++ = digits[byte_ & 0x0F];
	return it_;
}


template <size_t MaxChars, typename OutputIt>
struct FormatNResult
{
	InplaceStr<MaxChars>				string;
	fmt::format_to_n_result<OutputIt>	formatResult;
};

template <size_t MaxChars, typename TFormat, typename... TArgs>
auto inplaceFormat(TFormat&& format_, TArgs&&... args_)
{
	FormatNResult<MaxChars, char*> result;

	result.formatResult = fmt::format_to_n(
			result.string.data(), MaxChars - 1,
			std::forward<TFormat>(format_),
			std::forward<TArgs>(args_)...
		);
	*result.formatResult.out = '\0';

	return result;
}

}

namespace fmt
{

template <size_t MaxChars>
struct formatter< samp_cpp::InplaceStr<MaxChars> > : formatter<std::string_view>
{
	template <typename Context>
	auto format(samp_cpp::InplaceStr<MaxChars> const & str_, Context& ctx_)
	{
		return formatter<std::string_view>::format(str_.view(), ctx_);
	}
};

}