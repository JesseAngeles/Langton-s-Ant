#include "logic/Ant.hpp"

// Constructor
Ant::Ant(int x_pos, int y_pos, Direction direction)
    : x_pos(x_pos), y_pos(y_pos), direction(direction)
{
}

// Private functions
void Ant::updateDirection(const Rule &rule)
{
    if (rule == Rule::LEFT)
        if (direction == Direction::LEFT)
            direction = Direction::DOWN;
        else if (direction == Direction::UP)
            direction = Direction::LEFT;
        else if (direction == Direction::RIGHT)
            direction = Direction::UP;
        else if (direction == Direction::DOWN)
            direction = Direction::RIGHT;
    else if (rule == Rule::RIGHT)
        if (direction == Direction::LEFT)
            direction = Direction::UP;
        else if (direction == Direction::UP)
            direction = Direction::RIGHT;
        else if (direction == Direction::RIGHT)
            direction = Direction::DOWN;
        else if (direction == Direction::DOWN)
            direction = Direction::LEFT;
}

// Public functions
void Ant::move(const int &state)
{
    Rule rule_to_apply = rules[state];
    
    updateDirection(rule_to_apply);

    if (direction == Direction::LEFT)
        x_pos--;
    else if (direction == Direction::UP)
        y_pos++;
    else if (direction == Direction::RIGHT)
        x_pos++;
    else if (direction == Direction::LEFT)
        y_pos--;
}

// Overloading
bool Ant::operator<(const Ant &other) const
{
    if (x_pos < other.x_pos)
        return true;
    if (other.x_pos < x_pos)
        return false;

    if (y_pos < other.y_pos)
        return true;

    return false;
}