#ifndef VIEWER_H
#define VIEWER_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "grid.h"
#include "knight.h"
#include "SFML_Line.h"

const int WIDTH = 1080;
const int HEIGHT = 1080;

class Viewer
{

public:
    Viewer();
    Viewer(int n);
    ~Viewer();

    const bool getWindowIsOpen() const;
    void pollEvent();
    void update();
    void render();

private:
    sf::RenderWindow *window;
    sf::Event e;
    sf::Font font;

    Grid<int> grid;
    int squareSize;

    void init();

    void drawGrid();
    void drawPath();
    void drawNums();
};

#endif
