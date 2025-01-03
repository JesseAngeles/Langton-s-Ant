#ifndef MAIN_GRAPHIC_HPP
#define MAIN_GRAPHIC_HPP

#include <iostream>
#include <functional> // Incluir para std::function

#include "gui/components/Graphic.hpp"

class GUI;

using namespace sf;

class MainGraphic : public Graphic
{
private:
    std::function<float(float)> fun0; // Usar std::function para la función de callback
    std::function<float(float)> fun1;

    std::vector<std::shared_ptr<GraphicFunction>> functions;

    GUI *gui;
    int max = 0;

public:
    // Constructor
    MainGraphic(GUI *gui)
        : Graphic(Vector2f(1275, 7), Vector2f(600, 600), Color::White, Vector2f(0, 0), Vector2f(10, 10)),
          gui(gui)
    {
        CircleShape circle(2);
        circle.setRadius(3);
        circle.setFillColor(sf::Color::Red);
        circle.setOutlineThickness(1);
        circle.setOutlineColor(sf::Color::Black);

        CircleShape circle_log = circle;
        circle_log.setOutlineThickness(0);

        sf::VertexArray line(sf::Lines, 2);
        line[0].color = line[1].color = sf::Color::Black;

        this->fun0 = std::bind(&MainGraphic::lineFunction, this, std::placeholders::_1);
        this->fun1 = std::bind(&MainGraphic::lineFunction, this, std::placeholders::_1);

        std::shared_ptr<GraphicFunction> fun_lineal = drawFunction(fun0, 0, 0, 1, circle, line);
        std::shared_ptr<GraphicFunction> fun_log = drawFunction(fun1, 0, 0, 1, circle_log, line);
        functions.push_back(fun_lineal);
        functions.push_back(fun_log);
    }

    void clear();

    float lineFunction(float x) { return x; }

    void updateFunction();
};
#endif // MAIN_GRAPHIC_HPP