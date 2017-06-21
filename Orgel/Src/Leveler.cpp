#include "Leveler.h"

Leveler::Leveler()
{
}

Leveler::~Leveler()
{
}

void Leveler::set(double volume)
{
	this->volume=volume;
}

WORD Leveler::get(double sin)
{
	return (WORD)(sin*volume);
}
