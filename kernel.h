#pragma once
extern "C" int runCudaKernel();

class CudaClass
{
public:
	CudaClass();
	~CudaClass();
	bool initializeCuda();
};