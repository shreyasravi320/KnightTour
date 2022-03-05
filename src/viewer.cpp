#include "include/viewer.h"

Viewer::Viewer()
{
    init();
    grid = Grid(8, 8, UNVISITED);
    solveClosedTour(grid);

    squareSize = HEIGHT / grid.getRows();
}

Viewer::Viewer(int n)
{
    init();
    grid = Grid(n, n, UNVISITED);
    solveClosedTour(grid);

    squareSize = HEIGHT / grid.getRows();
}

Viewer::~Viewer()
{

}

void Viewer::init()
{
    window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "KnightTour", sf::Style::Titlebar | sf::Style::Close);
    font.loadFromFile("CourierPrime-Bold.ttf");
    window->setFramerateLimit(144);
}

const bool Viewer::getWindowIsOpen() const
{
    return window->isOpen();
}

void Viewer::pollEvent()
{
    while (window->pollEvent(e))
    {
        switch (e.type)
        {
            case sf::Event::Closed:
            {
                window->close();
                break;
            }

            default:
            {
                break;
            }
        }
    }
}

void Viewer::update()
{
    pollEvent();
}

void Viewer::render()
{
    window->clear(WHITE);
    drawGrid();
    // drawPath();
    drawNums();
    window->display();
}

void Viewer::drawGrid()
{
    // Draw horizontal and vertical lines to make a visual grid
    for (int i = 0; i < grid.getRows(); i++)
    {
        sf::Vertex line_h[] = 
        {
            sf::Vertex(sf::Vector2f(0, i * squareSize), BLACK),
            sf::Vertex(sf::Vector2f(WIDTH, i * squareSize), BLACK)
        };

        sf::Vertex line_v[] = 
        {
            sf::Vertex(sf::Vector2f(i * squareSize, 0), BLACK),
            sf::Vertex(sf::Vector2f(i * squareSize, HEIGHT), BLACK)
        };

        window->draw(line_h, 2, sf::Lines);
        window->draw(line_v, 2, sf::Lines);
    }
}

void Viewer::drawPath()
{
    // Draw the path connecting the edges sequentially
    int i = 0, j = 0;
    sf::Vector2f v(squareSize / 2, squareSize / 2);

    vector<int> delta_i = {1, 2,  2,  1, -1, -2, -2, -1};
    vector<int> delta_j = {2, 1, -1, -2, -2, -1,  1,  2};

    for (int s = 0; s < grid.getRows() * grid.getCols(); s++)
    {
        bool a = true;

        // Find next [i, j] in the path
        for (int k = 0; k < 8 and a; k++)
        {
            if (isValid(grid.getRows(), grid.getCols(), i + delta_i[k], j + delta_j[k]))
            {
                if (grid[i + delta_i[k]][j + delta_j[k]] == (s + 1) % (grid.getRows() * grid.getCols()))
                {
                    i += delta_i[k];
                    j += delta_j[k];


                    sf::Vector2f u(
                        j * squareSize + squareSize / 2,
                        i * squareSize + squareSize / 2
                    );

                    LineShape line_f(v, u, GREEN);
                    LineShape line_r(u, v, GREEN);

                    line_f.draw(window);
                    line_r.draw(window);

                    v = u;
                    a = false;
                }

                else if (k == 7)
                {
                    s++;
                    bool b = true;

                    for (int y = 0; y < grid.getRows() and b; y++)
                    {
                        for (int x = 0; x < grid.getCols() and b; x++)
                        {
                            if (grid[y][x] == s)
                            {
                                i = y;
                                j = x;
                                v = sf::Vector2f(j * squareSize + squareSize / 2, i * squareSize + squareSize / 2);

                                b = false;
                            }
                        }
                    }

                    a = false;
                    s--;
                }
            }
        }
    }
}

void Viewer::drawNums()
{
    // Draw the order to take, i.e. which edge is visited sequentially
    for (int i = 0; i < grid.getRows(); i++)
    {
        for (int j = 0; j < grid.getCols(); j++)
        {
            sf::Text num;
            
            num.setFont(font);
            num.setFillColor(grid[i][j] == 0 ? RED : BLACK);
            num.setCharacterSize(min(100, squareSize / 4));
            num.setString(to_string(grid[i][j]));

            num.setPosition((float)(squareSize * j), (float)(squareSize * i));

            window->draw(num);

            sf::CircleShape dot;
            dot.setRadius(squareSize / 16);
            dot.setFillColor(RED);

            dot.setPosition(
                (float)(squareSize * j + (squareSize / 2 - dot.getRadius())), 
                (float)(squareSize * i + (squareSize / 2 - dot.getRadius()))
            );

            window->draw(dot);
        }
    }
}
