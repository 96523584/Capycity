#include "Metal.h"

capycity::Metal::Metal(int price) :
	Material(price)
{
}

const std::string capycity::Metal::getType() const
{
	return "Metal";
}
