#ifndef EXAMPLE_GRID_HPP
#define EXAMPLE_GRID_HPP

#include <iostream>

#include "gui/components/Grid.hpp"

using namespace sf;

class ExampleGrid : public Grid
{
private:
    std::function<void(int, int)> fun; // Usar std::function para la función de callback
public:
    ExampleGrid();

     void functionGrid(int, int); 
};

#endif // EXAMPLE_GRID_HPP