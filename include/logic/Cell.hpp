#ifndef CELL_HPP
#define CELL_HPP

#include <optional>
#include <memory>

#include "Ant.hpp"

struct Cell
{
    int state;
    std::optional<std::shared_ptr<Ant>> ant;
    Cell(int state) : state(state), ant(std::nullopt) {}
    Cell(int state, std::shared_ptr<Ant>) : state(state), ant(ant) {}
};

#endif // CELL_HPP