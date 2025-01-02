#ifndef BUTTON_RESET_HPP
#define BUTTON_RESET_HPP

#include <iostream>
#include <functional>

#include "gui/components/Button.hpp"

class GUI;

using namespace sf;

class ButtonReset : public Button
{
private:
    std::function<void()> fun;
    GUI *gui;

public:
    ButtonReset(GUI *gui, Text text)
        : Button(Vector2f(10, 70), Vector2f(200, 50), Color(255, 255, 100), text),
          gui(gui)
    {
        this->text.setString("Add ant");

        // Definir el callback para el evento onClick usando std::bind
        this->fun = std::bind(&ButtonReset::functionButton, this);

        this->setOnClick(this->fun); // Asignar el callback

        background.setOutlineColor(Color::Blue); // Añadir un borde azul
        background.setOutlineThickness(2.f);
    }

    void functionButton();
};

#endif // BUTTON_RESET_HPP