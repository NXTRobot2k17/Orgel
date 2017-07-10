#include "Leveler.h"

Leveler::Leveler()
{
}

Leveler::~Leveler()
{
}

void Leveler::set(WORD volume)
{
	this->volume=volume;
}

double Leveler::get(double sin)
{
	return sin*volume;
}
