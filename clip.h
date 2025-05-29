#pragma once
#include <vector>
#include <fstream>

//template <typename T>
class clip
{
public:
	std::vector<int16_t> values;
	clip(int duration);
	void addsine(int frequency, int duration = 1000);//, int amplitude = MAX_);
	//void addsq(int frequency, int duration = 1000);
	void addchord(int frequency, int duration, float n, int step, bool nodrop);
	void addharmonic(int frequency, int duration, float n, bool nodrop=false);
	void addsqharmonic(int frequency, int duration, float n, bool nodrop=false);
	void addsqchord(int frequency, int duration, float n, int step, bool nodrop);

	void linearfade(int start, int end, float startval = 1, float endval = 0);
	void dampen(int start, int duration,float set_zero);
	void writeclip(std::ofstream& f, int offset = 0);
	void multiply(float k);
	clip operator+=(const clip& other) {
		values.insert(values.end(), other.values.begin(), other.values.end());
	}
	void expdistort(int clampstep , int duration/*ms*/, float set_zero);
	void distort(int cl);
};