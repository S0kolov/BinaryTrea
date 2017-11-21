#pragma once
#include <exception>
#include "CustomException.h"

class InvalidArgumentsException : public CustomException
{
public:
	const int _Error = 236;

	InvalidArgumentsException(const char *message) : CustomException(message)
	{
		
	}
};
