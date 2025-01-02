#ifndef EXAMPLE_GRAPHIC_HPP
#define EXAMPLE_GRAPHIC_HPP

#include <iostream>
#include <functional> // Incluir para std::function

#include "gui/components/Graphic.hpp"

using namespace sf;

class ExampleGraphic : public Graphic
{
private:
    std::function<float(float)> fun0; // Usar std::function para la función de callback
    std::function<float(float)> fun1; // Usar std::function para la función de callback
public:
    // Constructor
    ExampleGraphic();

    float lineFunction(float);
    float squareFunction(float);
};

#endif // EXAMPLE_GRAPHIC_HPP
