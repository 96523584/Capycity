#include "Material.h"

using namespace capycity;

const int Material::getPrice() const
{
	return price;
}

Material::Material(int price) :
	price(price)
{
}
