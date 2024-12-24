#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <vector>
#include <set>
#include <memory>

#include "Rule.hpp"
#include "Ant.hpp"

class Space
{
private:
    // Attributes
    std::vector<std::vector<int>> space;
    std::set<std::shared_ptr<Ant>> ants;

    std::vector<Rule> rules;
    int states;

public:
    // Constructor
    Space(int width, int height, std::set<std::shared_ptr<Ant>> ants, std::vector<Rule> rules);

    // Functions
    void move() const;

    void insertAnt(std::shared_ptr<Ant> ant) { ants.insert(ant); }

    // Getters
    std::vector<std::vector<int>> getSpace() const { return space; }
    std::set<std::shared_ptr<Ant>> getAnts() const { return ants; }
    std::vector<Rule> getRules() const { return rules; }
    int getStates() const { return states; }

    // Setters
    void setSpace(std::vector<std::vector<int>> &space) { this->space = space; }
    void setAnts(std::set<std::shared_ptr<Ant>> &ants) { this->ants = ants; }
    void setSpace(int &states) { this->states = states; }
    void setRules(std::vector<Rule> &rules) { this->rules = rules; }

    // Display
    void displaySpace();
    void displayAnts();
    void display();
};

#endif // SPACE_HPP