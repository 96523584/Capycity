#include <iostream>
#include <map>
#include <functional>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <sstream>

#include "Inout.h"
#include "Map.h"
#include "CapycitySim.h"

#include <cstdio>

void* operator new(size_t size)
{
	return malloc(size);
}


int main(int argc, char* argv[])
{
	/*
	 * TODO 1:
	 *	1) place Building				DONE
	 *		- out of bounds check		DONE
	 *		- collision check			DONE
	 *	2) delete area					DONE
	 *		- out of bounds check		DONE
	 *  3) print current map			DONE
	 *  4) close program				DONE
	 * TODO 2:
	 *	1) organize buildings in class CapycitySim
	 *	2) class Material
	 *		- Wood, Metal, Plastic
	 *	3) swap building enum for class tree
	 *		- cost, label, needed material vector/array
	 *	4) add menu functions
	 *		- label print
	 *		- list buildings (and their required materials)
	 *		- costs of one building
	 *		- sum of the costs of all buildings
	 */

	capycity::CapycitySim capycitysim(atoi(argv[1]), atoi(argv[2]));
	capycitysim.run();

	/*
	sf::RenderWindow window;
	window.create(sf::VideoMode(800, 600), "My horny Sim");
	sf::Event ev;
	std::vector<sf::RectangleShape> rects;
	bool running = true;
	sf::Clock dtClock;
	float dt;
	float timer = 0;
	float spawnTime = 1.f;
	float score = 0.f;
	bool mouseHeld = false;
	sf::Font f;
	f.loadFromFile("ALGER.TTF");
	sf::Text scoreT;
	scoreT.setFont(f);
	scoreT.setPosition(10.f, 25.f);
	scoreT.setCharacterSize(16u);
	scoreT.setString("Score: 0");
	while (running)
	{
		dt = dtClock.restart().asSeconds();
		timer += dt;
		window.clear(sf::Color::Black);
		if (timer >= spawnTime)
		{
			timer = 0.f;

			sf::RectangleShape insert(sf::Vector2f(rand() % 20 + 50, rand() % 20 + 50));
			insert.setPosition(sf::Vector2f(rand() % 700 + 20, 0));
			insert.setFillColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
			rects.push_back(insert);
		}
		for (auto it = rects.begin(); it != rects.end();)
		{
			it->move(0, 100.f * dt);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouseHeld && it->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(window)))
			{
				it = rects.erase(it);
				score += 25.f;
				scoreT.setString("Score: " + std::to_string((long long)score));
				if ((long long)score % 100 == 0)
				{
					spawnTime *= 0.95f;
				}
				continue;
			}
			if (it->getPosition().y >= 900.f)
				it = rects.erase(it);
			else
				++it;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			mouseHeld = true;
		}
		else
			mouseHeld = false;
		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
				running = false;
			}
		}
		for (sf::RectangleShape& r : rects)
		{
			window.draw(r);
		}
		window.draw(scoreT);
		window.display();
	}

	*/

	return 0;
}