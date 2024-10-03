#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <math.h>


const int windowWidth = 1000;
const int windowHeight = 1000;

const sf::Color roseColor = sf::Color::Magenta;
const sf::Color bgColor = sf::Color::Yellow;

const int roseRadius = 200;
const int petalNumber = 6;
const int rosePointCount = petalNumber * 50;

const int rotationRadius = 200;
const int rotationPeriod = 2;
const float selfRotationAngle = M_PI / 6;


int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 10;
    sf::RenderWindow window(
            sf::VideoMode(windowWidth, windowHeight),
            "Trigonometry",
            sf::Style::Default,
            settings);

    sf::SoundBuffer buffer;
    buffer.loadFromFile("../static/sound/baraban_1995_hq.wav");
    sf::Sound sound(buffer);

    sf::Clock clock;

    sf::ConvexShape ellipse;
    ellipse.setPosition(windowWidth / 2 + roseRadius, windowHeight / 2);
    ellipse.setFillColor(roseColor);
    ellipse.setPointCount(rosePointCount);


    for (int pointNum = 0; pointNum < rosePointCount; pointNum++)
    {
        float angle = float(2 * M_PI * pointNum) / float(rosePointCount);
        float radius = roseRadius * std::sin(petalNumber * angle);

        sf::Vector2f point = {
                radius * std::sin(angle),
                radius * std::cos(angle),
        };
        ellipse.setPoint(pointNum, point);
    }

    sound.play();
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
        float angle = 2 * M_PI * clock.getElapsedTime().asSeconds() / rotationPeriod;
        sf::Vector2f point = {
                rotationRadius * std::sin(angle) + windowWidth / 2,
                rotationRadius * std::cos(angle) + windowHeight / 2,
        };
        ellipse.setPosition(point);
        ellipse.rotate(selfRotationAngle);

        window.clear(bgColor);
        window.draw(ellipse);
        window.display();
    }

    return 0;
}