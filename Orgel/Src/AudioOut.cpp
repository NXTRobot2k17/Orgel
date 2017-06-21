#include "AudioOut.h"

AudioOut::AudioOut(cTaskHandler handler)
{
	stepSize=(double)handler.getCycleTime() * 0.000001;
	step=0;	
	toneStep=0;
	preTone=0;
}

AudioOut::~AudioOut()
{
}

void AudioOut::setTone(int tone)
{
	if(tone!=preTone)
	{
		toneStep=0;
		preTone=tone;
	}
	if(!sin.set(tone))
		leveler.set(0);
	else
		leveler.set(-1);
}

void AudioOut::setVolume(double volume)
{
	leveler.set(volume);
}

WORD AudioOut::getSound()
{
	step+=stepSize;
	toneStep+=stepSize;
	if(step>2*Pi)
		step-=2*Pi;
	return (WORD) leveler.get(sin.get(step)*std::pow(0.85, toneStep));
}
