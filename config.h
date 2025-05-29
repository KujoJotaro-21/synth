#pragma once
#include <limits>
#include <cstdint>

class config
{
public:
	int sample_rate = 44100;
	int bit_depth = 16;
	int max_volume = 10;
	config();
};
extern int16_t MAX_;
extern int16_t MIN_;
extern config defaults;