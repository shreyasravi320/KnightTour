#ifndef SFML_LINE
#define SFML_LINE

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <math.h>

#define WHITE sf::Color(255, 255, 255)
#define BLACK sf::Color(0, 0, 0)
#define BLUE sf::Color(50, 50, 205)
#define RED sf::Color(205, 50, 50)
#define PINK sf::Color(228, 35, 157)
#define GREEN sf::Color(50, 205, 50)

class LineShape
{
public:
    LineShape(
        const sf::Vector2f &p1, 
        const sf::Vector2f &p2, 
        sf::Color c=BLACK,
        float t=0.02
    )
    {
        color = c;
        thickness = t;

        sf::Vector2f m = p2 - p1;
        sf::Vector2f u = m / sqrt(m.x * m.x + m.y * m.y);
        sf::Vector2f n(-m.y, m.x);

        sf::Vector2f offset = (thickness / 2) * n;

        vertices[0].position = p1 + offset;
        vertices[1].position = p2 + offset;
        vertices[2].position = p1 - offset;
        vertices[3].position = p2 - offset;

        for (int i = 0; i < 4; i++)
        {
            vertices[i].color = color;
        }
    }
    
    void draw(sf::RenderWindow *window)
    {
        window->draw(vertices, 4, sf::Quads);
    }

private:
    sf::Vertex vertices[4];
    float thickness;
    sf::Color color;
};

#endif