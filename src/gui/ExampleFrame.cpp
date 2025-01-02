#include "gui/ExampleFrame.hpp"

// Constructor
ExampleFrame::ExampleFrame()
    : Frame(Vector2f(0, 0), Vector2f(1000, 500), Color(0, 191, 178)) {
    // Personalizar el frame si es necesario
    background.setOutlineColor(Color::Blue); // Añadir un borde azul
    background.setOutlineThickness(2.f);
}