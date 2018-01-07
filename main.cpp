#include "ProcessChain.h"
#include <stdio.h>
#include <iostream>
#include "windows.h"
#include "RawImageData.h"

using namespace std;

RawImageData* testImage = NULL;

void prepareTestImage()
{
	testImage = new RawImageData();
	memset(testImage->getBuffer(), 0, IMAGE_SIZE * sizeof(unsigned short));
}

int main()
{
	ProcessChain* processChain = new ProcessChain();

	if (!processChain->initializeCuda())
	{
		cout << "InitializeCuda failed!" << endl;
	}

	//test process
	prepareTestImage();
	processChain->process(testImage);

	processChain->uninitializeCuda();
	delete processChain;
	processChain = NULL;

	char str[10];
	cin >> str;

	return 0;
}