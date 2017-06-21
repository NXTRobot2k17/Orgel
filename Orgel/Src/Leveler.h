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

public:
	void set(double volume);
	WORD get(double sin);
};

#endif
