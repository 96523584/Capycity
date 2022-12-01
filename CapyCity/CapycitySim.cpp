#include "CapycitySim.h"

void capycity::CapycitySim::run()
{
	do {
		for (auto& option : menuOptions) {
			//std::printf("%5llu : %-50s\n", option.first, option.second.first.c_str());
			std::ostringstream oss;
			oss << std::setw(5) << std::right << option.first << " : " << std::setw(50) << std::left << option.second.first << std::endl;
			InOut::getInstance().print(oss.str());
		}
		std::string input = InOut::getInstance().scan();
		InOut::getInstance().print(menuOptions[atoi(input.c_str())].second());
	} while (running);
}

capycity::CapycitySim::CapycitySim(int sizeX, int sizeY) :
	map(sizeX, sizeY),
	running(true)
{
	addOptionToOptionMap("Place Building", std::bind(&capycity::Map::placeBuildings, &map));
	addOptionToOptionMap("Delete Area", std::bind(&capycity::Map::removeBuildings, &map));
	addOptionToOptionMap("Show Current Blueprint", std::bind(&capycity::Map::printMap, &map));
	addOptionToOptionMap("Exit Program", [&]() {running = false; return "Exiting!"; });

}

void capycity::CapycitySim::addOptionToOptionMap(const std::string& functionText, const std::function<std::string()>& function)
{
	menuOptions.insert(std::pair<size_t, std::pair<std::string, std::function<std::string()>>>(menuOptions.size(), std::pair<std::string, std::function<std::string()>>(functionText, function)));
}
