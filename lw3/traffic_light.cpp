#include <SFML/Graphics.hpp>


const int windowWidth = 500;
const int windowHeight = 500;

const float lighterWidth = 100;
const float lighterHeight = 300;

const float lighterX = (float) windowWidth / 2 - lighterWidth / 2;
const float lighterY = (float) windowHeight / 2 - lighterHeight / 2;

const float circleRadius = lighterWidth / 2;

const float circleX = lighterX;
const float startCircleY = lighterY;

const int circleCount = 3;
const sf::Color colors[circleCount] = {sf::Color::Red, sf::Color::Yellow, sf::Color::Green};



int main()
{
    sf::CircleShape circles[circleCount];

    sf::RenderWindow window(
            sf::VideoMode(windowWidth, windowHeight),
            "Traffic light");

    sf::RectangleShape body;
    body.setPosition(lighterX, lighterY);
    body.setSize({ lighterWidth, lighterHeight});
    body.setFillColor(sf::Color(128, 128, 128));

    for (int i = 0; i < circleCount; i++)
    {
        sf::CircleShape circle(circleRadius, 50);
        circle.setPosition(circleX, startCircleY + 2 * circleRadius * i);
        circle.setFillColor(colors[i]);
        circles[i] = circle;
    }

    while (window.isOpen())
    {
        sf::Event event{}; // выделение памяти
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(body);
        for (auto circle: circles)
        {
            window.draw(circle);
        }
        window.display();
    }

    return 0;
}