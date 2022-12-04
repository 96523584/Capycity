#include "Plastic.h"

capycity::Plastic::Plastic(int price) :
	Material(price)
{
}

const std::string capycity::Plastic::getType() const
{
	return "Plastic";
}
