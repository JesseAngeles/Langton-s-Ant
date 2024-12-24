#include "logic/Ant.hpp"

// Constructor
Ant::Ant(Vector2i pos, Vector2i space, Direction direction, std::vector<Rule> rules, int colony)
    : pos(pos), space(space), direction(direction), rules(rules), colony(0)
{
}

// Private functions

// Public functions
void Ant::rotate(const int &state)
{
    Rule rule_to_apply = rules[state];

    if (rule_to_apply == Rule::LEFT)
    {
        if (direction == Direction::LEFT)
            direction = Direction::DOWN;
        else if (direction == Direction::UP)
            direction = Direction::LEFT;
        else if (direction == Direction::RIGHT)
            direction = Direction::UP;
        else if (direction == Direction::DOWN)
            direction = Direction::RIGHT;
    }
    else if (rule_to_apply == Rule::RIGHT)
    {
        if (direction == Direction::LEFT)
            direction = Direction::UP;
        else if (direction == Direction::UP)
            direction = Direction::RIGHT;
        else if (direction == Direction::RIGHT)
            direction = Direction::DOWN;
        else if (direction == Direction::DOWN)
            direction = Direction::LEFT;
    }
}

Vector2i Ant::getNextMove() const
{
    Vector2i pos = this->pos;

    if (direction == Direction::LEFT)
        pos.x--;
    else if (direction == Direction::UP)
        pos.y++;
    else if (direction == Direction::RIGHT)
        pos.x++;
    else if (direction == Direction::DOWN)
        pos.y--;

    pos.x = (pos.x + space.x) % space.x;
    pos.y = (pos.y + space.y) % space.y;

    return pos;
}

// Overloading
bool Ant::operator<(const Ant &other) const
{
    if (pos.x < other.pos.x)
        return true;
    if (other.pos.x < pos.x)
        return false;

    if (pos.y < other.pos.y)
        return true;

    return false;
}

// Setters
void Ant::setSpace(Vector2i &space)
{
    this->space = space;
    pos.x %= space.x;
    pos.y %= space.y;
}

// Display
void Ant::display()
{
    std::cout << "\n(" << pos.x << "," << pos.y << ") -> ";
    if (direction == Direction::DOWN)
        std::cout << "down";
    else if (direction == Direction::LEFT)
        std::cout << "left";
    else if (direction == Direction::UP)
        std::cout << "up";
    else if (direction == Direction::RIGHT)
        std::cout << "right";

    std::cout << ": ";

    for (const Rule &rule : rules)
        if (rule == Rule::LEFT)
            std::cout << "L";
        else if (rule == Rule::RIGHT)
            std::cout << "R";
}