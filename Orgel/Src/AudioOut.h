#include "stdint.h"

#include "sinGenerator.h"
#include "Leveler.h"

#define Pi    3.14159265358979323846f 

#ifndef AUDIOOUT_H
#define AUDIOOUT_H

class AudioOut
{
public:
	AudioOut(double stepSize);
	~AudioOut();

private:
	int tone;
	double volume;
	double time;

	double step;
	double stepSize;

	sinGenerator sin;
	Leveler leveler;

public:
	void setTone(int tone);
	void setVolume(double volume);
	WORD getSound();
};

#endif
