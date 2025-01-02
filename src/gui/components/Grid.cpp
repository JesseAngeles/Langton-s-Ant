#include "gui/components/Grid.hpp"

// Constructor
Grid::Grid(const sf::Vector2f &position, const sf::Vector2f &size, const int &width, const int &height)
    : Frame(position, size), width(width), height(height),
      rectangles(width, std::vector<std::shared_ptr<sf::RectangleShape>>(height))
{
    calculateScale();

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            sf::RectangleShape rectangle;
            rectangle.setFillColor(sf::Color::White);
            rectangle.setSize(scale);
            rectangle.setPosition(sf::Vector2f(i * scale.x + position.x, j * scale.y + position.y));

            rectangles[i][j] = std::make_shared<sf::RectangleShape>(rectangle);
        }
    }
}

#include <iostream>

// Protected function
void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    Frame::draw(target, states);

    for (const std::vector<std::shared_ptr<sf::RectangleShape>> &line : rectangles)
        for (const std::shared_ptr<sf::RectangleShape> &rectangle : line)
            target.draw(*rectangle);

    for (const sf::VertexArray &axis : axes)
        target.draw(axis);
}

void Grid::handleEvent(const sf::Event &event)
{
    if (event.type == sf::Event::MouseButtonPressed)
        if (event.mouseButton.button == sf::Mouse::Left)
            if (background.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                if (onCellClick)
                {
                    int x = (event.mouseButton.x - position.x) / scale.x;
                    int y = (event.mouseButton.y - position.y) / scale.y;

                    onCellClick(x, y);
                }
}

void Grid::calculateScale()
{
    scale.x = size.x / static_cast<float>(width);
    scale.y = size.y / static_cast<float>(height);
}

// Public functions
void Grid::drawAxes()
{
    axes.clear();
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