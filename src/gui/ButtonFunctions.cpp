#include "gui/ButtonStart.hpp"
#include "gui/ButtonReset.hpp"
#include "gui/ButtonSpace.hpp"
#include "gui/ButtonAnt.hpp"
#include "gui/ButtonColony.hpp"

#include "gui/TextBoxRule.hpp"

#include "gui/MainGrid.hpp"

#include "gui/GUI.hpp"

void ButtonStart::functionButton()
{
    gui->testButton();
}

void ButtonReset::functionButton()
{
    gui->testButton();
}

void ButtonSpace::functionButton()
{
    gui->testButton();
}

void ButtonAnt::functionButton()
{
    gui->testButton();
}

void ButtonColony::functionButton()
{
    gui->testButton();
}

void TextBoxRule::functionButton(const std::string &input)
{
    gui->testTextBox(input);
}

void MainGrid::functionGrid(int x, int y)
{
    gui->testGrid(x, y);
}
