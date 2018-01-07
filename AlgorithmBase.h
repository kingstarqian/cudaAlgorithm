#pragma once

class AlgorithmBase
{
public:
	AlgorithmBase();
	~AlgorithmBase();

	virtual void fire(unsigned short* deviceBuffer) = 0;
};

