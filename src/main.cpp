#include <iostream>
#include "clip.h"
#include <fstream>
#include "config.h"

void mknote(std::ofstream& f, int freq, int duration = 1000) {
	static int offset = 0;
	clip A = clip(duration);
	A.addchord(freq, duration, 1,0,true);
	A.dampen(0, duration, 1);
	//A.expdistort(10000, duration, 1);
	//A.distort(5000);
	A.writeclip(f, offset);
	offset += (defaults.sample_rate * duration) / 1000;
	//std::cout << freq <<" "<< duration << std::endl;
	//A.multiply(0);
	return;
}

int main() {
	std::ofstream file("./out/out.pcm", std::ios::binary);
	mknote(file, 261.63, 1000);//4,4 time 60 bpm ie.., 1 beat = quarter note, 1 sec :)
	mknote(file, 261.63, 1000);//C4
	mknote(file, 392, 1000);//G4
	mknote(file, 392, 1000);//G4

	mknote(file, 440, 1000);//A4
	mknote(file, 440, 1000);//A4
	mknote(file, 392, 2000);//G4

	mknote(file, 349, 1000);//F4
	mknote(file, 349, 1000);//F4
	mknote(file, 329, 1000);//E4
	mknote(file, 329, 1000);//E4

	mknote(file, 293, 1000);//D4
	mknote(file, 293, 1000);//D4
	mknote(file, 261.63, 2000);//C4

	mknote(file, 392, 1000);//G4
	mknote(file, 392, 1000);//G4
	mknote(file, 349, 1000);//F4
	mknote(file, 349, 1000);//F4

	mknote(file, 329, 1000);//E4
	mknote(file, 329, 1000);//E4
	mknote(file, 293, 2000);//D4

	mknote(file, 392, 1000);//G4
	mknote(file, 392, 1000);//G4
	mknote(file, 349, 1000);//F4
	mknote(file, 349, 1000);//F4

	mknote(file, 329, 1000);//E4
	mknote(file, 329, 1000);//E4
	mknote(file, 293, 2000);//D4

	mknote(file, 261.63, 1000);//C4
	mknote(file, 261.63, 1000);//C4
	mknote(file, 392, 1000);//G4
	mknote(file, 392, 1000);//G4

	mknote(file, 440, 1000);//A4
	mknote(file, 440, 1000);//A4
	mknote(file, 392, 2000);//G4

	mknote(file, 349, 1000);//F4
	mknote(file, 349, 1000);//F4
	mknote(file, 329, 1000);//E4
	mknote(file, 329, 1000);//E4

	mknote(file, 293, 1000);//D4
	mknote(file, 293, 1000);//D4
	mknote(file, 261.63, 2000);//C4
}
