#pragma once

#include "Map.h"
#include "Wood.h"
#include <iomanip>


namespace capycity {

	class CapycitySim
	{
	public:
		void run();
		CapycitySim(int sizeX, int sizeY);
	private:
		capycity::Map map;
		std::map<size_t, std::pair<std::string, std::function<std::string()>>> menuOptions;
		bool running;
		void addOptionToOptionMap(const std::string& functionText, const std::function<std::string()>& function);
	};
}