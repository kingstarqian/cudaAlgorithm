#include "Negate.h"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <stdio.h>
#include "Common.h"

__global__ void negateAlgorithm(unsigned short * deviceBuffer)
{
	int i = threadIdx.x;
	deviceBuffer[i] = MAX_PIXEL_VALUE - deviceBuffer[i];
}

Negate::Negate()
{
}


Negate::~Negate()
{
}

void Negate::fire(unsigned short * deviceBuffer)
{
	CALCULATE_CUDA_ELAPSED_START

	for (int i = 0; i < IMAGE_HEIGHT; ++i)
	{
		negateAlgorithm <<<1, IMAGE_WIDTH >>>(deviceBuffer + IMAGE_WIDTH * i);
	}

	dim3 dim(IMAGE_WIDTH, IMAGE_HEIGHT);

	CALCULATE_CUDA_ELAPSED_STOP("Negate")
	
	cudaError_t cudaStatus = cudaThreadSynchronize();
	if (cudaStatus != cudaSuccess)
	{
		fprintf(stderr, "Negate::fire failed!");
	}
}
