#pragma once

#include SAMPCPP_PCH

namespace samp_cpp
{

enum class HttpMethod
{
	Get		= 1,
	Post	= 2,
	Head	= 3,
};

enum class HttpError
{
	BadHost 			= 1,
	NoSocket 			= 2,
	CantConnect 		= 3,
	CantWrite 			= 4,
	ContentTooBig 		= 5,
	MalformedResponse 	= 6,
};


bool http(int requestIdx_, HttpMethod type_, std::string const& url_, std::string const& data_);

bool http(int requestIdx_, HttpMethod type_, char const* url_, char const* data_);

}