#include "sinGenerator.h"

sinGenerator::sinGenerator()
{
	root = 1.0594631;
	wait=0;
}

sinGenerator::~sinGenerator()
{
}

bool sinGenerator::set(int n)
{
	if(wait<50000)
	{
		if(n==-100)
		{
			wait++;
			return true;
		}
	}else{
		return false;
	}
	wait=0;
	if(n!=this->n)
	{
		w = 2*Pi*(440 * std::pow(root, n));
	}
	this->n=n;
	return true;
}

double sinGenerator::get(double t)
{	
	return std::sin(w*t);
}
