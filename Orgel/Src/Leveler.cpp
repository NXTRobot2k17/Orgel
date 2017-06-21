#include "Leveler.h"

Leveler::Leveler()
{
}

Leveler::~Leveler()
{
}

void Leveler::set(double volume)
{
	if(volume==0)
	{
		oldVolume=volume;
		volume=0;
	}
	else if(volume == -1)
	{
		volume=oldVolume;
	}else
	{
		this->volume=volume;
	}
}

double Leveler::get(double sin)
{
	return sin*volume;
}
