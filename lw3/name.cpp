#include <SFML/Graphics.hpp>


const int windowWidth = 1000;
const int windowHeight = 500;


const sf::Color nameColor = sf::Color::Green;

int main()
{
    sf::RenderWindow window(
            sf::VideoMode(windowWidth, windowHeight),
            "Traffic light");

    sf::RectangleShape rStick;
    rStick.setPosition(100, 100);
    rStick.setSize({50, 300});
    rStick.setFillColor(nameColor);

    sf::CircleShape rCircle;
    rCircle.setPosition(150, 150);
    rCircle.setRadius(50);
    rCircle.setFillColor(sf::Color::Black);
    rCircle.setOutlineColor(nameColor);
    rCircle.setOutlineThickness(50);

    sf::ConvexShape rStickRotate;
    rStickRotate.setPosition(100, 250);
    rStickRotate.setPointCount(4);
    rStickRotate.setPoint(0, {70, 0});
    rStickRotate.setPoint(1, {220, 150});
    rStickRotate.setPoint(2, {150, 150});
    rStickRotate.setPoint(3, {0, 0});
    rStickRotate.setFillColor(nameColor);

    sf::RectangleShape dStick;
    dStick.setPosition(400, 100);
    dStick.setSize({50, 300});
    dStick.setFillColor(nameColor);

    sf::CircleShape dCircle;
    dCircle.setPosition(450, 150);
    dCircle.setRadius(100);
    dCircle.setFillColor(sf::Color::Black);
    dCircle.setOutlineColor(nameColor);
    dCircle.setOutlineThickness(50);
    dCircle.setScale(0.7, 1);

    sf::CircleShape oCircle;
    oCircle.setPosition(750, 150);
    oCircle.setRadius(100);
    oCircle.setFillColor(sf::Color::Black);
    oCircle.setOutlineColor(nameColor);
    oCircle.setOutlineThickness(50);
    oCircle.setScale(0.7, 1);

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

        window.clear();

        window.draw(rStick);
        window.draw(rCircle);
        window.draw(rStickRotate);
        window.draw(dStick);
        window.draw(dCircle);
        window.draw(oCircle);

        window.display();
    }

    return 0;
}