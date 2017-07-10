#include "AudioOut.h"

AudioOut::AudioOut(cTaskHandler handler)
{
	stepSize=(double)1/handler.getCycleTime();
	step=0;	
	toneStep=0;
	preTone=0;
}

AudioOut::~AudioOut()
{
}

void AudioOut::setTone(int toneValue)
{
	if(toneValue!=preTone)
	{
		toneStep=0;
		preTone=toneValue;
		sin.set(toneValue);
	}
}

void AudioOut::setVolume(WORD volume)
{
	if(toneStep<5)
		leveler.set(volume);
}

WORD AudioOut::getSound()
{
	step+=stepSize;
	toneStep+=stepSize;
	if(step>2*Pi)
		step-=2*Pi;
	return (WORD) leveler.get(sin.get(step)*std::pow(0.5, toneStep));
}
