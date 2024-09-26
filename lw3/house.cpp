#include <SFML/Graphics.hpp>


const int windowWidth = 1000;
const int windowHeight = 500;


int main()
{
    sf::RenderWindow window(
            sf::VideoMode(windowWidth, windowHeight),
            "Traffic light");

    sf::RectangleShape wall;
    wall.setPosition(200, 200);
    wall.setSize({ 600, 250});
    wall.setFillColor(sf::Color(150, 80, 50));

    sf::RectangleShape grass;
    grass.setPosition(0, 450);
    grass.setSize({windowWidth, 50});
    grass.setFillColor(sf::Color::Green);

    sf::ConvexShape roof;
    roof.setPosition((float) windowWidth / 2, 100);
    roof.setPointCount(4);
    roof.setPoint(0, {300, 0});
    roof.setPoint(1, {350, 100});
    roof.setPoint(2, {-350, 100});
    roof.setPoint(3, {-300, 0});
    roof.setFillColor(sf::Color::Red);

    sf::RectangleShape door;
    door.setPosition(250, 250);
    door.setSize({100, 200});
    door.setFillColor(sf::Color::Black);

    sf::RectangleShape flue;
    flue.setPosition(600, 70);
    flue.setSize({50, 100});
    flue.setFillColor(sf::Color(100, 100, 100));

    sf::RectangleShape houseWindow;
    houseWindow.setPosition(500, 250);
    houseWindow.setSize({100, 100});
    houseWindow.setFillColor(sf::Color(0, 191, 255));


    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear(sf::Color(135, 206, 235));
        window.draw(wall);
        window.draw(houseWindow);
        window.draw(roof);
        window.draw(door);
        window.draw(flue);
        window.draw(grass);
        window.display();
    }

    return 0;
}