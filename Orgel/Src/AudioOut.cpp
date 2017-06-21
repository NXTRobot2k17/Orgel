#include "AudioOut.h"

AudioOut::AudioOut(double stepSize)
{
	this->stepSize=stepSize;
	step=0;
}

AudioOut::~AudioOut()
{
}

void AudioOut::setTone(int tone)
{
	sin.set(tone);
}

void AudioOut::setVolume(double volume)
{
	leveler.set(volume);
}

WORD AudioOut::getSound()
{
	step+=stepSize;
	if(step>2*Pi)
		step-=2*Pi;
	return leveler.get(sin.get(step));
}
