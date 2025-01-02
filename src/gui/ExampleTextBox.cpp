#include "gui/ExampleTextBox.hpp"

#include <iostream>

ExampleTextBox::ExampleTextBox(Text text)
    : TextBox(Vector2f(10, 100), Vector2f(200, 50), Color(Color::White), text, "", 20)
{
    this->text.setCharacterSize(10);
    
    // Definir el callback para el evento onClick usando std::bind
    this->fun = std::bind(&ExampleTextBox::functionButton, this, std::placeholders::_1); 

    this->setOnEnter(this->fun); // Asignar el callback

    background.setOutlineColor(Color::Blue);
    background.setOutlineThickness(2.f);
}

void ExampleTextBox::functionButton(const std::string &input)
{
   std::cout << "mensaje: " << input << std::endl;
}

