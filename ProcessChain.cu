#include "ProcessChain.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include <iostream>
#include "Common.h"
#include "Negate.h"
#include "RawImageData.h"

using namespace std;

ProcessChain::ProcessChain(): deviceBuffer(NULL),negate(NULL)
{
}

ProcessChain::~ProcessChain()
{
}

bool ProcessChain::initializeCuda()
{
	if (initializeDevice())
	{
		mallocMemory();
		initializeChain();
	}
	else
	{
		return false;
	}

	return true;
}


bool ProcessChain::initializeDevice()
{
	cudaError_t cudaStatus;

	int count = 0;
	cudaStatus = cudaGetDeviceCount(&count);
	if (cudaStatus != cudaSuccess)
	{
		fprintf(stderr, "cudaGetDeviceCount failed! Do you have a CUDA-capable GPU installed?");
		return false;
	}
	if (count != 1)
	{
		cout << "Cuda device count is not one. count = " << count << endl;
		return false;
	}

	// Choose which GPU to run on, change this on a multi-GPU system.
	cudaStatus = cudaSetDevice(0);
	if (cudaStatus != cudaSuccess)
	{
		fprintf(stderr, "cudaSetDevice failed!");
		return false;
	}

	//Get Device Properties
	cudaDeviceProp prop;
	cudaStatus = cudaGetDeviceProperties(&prop, 0);
	if (cudaStatus != cudaSuccess)
	{
		fprintf(stderr, "Get CUDA devices failed!");
		return false;
	}

	cout << "MultiProcessCount: " << prop.multiProcessorCount << endl;
	cout << "MaxThreadsPerBlock: " << prop.maxThreadsPerBlock << endl;
	cout << "MaxThreadsPerMultiProcessor" << prop.maxThreadsPerMultiProcessor << endl;

	return true;
}

bool ProcessChain::mallocMemory()
{
	cudaError_t cudaStatus;
	cudaStatus = cudaMalloc((void**)&deviceBuffer, IMAGE_SIZE * sizeof(unsigned short));
	if (cudaStatus != cudaSuccess)
	{
		fprintf(stderr, "Malloc device memory failed!");
		return false;
	}

	return true;
}


void ProcessChain::uninitializeCuda()
{
	freeMemory();
}

void ProcessChain::process(RawImageData* image)
{
	cudaMemcpy(deviceBuffer, image->getBuffer(), IMAGE_SIZE * sizeof(unsigned short), cudaMemcpyHostToDevice);
	negate->fire(deviceBuffer);
	cudaMemcpy(image->getBuffer(), deviceBuffer, IMAGE_SIZE * sizeof(unsigned short), cudaMemcpyDeviceToHost);
}

void ProcessChain::freeMemory()
{

}

void ProcessChain::initializeChain()
{
	negate = new Negate();
}
