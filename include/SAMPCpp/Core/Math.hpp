#pragma once

#include <QuickMaffs/Everything.hpp>

namespace samp_cpp
{

namespace math = quickmaffs;

// Bunch of handful aliases
namespace math_aliases // namespace only for convenient "using namespace samp::math_aliases"
{
using Vec2i 	= math::Vector2i32;
using Vec2u 	= math::Vector2u32;
using Vec2f 	= math::Vector2f;
using Vec2d 	= math::Vector2d;
using Vec2size 	= math::Vector2size;

using Vec3i 	= math::Vector3i32;
using Vec3u 	= math::Vector3u32;
using Vec3f 	= math::Vector3f;
using Vec3d 	= math::Vector3d;
using Vec3size 	= math::Vector3size;
}

using namespace math_aliases;

}