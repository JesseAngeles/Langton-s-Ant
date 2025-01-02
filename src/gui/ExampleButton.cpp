#include "gui/ExampleButton.hpp"

ExampleButton::ExampleButton(const Text &text)
    : Button(Vector2f(10, 10), Vector2f(300, 50), Color(255, 255, 100), text)
{
    this->text.setString("Boton");

    // Definir el callback para el evento onClick usando std::bind
    this->fun = std::bind(&ExampleButton::functionButton, this);

    this->setOnClick(this->fun); // Asignar el callback

    background.setOutlineColor(Color::Blue); // Añadir un borde azul
    background.setOutlineThickness(2.f);
}

void ExampleButton::functionButton()
{
   std::cout << "Boton de prueba" << std::endl;
}
