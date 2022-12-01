#include "Map.h"
using namespace capycity;

Map::Map(int sizeX, int sizeY) :
	mapSize{ sizeX, sizeY }
{
	map = new Building[mapSize.x * mapSize.y];
	fill(Building::Empty, 0, 0, mapSize.x, mapSize.y);
}

capycity::Map::~Map()
{
	delete[] map;
}

std::string capycity::Map::placeBuildings()
{
	InOut::getInstance().print("Please Input Building Type!\n");
	Building type = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Horizontal Size!\n");
	int sizeX = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Vertical Size!\n");
	int sizeY = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Horizontal Position!\n");
	int posX = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Vertical Position!\n");
	int posY = Building(atoi(InOut::getInstance().scan().c_str()));
	if (checkBounds(posX, posY, sizeX, sizeY)) {
		return "Area out of Bounds!\n";
	}
	if (checkCollision(posX, posY, sizeX, sizeY)) {
		return "Area occupied!\n";
	}
	fill(type, posX, posY, sizeX, sizeY);
	return "";
}

std::string capycity::Map::removeBuildings()
{
	InOut::getInstance().print("Please Input Horizontal Size!\n");
	int sizeX = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Vertical Size!\n");
	int sizeY = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Horizontal Position!\n");
	int posX = Building(atoi(InOut::getInstance().scan().c_str()));
	InOut::getInstance().print("Please Input Vertical Position!\n");
	int posY = Building(atoi(InOut::getInstance().scan().c_str()));
	if (checkBounds(posX, posY, sizeX, sizeY)) {
		return "Area out of Bounds!\n";
	}
	fill(Building::Empty, posX, posY, sizeX, sizeY);
	return "";
}

std::string capycity::Map::printMap()
{
	for (int y = 0; y < mapSize.y; y++) {
		for (int x = 0; x < mapSize.x; x++) {
			InOut::getInstance().print(std::to_string(map[coordToIndex(x, y)]) + " ");
		}
		InOut::getInstance().print("\n");
	}
	return "";
}

int Map::coordToIndex(int x, int y)
{
	return x + mapSize.x * y;
}

Coord_t Map::indexToCoord(int index)
{
	return Coord_t{ index % mapSize.x, index / mapSize.x };
}

//true if out of bounds
bool capycity::Map::checkBounds(int posX, int posY, int sizeX, int sizeY)
{
	return posX < 0 || posY < 0 || sizeX < 0 || sizeY < 0 || posX + sizeX > mapSize.x || posY + sizeY > mapSize.y;
}

//true if space occupied
bool capycity::Map::checkCollision(int posX, int posY, int sizeX, int sizeY)
{
	for (int y = posY; y < posY + sizeY; y++) {
		for (int x = posX; x < posX + sizeX; x++) {
			if (map[coordToIndex(x, y)] != Building::Empty) {
				return true;
			}
		}
	}
	return false;
}

void capycity::Map::fill(Building type, int posX, int posY, int sizeX, int sizeY)
{
	for (int y = posY; y < posY + sizeY; y++) {
		for (int x = posX; x < posX + sizeX; x++) {
			map[coordToIndex(x, y)] = type;
		}
	}
}
