#include "logic/Space.hpp"

// Constructor
Space::Space(int width, int height, int states, std::set<std::shared_ptr<Ant>> ants)
    : space(width, std::vector<Cell>(height, Cell(0, true))), states(states), ants(ants)
{
    for (const std::shared_ptr<Ant> &ant : ants)
        this->space[ant->getPos().x][ant->getPos().y].empty = false;
}

// Private functions

// Public functions
void Space::move()
{
    Vector2i pos;
    for (const std::shared_ptr<Ant> &ant : ants)
    {
        pos = ant->getPos();
        ant->rotate(space[pos.x][pos.y].state);
        Vector2i new_pos = ant->getNextMove();
        ant->setPos(new_pos);
        space[pos.x][pos.y].state = (space[pos.x][pos.y].state + 1) % states;
    }
}

// Setters
void Space::setSpace(std::vector<std::vector<Cell>> &space)
{
    this->space = space;
    Vector2i new_space(space.size(), space[0].size());
    for (const std::shared_ptr<Ant> &ant : ants)
        ant->setSpace(new_space);
}

// Displays
void Space::displaySpace()
{
    std::cout << std::endl;
    for (const std::vector<Cell> &line : space)
    {
        for (const Cell &cell : line)
            std::cout << cell.state << " ";
        std::cout << std::endl;
    }
}

void Space::displayAnts()
{
    std::vector<std::vector<Cell>> space_copy(space);

    std::cout << std::endl;
    for (const std::vector<Cell> &line : space_copy)
    {
        for (const Cell &cell : line)
            std::cout << cell.empty << " ";
        std::cout << std::endl;
    }
}

void Space::display()
{
    std::vector<std::vector<Cell>> space_copy(space);
    for (const std::shared_ptr<Ant> &ant : ants)
        space_copy[ant->getPos().x][ant->getPos().y].state = states;

    std::cout << std::endl;
    for (const std::vector<Cell> &line : space_copy)
    {
        for (const Cell &cell : line)
            std::cout << cell.state << " ";
        std::cout << std::endl;
    }
}