#pragma once
#include <SFML/Graphics.hpp>
#include "Counter.h"
#include "Images.h"

class Hole{
private:
	sf::Texture texture;
	Counter pebbles;
	sf::Vector2f position;
	sf::CircleShape shape;

public:
	Hole(sf::Vector2f );
	Hole();
	~Hole();

	void Update(int);
	void Set_Position(sf::Vector2f );
	void Render(const sf::RenderTarget &);

};

