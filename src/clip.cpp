#include "clip.h"
#include "config.h"
#include <cmath>
#include <numbers>
#include "funcs.h"
#include <iostream>

constexpr float PI = 3.14159265358979323846f;
constexpr float e = std::numbers::e_v<float>;

clip::clip(int duration) {
	values.resize((duration/1000) * defaults.sample_rate, 0);
}

void clip::addsine(int frequency, int duration){//,int amplitude = (MAX_ * defaults.max_volume)/100) {
	for (int i = 0; i < values.size(); i++) {
		float val = MAX_*sin((2 * PI * frequency * i) / defaults.sample_rate);
		values[i] = val;
	}
}

void clip::addchord(int frequency, int duration, float n, int step, bool nodrop) {//,int amplitude = (MAX_ * defaults.max_volume)/100) {
	frequency *= std::pow(2.0f, step / 12.0f);
	for (int i = 0; i < values.size(); i++) {
		float val = (nodrop ? MAX_ : (n > 1 ? MAX_ / n : MAX_ * n)) * (sin((n * 2 * PI * frequency * i) / defaults.sample_rate));
		values[i] = val;
	}
}

void clip::addharmonic(int frequency, int duration,float n, bool nodrop) {//,int amplitude = (MAX_ * defaults.max_volume)/100) {
	for (int i = 0; i < values.size(); i++) {
		float val = (n>1?MAX_/n:MAX_*n)*sin((n * 2 * PI * frequency * i) / defaults.sample_rate);
		values[i] = val;
	}
}

void clip::addsqharmonic(int frequency, int duration, float n, bool nodrop) {//,int amplitude = (MAX_ * defaults.max_volume)/100) {
	for (int i = 0; i < values.size(); i++) {
		float val = (nodrop?MAX_:(n > 1 ? MAX_ / n : MAX_ * n)) * sgn(sin((n * 2 * PI * frequency * i) / defaults.sample_rate));
		values[i] = val;
	}
}

void clip::addsqchord(int frequency, int duration, float n, int step,bool nodrop) {//,int amplitude = (MAX_ * defaults.max_volume)/100) {
	frequency *= std::pow(2.0f, step / 12.0f);
	for (int i = 0; i < values.size(); i++) {
		float val = (nodrop ? MAX_ : (n > 1 ? MAX_ / n : MAX_ * n)) * sgn(sin((n * 2 * PI * frequency * i) / defaults.sample_rate));
		values[i] = val;
	}
}

void clip::dampen(int start, int duration/*ms*/,float set_zero) {
	duration = duration * defaults.sample_rate;
	duration /= 1000;
	float y = (std::log(MAX_ * sin((2 * PI * 440 * duration)/1000))/duration);
	for (int i = start; i < values.size(); i++) {
		values[i] *= std::exp(-(y * i));
		//std::cout << i<<"," << std::exp(-y * i) <<"," << values[i] << std::endl;
	}
}

void clip::writeclip(std::ofstream& f, int offset) {
	if (!f.is_open()) {
		std::cerr << "Failed to open file\n";
		return;
	}

	f.seekp(offset);
	for (int i = 0; i < values.size(); i++) {
		f.write(reinterpret_cast<const char*>(&values[i]), sizeof(int16_t));
	}
}

void clip::multiply(float k) {
	for (int i = 0; i < values.size(); i++){
		float a = values[i] * k;
		values[i] = a;
	}
}

void clip::expdistort(int clampstep, int duration_ms, float set_zero) {
	int duration_samples = duration_ms * defaults.sample_rate / 1000;
	float y = std::log(MAX_ * sin((2 * PI * 440 * duration_ms) / 1000)) / duration_samples;

	for (int i = 0; i < values.size(); i++) {
		float envelope = MAX_ * std::exp(-(y * i));
		int upper = std::min<int16_t>(envelope + clampstep, MAX_);
		int lower = std::max<int16_t>(-envelope - clampstep, -MAX_);
		values[i] = clamp<int16_t>(lower, upper, values[i]);
	}
}


void clip::distort(int cl) {
	for (int i = 0; i < values.size(); i++) {
		values[i] = clamp<int16_t>(-cl, cl, values[i]);
		//std::cout << values[i] << std::endl;
	}
}

//void clip::linearfade(int start, int end,float startval, float endval){
//	float rate = endval - startval;
//	if (start == end) return;
//	rate /= end - start;
//	for (int i = start; i < end; i++) {
//		values[i] = static_cast<int16_t>(values[i] * rate);
//		values[i] += startval;
//	}
//}
