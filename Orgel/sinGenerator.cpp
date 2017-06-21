#include "sinGenerator.h"

sinGenerator::sinGenerator()
{
	root = 1.0594631;
}

void sinGenerator::set(int n)
{
	if(n!=this->n)
	{
		w = 2*Pi*(440 * std::pow(root, n));
	}
	this->n=n;
}

double sinGenerator::get(double x)
{	
	return std::sin(w*x);
}