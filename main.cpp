#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "Game.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 700, 600 }), "Avele");

    //window.setPosition(sf::Vector2i(10, 50));   
    auto color = sf::Color{ 0xFF0000FF };
    
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    Hole test;
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {            
            if (event->is<sf::Event::Closed>())
                window.close();
        }
        window.clear();

        window.draw(shape);      
        test.Render(window);
        // end the current frame
        window.display();
    }
}