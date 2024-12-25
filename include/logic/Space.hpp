#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <memory>

#include "Cell.hpp"

#include "Randomizer.hpp"
#include "Rule.hpp"
#include "Ant.hpp"

class Space
{
private:
    // Attributes
    std::vector<std::vector<Cell>> space;
    std::set<std::shared_ptr<Ant>> ants;

    int states;

    Randomizer randomizer;

    // Functions

public:
    // Constructor
    Space(int width, int height, int states, std::set<std::shared_ptr<Ant>> ants);

    // Functions
    void move();
    void switchCell(Position2D pos) { space[pos.x][pos.y].state = (space[pos.x][pos.y].state + 1) % states; }
    bool insertAnt(std::shared_ptr<Ant> &ant);
    void removeAnt(Position2D pos);

    int insertColony(Position2D center, float radius, int population, std::vector<Rule> rules, int colony);

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