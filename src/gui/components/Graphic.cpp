#include "gui/components/Graphic.hpp"

// Constructor
Graphic::Graphic(const sf::Vector2f &position, const sf::Vector2f &size,
                 const sf::Color color, const sf::Vector2f &min_point, const sf::Vector2f &max_point)
    : Frame(position, size, color), min_point(min_point), max_point(max_point)
{
    calculateScale();
    calculateCenter();
}

// Protected functions
void Graphic::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Frame::draw(target, states);

    for (const sf::VertexArray &axis : axes)
        target.draw(axis);

    for (const std::shared_ptr<GraphicFunction> &function : functions)
    {
        for (const sf::VertexArray &line : function->getLines())
            if (background.getGlobalBounds().contains(line[0].position) &&
                background.getGlobalBounds().contains(line[1].position))
                target.draw(line, states);
                
        for (const sf::CircleShape &dot : function->getDots())
        {
            if (background.getGlobalBounds().contains(dot.getPosition()))
                target.draw(dot, states);
        }
    }
}

void Graphic::calculateScale()
{
    scale.x = size.x / std::abs(max_point.x - min_point.x);
    scale.y = size.y / std::abs(max_point.y - min_point.y);
}

void Graphic::calculateCenter()
{
    origin.x = position.x - min_point.x * scale.x;
    origin.y = position.y + max_point.y * scale.y;
}

// Public functions
void Graphic::drawAxes()
{
    axes.clear(); // Limpia los ejes previos
    for (float x = position.x; x <= position.x + size.x; x += scale.x)
    {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(x, position.y);
        line[1].position = sf::Vector2f(x, position.y + size.y);
        line[0].color = line[1].color = sf::Color::Black;

        axes.push_back(line);
    }

    for (float y = position.y; y <= position.y + size.y; y += scale.y)
    {
        sf::VertexArray line(sf::Lines, 2);
        line[0].position = sf::Vector2f(position.x, y);
        line[1].position = sf::Vector2f(position.x + size.x, y);
        line[0].color = line[1].color = sf::Color::Black;

        axes.push_back(line);
    }
}

void Graphic::rescale(const sf::Vector2f &min_point, const sf::Vector2f &max_point)
{
    this->min_point = min_point;
    this->max_point = max_point;

    calculateScale();
    calculateCenter();

    axes.clear();
    drawAxes();

    for (const std::shared_ptr<GraphicFunction> &function : functions)
        function->rescale(scale, origin);
}

std::shared_ptr<GraphicFunction> Graphic::drawFunction(
    std::function<float(float)> f, const float &min, const float &max,
    const float &increment, const sf::CircleShape &circle, const std::optional<sf::VertexArray> line)
{
    auto new_function = std::make_shared<GraphicFunction>(position, size, origin, scale);
    new_function->setDefaultDot(circle);
    if (line.has_value())
        new_function->setDefaultLine(line.value());

    for (float i = min; i <= max; i += increment)
        new_function->addPoint(sf::Vector2f(i, f(i)));

    functions.push_back(new_function);
    return new_function;
}