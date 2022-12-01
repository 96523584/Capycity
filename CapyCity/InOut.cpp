#include "InOut.h"

void InOut::print(const std::string& output)
{
	std::cout << output;
}

std::string InOut::scan()
{
	std::string output;
	std::cin >> output;
	return output;
}

InOut& InOut::getInstance()
{
	static InOut inout;
	return inout;
}

InOut::InOut()
{
}
