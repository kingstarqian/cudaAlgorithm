#pragma once
#include "AlgorithmBase.h"

class Negate :
	public AlgorithmBase
{
public:
	Negate();
	~Negate();

	virtual void fire(unsigned short* deviceBuffer);
};

