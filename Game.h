#pragma once
#include <SFML/Graphics.hpp>
#include "Hole.h"
#include "Menu.h"
#include <vector>

class Game
{
private:
	//sf::RenderWindow window(sf::VideoMode({ 1000, 700 }), "Avele");
	sf::RenderWindow window;
	sf::Font font;
	std::vector<Hole> holes;

public:
	Game();
	~Game();

	void Loop();
	void Reset();
	void Update(std::vector<Hole>, std::vector<int> );
};

