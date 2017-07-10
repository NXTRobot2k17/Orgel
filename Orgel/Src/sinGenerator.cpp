#include "sinGenerator.h"

sinGenerator::sinGenerator()
{
	root = 1.0594631;
	wait=0;
}

sinGenerator::~sinGenerator()
{
}

bool sinGenerator::set(int note)
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
	if(note!=n)
	{
		w = (440 * std::pow(root, note));
	}
	n=note;
	return true;
}

double sinGenerator::get(double t)
{	
	return std::sin(2*Pi*w*t);
}
