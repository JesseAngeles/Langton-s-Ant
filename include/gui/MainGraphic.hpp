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
    std::vector<std::shared_ptr<GraphicFunction>> functions;

    GUI *gui;
    int max = 0;

    CircleShape lineal_circle;
    CircleShape log_circle;

public:
    // Constructor
    MainGraphic(GUI *gui)
        : Graphic(Vector2f(1275, 7), Vector2f(600, 600), Color::White, Vector2f(0, 0), Vector2f(10, 10)),
          gui(gui)
    {
        CircleShape circle(2);
        circle.setRadius(3);
        circle.setFillColor(sf::Color::Red);
        circle.setOutlineThickness(0);
        circle.setOutlineColor(sf::Color::Black);

        lineal_circle = circle;
        log_circle = circle;

        sf::VertexArray line(sf::Lines, 2);
        line[0].color = line[1].color = sf::Color::Black;

        this->fun0 = std::bind(&MainGraphic::lineFunction, this, std::placeholders::_1);

        std::shared_ptr<GraphicFunction> fun_lineal = drawFunction(fun0, 0, 0, 1, circle, line);
        std::shared_ptr<GraphicFunction> fun_log = drawFunction(fun0, 0, 0, 1, log_circle, line);
        functions.push_back(fun_lineal);
        functions.push_back(fun_log);
    }

    void setColors(const std::vector<Color> &colors)
    {
        functions.clear();
        for (const Color &color : colors)
        {
            lineal_circle.setFillColor(color);
            log_circle.setFillColor(color);

            std::shared_ptr<GraphicFunction> lineal_fun = drawFunction(fun0, 0, 0, 1, lineal_circle);
            std::shared_ptr<GraphicFunction> log_fun = drawFunction(fun0, 0, 0, 1, log_circle);
            
            functions.push_back(lineal_fun);
            functions.push_back(log_fun);
        }

    }

    void clear();

    float lineFunction(float x) { return x; }

    void updateFunction();
};
#endif // MAIN_GRAPHIC_HPP