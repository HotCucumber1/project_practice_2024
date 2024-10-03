#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>


const int windowWidth = 1000;
const int windowHeight = 500;
const float ballRadius = 30;

const sf::Color ballColor = sf::Color::Magenta;
const sf::Color bgColor = sf::Color::Yellow;

const float amplitude = (float) windowHeight / 2 - ballRadius;
const float period = 4;


int main()
{
    sf::RenderWindow window(
            sf::VideoMode(windowWidth, windowHeight),
            "Trigonometry");
    sf::Clock clock;

    sf::Vector2f pos = {10, 220 };
    float totalTime = 0;
    float speedX = 200 * 10;

    sf::CircleShape ball(ballRadius);
    ball.setFillColor(ballColor);

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

        const float deltaTime = clock.restart().asSeconds();
        totalTime += deltaTime;

        const float wavePhase = totalTime * float(2 * M_PI) * 10;
        const float x = speedX * deltaTime;
        const float y = amplitude * std::sin(wavePhase / period) + (float)windowHeight / 2 - ballRadius;

        pos.x += x;
        pos.y = y;

        if (pos.x + 2 * ballRadius >= windowWidth || pos.x <= 0)
        {
            speedX *= (-1);
        }

        ball.setPosition(pos);
        window.clear(bgColor);
        window.draw(ball);
        window.display();
    }

    return 0;
}