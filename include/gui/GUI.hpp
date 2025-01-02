#ifndef GUI_HPP
#define GUI_HPP

#include <memory>

#include "logic/Space.hpp"

#include "gui/components/MainWindow.hpp"
#include "gui/MainGraphic.hpp"
#include "gui/MainGrid.hpp"
#include "gui/TextBoxRule.hpp"
#include "gui/ButtonStart.hpp"
#include "gui/ButtonReset.hpp"
#include "gui/ButtonSpace.hpp"
#include "gui/ButtonAnt.hpp"
#include "gui/ButtonColony.hpp"

using namespace sf;

class GUI : public MainWindow
{
private:
    // Attributes
    int option;

    // Logic
    std::shared_ptr<Space> space;

    // GUI Components
    sf::Font font;
    sf::Text default_text;

    Frame frame;
    MainGraphic graphic;
    MainGrid grid;

    TextBoxRule tb_rule;

    ButtonStart btn_start;
    ButtonReset btn_reset;
    ButtonSpace btn_space;
    ButtonAnt btn_ant;
    ButtonColony btn_colony;

    void initDefaultText();

public:
    // Constructor
    GUI(const std::shared_ptr<Space> &);

    void testButton() { std::cout << "Test\n"; };
    void testTextBox(std::string text) { std::cout << "Test: " << text << std::endl; }
    void testGrid(int x, int y) { std::cout << "Test: (" << x << "," << y << ")\n"; }

    // Getters

    // Setters
    void setOption(int option) { this->option = option; }
};

#endif // GUI_HPP