#ifndef ANT_HPP
#define ANT_HPP

#include <vector>

#include "Direction.hpp"
#include "Rule.hpp"

class Ant
{
private:
    // Attributes
    int x_pos;
    int y_pos;
    Direction direction;

    // Rules
    std::vector<Rule> rules;

    // Functions
    void updateDirection(const Rule &rule);

public:
    // Constructor
    Ant(int x_pos, int y_pos, Direction direction = Direction::UP);

    // Functions
    void move(const int &state);

    // Overloading
    bool operator<(const Ant &other) const;

    // Getters
    int getXPos() const { return x_pos; }
    int getYPos() const { return y_pos; }
    Direction getDirection() const { return direction; }
    std::vector<Rule> getRules() const { return rules; }

    // Setters
    void setXPos(int &x_pos) { this->x_pos = x_pos; }
    void setYPos(int &y_pos) { this->y_pos = y_pos; }
    void setDirection(Direction &direction) { this->direction = direction; }
    void setRules(std::vector<Rule> &rules) { this->rules = rules; }
};

#endif // ANT_HPP