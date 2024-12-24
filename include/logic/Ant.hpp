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
};

class Ant
{
private:
    // Attributes
    Vector2i pos;
    Direction direction;

    Vector2i space;

    // Rules
    std::vector<Rule> rules;

    // Functions

public:
    // Constructor
    Ant(Vector2i pos, Vector2i space, Direction direction, std::vector<Rule> rules);

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