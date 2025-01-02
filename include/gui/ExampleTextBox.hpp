#ifndef EXAMPLE_TEXT_BOX_HPP
#define EXAMPLE_TEXT_BOX_HPP

#include "gui/components/TextBox.hpp"

using namespace sf;

class ExampleTextBox : public TextBox
{
private:
    std::function<void(const std::string &)> fun; // Usar std::function para la función de callback
public:
    ExampleTextBox(Text);

    void functionButton(const std::string &input);
};

#endif // EXAMPLE_TEXT_BOX_HPP
