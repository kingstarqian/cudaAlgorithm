#pragma once
#include "Common.h"

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