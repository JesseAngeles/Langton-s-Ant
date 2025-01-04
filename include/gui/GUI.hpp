#ifndef GUI_HPP
#define GUI_HPP

#include <memory>

#include "logic/Space.hpp"

#include "gui/components/MainWindow.hpp"
#include "gui/MainGraphic.hpp"
#include "gui/MainGrid.hpp"
#include "gui/TextBoxRule.hpp"
#include "gui/TextBoxRadio.hpp"
#include "gui/TextBoxSize.hpp"
#include "gui/ButtonStart.hpp"
#include "gui/ButtonStep.hpp"
#include "gui/ButtonReset.hpp"
#include "gui/ButtonState.hpp"
#include "gui/ButtonAnt.hpp"
#include "gui/ButtonColony.hpp"

using namespace sf;

class GUI : public MainWindow
{
private:
    // Attributes
    int direction = 0;
    int generation_count = 0;
    int current_colonies = 0;
    int rule_size;
    int size = 1;
    int radio = 1;
    bool is_running = false;
    bool is_colony = false;

    std::string current_rule;

    // GUI Components
    sf::Font font;
    sf::Text default_text;
    sf::Text generation_count_text;
    sf::Text max_generation_text;
    sf::Text radio_text;
    sf::Text size_text;
    std::vector<Color> colors;

    Frame frame;
    std::shared_ptr<MainGraphic> graphic;
    std::shared_ptr<MainGrid> grid;

    std::shared_ptr<TextBoxRule> tb_rule;
    std::shared_ptr<TextBoxRadio> tb_radio;
    std::shared_ptr<TextBoxSize> tb_size;

    std::shared_ptr<ButtonStart> btn_start;
    std::shared_ptr<ButtonStep> btn_step;
    std::shared_ptr<ButtonReset> btn_reset;
    std::shared_ptr<ButtonState> btn_state;
    std::shared_ptr<ButtonAnt> btn_ant;
    std::shared_ptr<ButtonColony> btn_colony;

    void initDefaultText();
    void render() override;

public:
    // Constructor
    GUI(const std::shared_ptr<Space> &);
    void run() override;

    // Logic
    std::shared_ptr<Space> space;

    void move();
    void clear();
    void initColors();
    Color generateRandomColor();

    // Test functions
    void testButton() { std::cout << "Test\n"; };
    void testTextBox(std::string text) { std::cout << "Test: " << text << std::endl; }
    void testGrid(int x, int y) { std::cout << "Test: (" << x << "," << y << ")\n"; }

    // Getters
    int getDirection() const { return direction; }
    int getGenerationCount() const { return generation_count; }
    int getRuleSize() const { return rule_size; }
    bool isRunning() const { return is_running; }
    bool isColony() const { return is_colony; }
    std::string getRule() const { return current_rule; }
    int getSize() const { return size; }
    int getRadio() const { return radio; }
    int getCurrentColonies() const {return current_colonies; }

    // Setters
    void setDirection(int direction) { this->direction = direction; }
    void resetGenerationCount() { generation_count = 0; }
    void setRuleSize(int rule_size) { this->rule_size = rule_size; }
    void switchRunning() { is_running = !is_running; }
    void switchColony() { is_colony = !is_colony; }
    void setRule(std::string current_rule) { this->current_rule = current_rule; }
    void setSize(int size) { this->size = size; }
    void setRadio(int radio) { this->radio = radio; }
    void setMaxGenerationText(int x) { max_generation_text.setString("Max: " + std::to_string(x)); }
    void setGenerationCountText() { generation_count_text.setString("Generation: " + std::to_string(generation_count)); }
    void setButtonAntText(const std::string &content) { btn_ant->setText(content); }
    void setCurrentColonies(int current_colonies) {this->current_colonies = current_colonies; }
};

#endif // GUI_HPP