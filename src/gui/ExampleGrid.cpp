#include "gui/ExampleGrid.hpp"

ExampleGrid::ExampleGrid()
    : Grid(Vector2f(650, 5), Vector2f(300, 300), 5, 10)
{
    // Definir el callback
    this->fun = std::bind(&ExampleGrid::functionGrid, this, std::placeholders::_1, std::placeholders::_2); 
    this->setonCellClick(fun);

    this->drawAxes();
}

void ExampleGrid::functionGrid(int x, int y)
{
    std::cout << "(" << x << "," << y << ")\n";
    this->rectangles[x][y]->setFillColor(Color::Black);
}
