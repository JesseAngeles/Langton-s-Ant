#include <iostream>

#include "logic/Space.hpp"
#include "logic/Ant.hpp"

using namespace std;

int main()
{
    // Crear hormiga
    set<std::shared_ptr<Ant>> ants;
    ants.insert(std::make_shared<Ant>(3, 3, Direction::UP));

    std::string rule = "RL";

    // Crear el espacio
    Space space(6, 6, ants, stringToRules(rule));

    for (int i = 0; i < 1; i++)
    {
        space.displayAnts();
        space.move();
    }

    space.displayAnts();

    return 0;
}