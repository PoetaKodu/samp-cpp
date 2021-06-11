#pragma once

#include SAMPCPP_PCH

#include <SAMPCpp/Color.hpp>

namespace samp_cpp
{

enum class CameraMove
{
	Move = 1,
	Cut = 2
};

class Player
{
public:
	Player(int32_t id_)
		: _id(id_)
	{
	}

	int32_t id() const { return _id; }

	bool setPosition(math::Vector3f const& pos_);
	bool setPosition(float x_, float y_, float z_);

	math::Vector3f getPosition() const;

	bool setCameraPosition(math::Vector3f const& pos_);
	bool setCameraPosition(float x_, float y_, float z_);

	bool setCameraLookAt(math::Vector3f const& lookAt_, CameraMove moveMethod_ = CameraMove::Cut);
	bool setCameraLookAt(float x_, float y_, float z_, CameraMove moveMethod_ = CameraMove::Cut);

	std::string getName() const;

	template <typename TFormat, typename TFirstArg, typename... TArgs>
	void msg(Color color_, TFormat && fmt_, TFirstArg && firstArg_, TArgs &&... args_)
	{
		std::string msgContent = fmt::format(
				std::forward<TFormat>(fmt_),
				std::forward<TFirstArg>(firstArg_),
				std::forward<TArgs>(args_)...
			);

		this->msg(color_, msgContent);
	}

	

	bool msg(Color color_, std::string const& content_);

	bool msg(Color color_, char const* content_);
private:
	int32_t _id;
};

}