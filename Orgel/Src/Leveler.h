#include "lib.h"

#ifndef LEVELER_H
#define LEVELER_H

class Leveler
{
public:
	Leveler();
	~Leveler();
private:
	double volume;
	double oldVolume;

public:
	void set(double volume);
	double get(double sin);
};

#endif
