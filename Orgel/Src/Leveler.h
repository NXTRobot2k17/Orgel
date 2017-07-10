#include "lib.h"

#ifndef LEVELER_H
#define LEVELER_H

class Leveler
{
public:
	Leveler();
	~Leveler();
private:
	WORD volume;

public:
	void set(WORD volume);
	double get(double sin);
};

#endif
