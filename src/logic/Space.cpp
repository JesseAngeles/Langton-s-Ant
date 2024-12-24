#include "logic/Space.hpp"

// Constructor
Space::Space(int width, int height, std::set<std::shared_ptr<Ant>> ants, std::vector<Rule> rules)
    : space(width, std::vector<int>(height, 0)), ants(ants), rules(rules)
{
}

// Private functions

// Public functions
void Space::move() const
{
    for (const std::shared_ptr<Ant> &ant : ants)
    {

    }
}

// Displays
void Space::displaySpace()
{
    std::cout << std::endl;
    for (const std::vector<int> &line : space)
    {
        for (const int &cell : line)
            std::cout << cell << " ";
        std::cout << std::endl;
    }
}

void Space::displayAnts()
{
    std::vector<std::vector<int>> space_copy(space.size(), std::vector<int>(space[0].size(), 0));
    for (const std::shared_ptr<Ant> &ant : ants)
        space_copy[ant->getXPos()][ant->getYPos()] = 1;
    
    std::cout << std::endl;
    for (const std::vector<int> &line : space_copy)
    {
        for (const int &cell : line)
            std::cout << cell << " ";
        std::cout << std::endl;
    }

}

void Space::display()
{

    std::cout << std::endl;
}