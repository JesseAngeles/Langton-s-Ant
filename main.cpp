#include <iostream>

#include "logic/Space.hpp"
#include "logic/Ant.hpp"

#include "gui/components/MainWindow.hpp"

#include "gui/GUI.hpp"

#include "gui/MainGrid.hpp"
#include "gui/MainGraphic.hpp"
#include "gui/ButtonAnt.hpp"

using namespace std;

int main()
{
    // Metaparametros
    int states = 2;
    int width = 10;
    int height = 10;
    
    std::set<std::shared_ptr<Ant>> ants;

    auto space = std::make_shared<Space>(width, height, states, ants);

    GUI gui(space);
    gui.run();

    return 0;
}
