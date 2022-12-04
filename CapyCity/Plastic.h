#pragma once
#include "Material.h"


namespace capycity {
	class Plastic :
		public Material
	{
	public:
		Plastic(int price);

		const std::string getType() const override;

	};
}

