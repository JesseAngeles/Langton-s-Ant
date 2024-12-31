#include <iostream>

#include "logic/Space.hpp"
#include "logic/Ant.hpp"

#include "gui/MainWindow.hpp"

using namespace std;

int main()
{
    // Metaparametros
    int states = 2;
    int width = 6;
    int height = 6;

    // Crear regla
    std::string rule_string = "RL";
    std::vector<Rule> rule = stringToRules(rule_string);
    rule.resize(states);

    // Crear hormiga
    Ant ant(Position2D(2, 2), Position2D(width, height), Direction::UP, rule);
    set<std::shared_ptr<Ant>> ants;
    ants.insert(std::make_shared<Ant>(ant));

    // Crear el espacio
    Space space(width, height, states, ants);

    for (int i = 0; i < 10; i++)
    {
        space.move();
    }

    space.display();
    space.displayAnts();


    // Interfaz grafica
    MainWindow gui(800, 800, "Hola mundo", Color(100, 255, 130));
    gui.mainLoop();

    return 0;
}