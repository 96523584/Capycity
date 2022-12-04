#include "Wood.h"

capycity::Wood::Wood(int price) :
	Material(price)
{
}

const std::string capycity::Wood::getType() const
{
	return "Wood";
}
