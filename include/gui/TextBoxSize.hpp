#ifndef TEXT_BOX_SIZE_HPP
#define TEXT_BOX_SIZE_HPP

#include <iostream>

#include "gui/components/TextBox.hpp"

using namespace sf;

class GUI;

class TextBoxSize : public TextBox
{
private:
    std::function<void(const std::string &)> fun;
    GUI *gui;

public:
    TextBoxSize(GUI *gui, Text text)
        : TextBox(Vector2f(110, 490), Vector2f(100, 50), Color(Color::White), text, "", 20),
          gui(gui)
    {
        this->text.setCharacterSize(10);

        // Definir el callback para el evento onClick usando std::bind
        this->fun = std::bind(&TextBoxSize::functionButton, this, std::placeholders::_1);

        this->setOnEnter(this->fun); // Asignar el callback

        background.setOutlineColor(Color::Blue);
        background.setOutlineThickness(2.f);
    }

    void functionButton(const std::string &input);
};

#endif // TEXT_BOX_SIZE_HPP
