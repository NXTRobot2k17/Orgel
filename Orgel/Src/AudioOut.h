#include "lib.h"
#include <math.h>

#include "stdint.h"

#include "sinGenerator.h"
#include "Leveler.h"

#define Pi    3.14159265358979323846f 

#ifndef AUDIOOUT_H
#define AUDIOOUT_H

class AudioOut
{
public:
	AudioOut(cTaskHandler handler);
	~AudioOut();

private:
	int tone;
	int preTone;
	double volume;
	double time;

	double step;
	double toneStep;
	double stepSize;

	sinGenerator sin;
	Leveler leveler;

public:
	void setTone(int tone);
	void setVolume(double volume);
	WORD getSound();
};

#endif
