#include "ProcessChain.h"
#include <stdio.h>
#include <iostream>
#include "windows.h"

using namespace std;

int main()
{
	ProcessChain* processChain = new ProcessChain();

	if (!processChain->initializeCuda())
	{
		cout << "InitializeCuda failed!" << endl;
	}

	processChain->uninitializeCuda();
	delete processChain;
	processChain = NULL;

	while (1)
	{
		Sleep(10);
	}
	return 0;
}