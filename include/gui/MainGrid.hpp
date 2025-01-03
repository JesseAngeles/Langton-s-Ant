#ifndef MAIN_GRID_HPP
#define MAIN_GRID_HPP

#include <iostream>

#include "gui/components/Grid.hpp"

class GUI;

using namespace sf;

class MainGrid : public Grid
{
private:
    std::function<void(int, int)> fun; // Usar std::function para la función de callback

    GUI *gui;

public:
    MainGrid(GUI *gui, int width, int height)
        : Grid(Vector2f(250, 7), Vector2f(1000, 1000), width, height),
          gui(gui)
    {
        // Definir el callback
        this->fun = std::bind(&MainGrid::functionGrid, this, std::placeholders::_1, std::placeholders::_2);
        this->setonCellClick(fun);

        // this->drawAxes();
    }

    void setGridColor(const int &x, const int &y, const Color &color)
    {
        this->rectangles[x][y]->setFillColor(color);
    }
    
    void functionGrid(int x, int y);
};

#endif // MAIN_GRID_HPP