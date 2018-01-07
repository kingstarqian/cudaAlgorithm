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
	cudaEvent_t start, stop;
	cudaEventCreate(&start);
	cudaEventCreate(&stop);
	cudaEventRecord(start, 0);

	for (int i = 0; i < IMAGE_HEIGHT; ++i)
	{
		negateAlgorithm << <1, IMAGE_WIDTH >> >(deviceBuffer + IMAGE_WIDTH * i);
	}

	cudaEventRecord(stop, 0);
	cudaEventSynchronize(stop);
	float tm;
	cudaEventElapsedTime(&tm, start, stop);
	printf("Negate GPU Elapsed time:%.6f ms.\n", tm);
	
	cudaError_t cudaStatus = cudaThreadSynchronize();
	if (cudaStatus != cudaSuccess)
	{
		fprintf(stderr, "Negate::fire failed!");
	}
}
