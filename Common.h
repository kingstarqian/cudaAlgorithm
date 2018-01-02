#pragma once
#include <stdio.h>
#include <string.h>

const int IMAGE_WIDTH = 1000;
const int IMAGE_HEIGHT = 1000;
const int IMAGE_SIZE = IMAGE_WIDTH * IMAGE_HEIGHT;


class RawImageData
{
public:
	RawImageData()
	{
		buffer = new unsigned short[IMAGE_SIZE];
	}
	RawImageData(const RawImageData& image)
	{
		memcpy(this->buffer, image.getBuffer(), IMAGE_SIZE * sizeof(unsigned short));
	}
	RawImageData& operator=(const RawImageData& image)
	{
		memcpy(this->buffer, image.getBuffer(), IMAGE_SIZE * sizeof(unsigned short));
	}
	~RawImageData()
	{
		if (buffer)
		{
			delete[] buffer;
			buffer = NULL;
		}
	}
	

	unsigned short* getBuffer() const
	{
		return buffer;
	}

private:
	unsigned short* buffer;
};