#pragma once

#include <string>

namespace capycity {
	class Material
	{
	public:
		virtual const std::string getType() const = 0;
		const int getPrice() const;
		Material(int price);
	private:
	protected:
		int price;
	};
}