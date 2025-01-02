#ifndef MAIN_GRAPHIC_HPP
#define MAIN_GRAPHIC_HPP

#include <iostream>
#include <functional> // Incluir para std::function

#include "gui/components/Graphic.hpp"

using namespace sf;

class MainGraphic : public Graphic
{
private:
    std::function<float(float)> fun0; // Usar std::function para la función de callback
    std::function<float(float)> fun1; // Usar std::function para la función de callback
public:
    // Constructor
    MainGraphic()
        : Graphic(Vector2f(1275, 7), Vector2f(600, 300), Color::White, Vector2f(0, 0), Vector2f(10, 10))
    {
        drawAxes();

        CircleShape circle(2);
        circle.setRadius(3);
        circle.setFillColor(sf::Color::Red);
        circle.setOutlineThickness(1);
        circle.setOutlineColor(sf::Color::Black);

        sf::VertexArray line(sf::Lines, 2);
        line[0].color = line[1].color = sf::Color::Black;

        this->fun0 = std::bind(&MainGraphic::lineFunction, this, std::placeholders::_1);
        this->fun1 = std::bind(&MainGraphic::squareFunction, this, std::placeholders::_1);

        std::shared_ptr<GraphicFunction> fun = drawFunction(fun0, -10, 10, 1, circle, line);
        fun->addPoint(Vector2f(1, 0), false);
        std::shared_ptr<GraphicFunction> fun2 = drawFunction(fun1, -10, 10, 1, circle, line);
        fun2->addPoint(Vector2f(0, -3), false);
        fun2->addPoint(Vector2f(0, 11), false);

        rescale(sf::Vector2f(-7, -4), sf::Vector2f(4, 4));
    }

    float lineFunction(float x) { return x; }
    float squareFunction(float x) { return x * x; }
};
#endif // MAIN_GRAPHIC_HPP