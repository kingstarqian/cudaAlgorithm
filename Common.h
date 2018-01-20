#pragma once
#include <stdio.h>
#include <string.h>

const int IMAGE_WIDTH = 1000;
const int IMAGE_HEIGHT = 1000;
const int IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT;
const unsigned short MAX_PIXEL_VALUE = 0xFFFF;

#define PRINT_DEBUG_INFO

#ifdef PRINT_DEBUG_INFO

#define CALCULATE_CUDA_ELAPSED_START cudaEvent_t start, stop;\
									cudaEventCreate(&start);\
									cudaEventCreate(&stop);\
									cudaEventRecord(start, 0);

#define CALCULATE_CUDA_ELAPSED_STOP(prefix) cudaEventRecord(stop, 0);\
									cudaEventSynchronize(stop);\
									float tm;\
									cudaEventElapsedTime(&tm, start, stop);\
									printf(prefix);\
									printf(" GPU Elapsed time:%.6f ms.\n", tm);
#else

#define CALCULATE_CUDA_ELAPSED_START 
#define CALCULATE_CUDA_ELAPSED_STOP(prefix)

#endif // 



