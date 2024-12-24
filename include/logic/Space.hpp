#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <memory>

#include "Rule.hpp"
#include "Ant.hpp"

struct Cell
{
    int state;
    bool empty;
    Cell(int state, bool empty) : state(state), empty(empty) {}
};

class Space
{
private:
    // Attributes
    std::vector<std::vector<Cell>> space;
    std::set<std::shared_ptr<Ant>> ants;

    int states;

public:
    // Constructor
    Space(int width, int height, int states, std::set<std::shared_ptr<Ant>> ants);

    // Functions
    void move();

    void insertAnt(std::shared_ptr<Ant> ant) { ants.insert(ant); }

    // Getters
    std::vector<std::vector<Cell>> getSpace() const { return space; }
    std::set<std::shared_ptr<Ant>> getAnts() const { return ants; }
    int getStates() const { return states; }

    // Setters
    void setSpace(std::vector<std::vector<Cell>> &space);
    void setAnts(std::set<std::shared_ptr<Ant>> &ants) { this->ants = ants; }
    void setSpace(int &states) { this->states = states; }

    // Display
    void displaySpace();
    void displayAnts();
    void display();
};

#endif // SPACE_HPP