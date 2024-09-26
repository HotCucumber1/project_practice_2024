#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


const int windowWidth = 500;
const int windowHeight = 500;

const float circleRadius = 25;
const float outlineThickness = 1;
const int circlePointCount = 100;

const float x = static_cast<float>(windowHeight) / 2 - circleRadius; // безопаснее
const float y = static_cast<float>(windowHeight) / 2 - circleRadius;


int main()
{
    float offsetX = 0.05;
    float offsetY = 0.1;

    sf::SoundBuffer buffer;
    buffer.loadFromFile("../static/sound/piu.wav");
    sf::Sound sound(buffer);

    sf::RenderWindow window(
            sf::VideoMode(windowWidth, windowHeight),
            "SFML window");

    sf::CircleShape circle(circleRadius, circlePointCount);

    circle.setPosition(x, y);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineColor(sf::Color::Green);
    circle.setOutlineThickness(outlineThickness);

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

        circle.move(offsetX, offsetY);
        if (circle.getPosition().x + 2 * circle.getRadius() >= windowWidth || circle.getPosition().x <= 0)
        {
            offsetX *= (-1);
            sound.play();
        }
        if (circle.getPosition().y + 2 * circle.getRadius() >= windowHeight || circle.getPosition().y <= 0)
        {
            offsetY *= (-1);
            sound.play();
        }

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;
}
