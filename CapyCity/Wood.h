#pragma once
#include "Material.h"


namespace capycity {
	class Wood :
		public Material
	{
	public:
		Wood(int price);

		const std::string getType() const override;

	};
}

