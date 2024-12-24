#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include <vector>

#include "Direction.hpp"
#include "Rule.hpp"

struct Vector2i
{
    int x;
    int y;
    Vector2i() = default;
    Vector2i(int x, int y) : x(x), y(y) {}
    bool operator==(const Vector2i &other) const { return x == other.x && y == other.y; }
    bool operator<(const Vector2i &other) const
    {
        if (x < other.x)
            return true;
        if (other.x < x)
            return false;

        if (y < other.y)
            return true;
        
        return false;
    }
};

class Ant
{
private:
    // Attributes
    Vector2i pos;
    Direction direction;

    Vector2i space;

    int colony;

    // Rules
    std::vector<Rule> rules;

    // Functions

public:
    // Constructor
    Ant(Vector2i pos, Vector2i space, Direction direction, std::vector<Rule> rules, int colony = 0);

    // Functions
    void rotate(const int &state);
    Vector2i getNextMove() const;

    // Overloading
    bool operator<(const Ant &other) const;

    // Getters
    Vector2i getPos() const { return pos; }
    Direction getDirection() const { return direction; }
    std::vector<Rule> getRules() const { return rules; }

    // Setters
    void setPos(Vector2i &pos) { this->pos = pos; }
    void setDirection(Direction &direction) { this->direction = direction; }
    void setRules(std::vector<Rule> &rules) { this->rules = rules; }
    void setSpace(Vector2i &space);

    // Display
    void display();
};

#endif // ANT_HPP