#ifndef BUTTON_COLONY_HPP
#define BUTTON_COLONY_HPP

#include <iostream>
#include <functional>
#include "gui/components/Button.hpp"

class GUI;

using namespace sf;

class ButtonColony : public Button
{
private:
    std::function<void()> fun;
    GUI *gui;

public:
    ButtonColony(GUI *gui, Text text)
        : Button(Vector2f(10, 310), Vector2f(200, 50), Color(255, 255, 100), text),
          gui(gui)
    {
        this->text.setString("Add ant");

        // Definir el callback para el evento onClick usando std::bind
        this->fun = std::bind(&ButtonColony::functionButton, this);

        this->setOnClick(this->fun); // Asignar el callback

        background.setOutlineColor(Color::Blue); // Añadir un borde azul
        background.setOutlineThickness(2.f);
    }

    void functionButton();
};

#endif // BUTTON_COLONY_HPP