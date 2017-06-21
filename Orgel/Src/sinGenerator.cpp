#include "sinGenerator.h"

sinGenerator::sinGenerator()
{
	root = 1.0594631;
}

sinGenerator::~sinGenerator()
{
}

void sinGenerator::set(int n)
{
	if(n==-100)
		return;
	if(n!=this->n)
	{
		w = 2*Pi*(440 * std::pow(root, n));
	}
	this->n=n;
}

double sinGenerator::get(double t)
{	
	return std::sin(w*t);
}
