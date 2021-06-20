#pragma once

namespace samp_cpp
{

enum class TextAlign
{
	Left		= 0,
	Center		= 1,
	Right		= 2,
};

///////////////////////////////////////////////
inline int toObjectMaterialTextAlign(TextAlign textAlign_)
{
	return static_cast<int>(textAlign_);
}

///////////////////////////////////////////////
inline int toTextDrawTextAlign(TextAlign textAlign_)
{
	return static_cast<int>(textAlign_) + 1; // For some reason TextDraw text align starts with 1, not 0
}

}