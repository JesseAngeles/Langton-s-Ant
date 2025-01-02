#include "gui/ExampleGraphic.hpp"

ExampleGraphic::ExampleGraphic()
    : Graphic(Vector2f(320, 5), Vector2f(300, 300), Color(155, 255, 100), Vector2f(-10, -10), Vector2f(10, 10))
{
    drawAxes();

    CircleShape circle(2);
    circle.setRadius(3);
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineThickness(1);
    circle.setOutlineColor(sf::Color::Black);

    sf::VertexArray line(sf::Lines, 2);
    line[0].color = line[1].color = sf::Color::Black;

    this->fun0 = std::bind(&ExampleGraphic::lineFunction, this, std::placeholders::_1);
    this->fun1 = std::bind(&ExampleGraphic::squareFunction, this, std::placeholders::_1);

    std::shared_ptr<GraphicFunction> fun = drawFunction(fun0, -10, 10, 1, circle, line);
    fun->addPoint(Vector2f(1, 0), false);
    std::shared_ptr<GraphicFunction> fun2 = drawFunction(fun1, -10, 10, 1, circle, line);
    fun2->addPoint(Vector2f(0, -3), false);
    fun2->addPoint(Vector2f(0, 11), false);

    rescale(sf::Vector2f(-7, -4), sf::Vector2f(4, 4));

}

float ExampleGraphic::lineFunction(float x)
{
    return x;
}

float ExampleGraphic::squareFunction(float x)
{
    return x * x;
}
