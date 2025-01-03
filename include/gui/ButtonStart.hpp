#ifndef BUTTON_START_HPP
#define BUTTON_START_HPP

#include <iostream>
#include <functional>
#include "gui/components/Button.hpp"

// Declaración hacia adelante de GUI
class GUI;

using namespace sf;

class ButtonStart : public Button
{
private:
    std::function<void()> fun;
    GUI *gui;
    
public:
    ButtonStart(GUI *gui, Text text)
        : Button(Vector2f(10, 10), Vector2f(200, 50), Color(255, 255, 100), text),
          gui(gui)
    {
        this->fun = std::bind(&ButtonStart::functionButton, this);

        this->setOnClick(this->fun);

        background.setOutlineColor(Color::Blue); 
        background.setOutlineThickness(2.f);
    }

    void functionButton();
};

#endif // BUTTON_START_HPP
