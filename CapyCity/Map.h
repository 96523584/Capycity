#pragma once
#include <map>
#include <functional>
#include <string>
#include <sstream>

#include "InOut.h"

namespace capycity {
	typedef struct Coord
	{
		int x;
		int y;
	}Coord_t;

	enum Building
	{
		Empty, HydroPowerplant, WindPowerplant, SolarPowerplant
	};
	class Map
	{
	public:


		Map(int sizeX, int sizeY);

		~Map();

		std::string placeBuildings();

		std::string removeBuildings();

		std::string printMap();


	private:
		Building* map;
		Coord_t mapSize;

		int coordToIndex(int x, int y);

		Coord_t indexToCoord(int index);

		bool checkBounds(int posX, int posY, int sizeX, int sizeY);

		bool checkCollision(int posX, int posY, int sizeX, int sizeY);

		void fill(Building type, int posX, int posY, int sizeX, int sizeY);
	};

}