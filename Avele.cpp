#include <SFML/Graphics.hpp>

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode({ 200, 200 }), "Avele");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //sf::Texture texture("images/hole.png");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // clear the window with black color
        window.clear();

        // draw everything here...
        // window.draw(...);
        window.draw(shape);

        // end the current frame
        window.display();
    }
}