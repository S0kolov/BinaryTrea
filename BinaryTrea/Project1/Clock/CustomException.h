#pragma once
#include <exception>

class CustomException : public std::exception
{
public:
	const int _Error = 407;
	CustomException(const char* message) : exception(message)
	{
		
	}
};
