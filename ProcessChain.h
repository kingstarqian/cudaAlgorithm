#pragma once

class AlgorithmBase;
class RawImageData;

class ProcessChain
{
public:
	ProcessChain();
	~ProcessChain();

	bool initializeCuda();
	void uninitializeCuda();

	void process(RawImageData* image);

private:
	bool initializeDevice();
	bool mallocMemory();
	void freeMemory();
	void initializeChain();

private:
	unsigned short* deviceBuffer;
	AlgorithmBase* negate;
};



