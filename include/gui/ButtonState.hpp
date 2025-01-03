#ifndef BUTTON_STATE_HPP
#define BUTTON_STATE_HPP

#include <iostream>
#include <functional>
#include "gui/components/Button.hpp"

// Declaración hacia adelante de GUI
class GUI;

using namespace sf;

class ButtonState : public Button
{
private:
    std::function<void()> fun;
    GUI *gui;
    
public:
    ButtonState(GUI *gui, Text text) // Recibe un puntero a GUI
        : Button(Vector2f(10, 190), Vector2f(200, 50), Color(255, 255, 100), text),
          gui(gui) // Inicializa el puntero
    {
        this->text.setString("Space");

        // Definir el callback para el evento onClick usando std::bind
        this->fun = std::bind(&ButtonState::functionButton, this);

        this->setOnClick(this->fun); // Asignar el callback

        background.setOutlineColor(Color::Blue); // Añadir un borde azul
        background.setOutlineThickness(2.f);
    }

    void functionButton();
};

#endif // BUTTON_STATE_HPP
