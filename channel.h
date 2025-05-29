#pragma once
#include "clip.h"

class channel
{
	std::vector<clip> snips;
	channel();
	void notegen(const char* str);
};

