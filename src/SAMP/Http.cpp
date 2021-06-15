#include SAMPCPP_PCH

#include <SAMPCpp/SAMP/Http.hpp>


namespace samp_cpp
{

/////////////////////////////////////////////////////
bool http(int requestIdx_, HttpMethod method_, std::string const& url_, std::string const& data_)
{
	return http(requestIdx_, method_, url_.c_str(), data_.c_str());
}

/////////////////////////////////////////////////////
bool http(int requestIdx_, HttpMethod method_, char const* url_, char const* data_)
{
	return sampgdk_HTTP(requestIdx_, static_cast<int>(method_), url_, data_);
}

}