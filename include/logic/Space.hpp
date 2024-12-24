#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <optional>
#include <memory>

#include "Randomizer.hpp"
#include "Rule.hpp"
#include "Ant.hpp"

struct Cell
{
    int state;
    std::optional<std::shared_ptr<Ant>> ant;
    Cell(int state) : state(state), ant(std::nullopt) {}
    Cell(int state, std::shared_ptr<Ant>) : state(state), ant(ant) {}
};

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
    void switchCell(Vector2i pos) { space[pos.x][pos.y].state = (space[pos.x][pos.y].state + 1) % states; }
    bool insertAnt(std::shared_ptr<Ant> &ant);
    void removeAnt(Vector2i pos);

    int insertColony(Vector2i center, float radius, int population, std::vector<Rule> rules, int colony);

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