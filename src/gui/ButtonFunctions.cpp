#include "gui/ButtonStart.hpp"
#include "gui/ButtonStep.hpp"
#include "gui/ButtonReset.hpp"
#include "gui/ButtonState.hpp"
#include "gui/ButtonAnt.hpp"
#include "gui/ButtonColony.hpp"

#include "gui/TextBoxRule.hpp"

#include "gui/MainGrid.hpp"

#include "gui/GUI.hpp"

void ButtonStart::functionButton()
{
    gui->switchRunning();
    if (gui->isRunning())
    {
        this->text.setString("Stop");
    }
    else
    {
        setText("Start");
    }
}

void ButtonStep::functionButton()
{
    gui->move();
}

void ButtonReset::functionButton()
{
    gui->clear();

    gui->initColors();
}

void ButtonState::functionButton()
{
    std::string rule_string = gui->getRule();
    std::vector<Rule> rules = stringToRules(rule_string);

    gui->setRuleSize(rules.size());
    gui->initColors();
}

void ButtonAnt::functionButton()
{
    gui->setDirection((gui->getDirection() + 1) % 5);
    switch (gui->getDirection())
    {
    case 0:
        this->setText("Add ant");
        break;
    case 1:
        this->text.setString("UP");
        break;
    case 2:
        this->text.setString("RIGHT");
        break;
    case 3:
        this->text.setString("DOWN");
        break;
    case 4:
        this->text.setString("LEFT");
        break;
    }
}

void ButtonColony::functionButton()
{
}

void TextBoxRule::functionButton(const std::string &input)
{
    int size = input.size();
    gui->setRule(input);
    gui->setRuleSize(size);
    gui->space->setSpace(size);
    gui->initColors();
}

void MainGrid::functionGrid(int x, int y)
{
    // Insert one ant
    int direction_int = gui->getDirection();
    if (direction_int)
    {
        Direction direction;
        switch (direction_int)
        {
        case 1:
            direction = Direction::UP;
            break;
        case 2:
            direction = Direction::LEFT;
            break;
        case 3:
            direction = Direction::DOWN;
            break;
        case 4:
            direction = Direction::RIGHT;
            break;
        }

        std::string rule_string = gui->getRule();
        std::vector<Rule> rules = stringToRules(rule_string);

        std::shared_ptr<Ant> ant = std::make_shared<Ant>(Position2D(x, y), Position2D(this->width, this->height),
                                                         direction, rules);

        ant->display();

        gui->space->insertAnt(ant);

        this->rectangles[x][y]->setFillColor(Color::Red);
    }
}
