#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
#include <vector>

#include "Position2D.hpp"

#include "Direction.hpp"
#include "Rule.hpp"



class Ant
{
private:
    // Attributes
    Position2D pos;
    Direction direction;

    Position2D space;

    int colony;

    // Rules
    std::vector<Rule> rules;

    // Functions

public:
    // Constructor
    Ant(Position2D pos, Position2D space, Direction direction, std::vector<Rule> rules, int colony = 0);

    // Functions
    void rotate(const int &state);
    Position2D getNextMove() const;

    // Overloading
    bool operator<(const Ant &other) const;

    // Getters
    Position2D getPos() const { return pos; }
    Direction getDirection() const { return direction; }
    std::vector<Rule> getRules() const { return rules; }

    // Setters
    void setPos(Position2D &pos) { this->pos = pos; }
    void setDirection(Direction &direction) { this->direction = direction; }
    void setRules(std::vector<Rule> &rules) { this->rules = rules; }
    void setSpace(Position2D &space);

    // Display
    void display();
};

#endif // ANT_HPP