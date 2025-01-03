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
#include "gui/ButtonState.hpp"
#include "gui/ButtonAnt.hpp"
#include "gui/ButtonColony.hpp"

using namespace sf;

class GUI : public MainWindow
{
private:
    // Attributes
    int option = 0;
    int rule_rize;
    bool is_running = false;
    std::string current_rule;

    // GUI Components
    sf::Font font;
    sf::Text default_text;

    Frame frame;
    MainGraphic graphic;
    MainGrid grid;

    TextBoxRule tb_rule;

    ButtonStart btn_start;
    ButtonReset btn_reset;
    ButtonState btn_state;
    ButtonAnt btn_ant;
    ButtonColony btn_colony;

    void initDefaultText();

public:
    // Constructor
    GUI(const std::shared_ptr<Space> &);
    void run() override;

    // Logic
    std::shared_ptr<Space> space;

    // Test functions
    void testButton() { std::cout << "Test\n"; };
    void testTextBox(std::string text) { std::cout << "Test: " << text << std::endl; }
    void testGrid(int x, int y) { std::cout << "Test: (" << x << "," << y << ")\n"; }

    // Getters
    int getOption() const { return option; }
    int getRuleSize() const { return rule_rize; }
    bool isRunning() const { return is_running; }
    std::string getRule() const { return current_rule; }

    // Setters
    void setOption(int option) { this->option = option; }
    void setRuleSize(int rule_size) { this->rule_rize = rule_rize; }
    void switchRunning() { is_running = !is_running; }
    void setRule(std::string current_rule) { this->current_rule = current_rule; }
};

#endif // GUI_HPP