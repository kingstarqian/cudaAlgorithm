#pragma once


class ProcessChain
{
public:
	ProcessChain();
	~ProcessChain();

	bool initializeCuda();
	void uninitializeCuda();

private:
	bool initializeDevice();
	bool mallocMemory();
	void freeMemory();

private:
	unsigned short* deviceBuffer;
};



