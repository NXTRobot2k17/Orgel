#include <math.h>

#ifndef SINGENERATOR_H
#define SINGENERATOR_H

#define Pi    3.14159265358979323846f 

class sinGenerator
{
public:
		sinGenerator();
		~sinGenerator();

private:
		double root;
		int n;
		double w;
		int wait;

public:
		bool set(int note);
		double get(double t);
};

#endif //SINGENERATOR_H
