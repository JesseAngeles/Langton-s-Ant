#include <iostream>

#include "logic/Space.hpp"
#include "logic/Ant.hpp"

#include "gui/MainWindow.hpp"

#include "gui/ExampleFrame.hpp"
#include "gui/ExampleButton.hpp"
#include "gui/ExampleTextBox.hpp"
#include "gui/ExampleGraphic.hpp"
#include "gui/ExampleGrid.hpp"

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

    MainWindow gui(1000, 500, "Hola mundo", Color::Cyan);
    
    Font font;
    font.loadFromFile("./resources/fonts/Roboto-Medium.ttf");

    Text text_default_format;
    text_default_format.setFont(font);
    text_default_format.setFillColor(Color::Black);
    text_default_format.setCharacterSize(20);

    ExampleFrame frame;
    ExampleButton btn(text_default_format);
    ExampleTextBox text_box(text_default_format);
    ExampleGraphic graphic;
    ExampleGrid grid;

    frame.addChild(std::make_shared<ExampleButton>(btn));
    frame.addChild(std::make_shared<ExampleTextBox>(text_box));
    frame.addChild(std::make_shared<ExampleGraphic>(graphic));
    frame.addChild(std::make_shared<ExampleGrid>(grid));
    
    gui.addFrame(frame);
    gui.run();

    return 0;
}