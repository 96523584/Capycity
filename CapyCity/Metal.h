#pragma once
#include "Material.h"


namespace capycity {
	class Metal :
		public Material
	{
	public:
		Metal(int price);

		const std::string getType() const override;

	};
}

