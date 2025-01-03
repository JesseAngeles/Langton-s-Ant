#include "gui/ButtonStart.hpp"
#include "gui/ButtonReset.hpp"
#include "gui/ButtonState.hpp"
#include "gui/ButtonAnt.hpp"
#include "gui/ButtonColony.hpp"

#include "gui/TextBoxRule.hpp"

#include "gui/MainGrid.hpp"

#include "gui/GUI.hpp"

void ButtonStart::functionButton()
{
    if (gui->isRunning())
    {
        this->text.setString("Stop");
    }
    else
    {
        setText("Start");
    }

    gui->switchRunning();
}

void ButtonReset::functionButton()
{
    if (gui->isRunning())
        gui->switchRunning();

    gui->space->clear();
}

void ButtonState::functionButton()
{
    std::string rule_string = gui->getRule();
    std::vector<Rule> rules = stringToRules(rule_string);

    gui->setRuleSize(rules.size());
}

void ButtonAnt::functionButton()
{

    gui->setOption(1);
}

void ButtonColony::functionButton()
{
}

void TextBoxRule::functionButton(const std::string &input)
{
    gui->setRule(input);
}

void MainGrid::functionGrid(int x, int y)
{
    switch (gui->getOption())
    {
    // Añadir hormiga
    case 1:
    {
        std::string rule_string = gui->getRule();
        std::vector<Rule> rules = stringToRules(rule_string);

        std::shared_ptr<Ant> ant = std::make_shared<Ant>(
            Position2D(x, y), Position2D(this->width, this->height), Direction::UP, rules);
        gui->space->insertAnt(ant);

        ant->display();

        gui->space->displayAnts();

        this->rectangles[x][y]->setFillColor(Color::Red);

        gui->setOption(0);
    }
    break;

    default:
        break;
    }
}
