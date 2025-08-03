#include "config.h"

int16_t MAX_ = (std::numeric_limits<int16_t>::max())/2;
int16_t MIN_ = std::numeric_limits<int16_t>::min();
config::config() : sample_rate(44100), bit_depth(16), max_volume(10) {}

config defaults;