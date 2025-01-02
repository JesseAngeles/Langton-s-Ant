#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <functional>

#include "gui/components/Frame.hpp"

class Grid : public Frame
{
protected:
    // Attributes
    int width;
    int height;
    sf::Vector2f scale;
    std::function<void(int, int)> onCellClick;

    std::vector<std::vector<std::shared_ptr<sf::RectangleShape>>> rectangles;
    std::vector<sf::VertexArray> axes;

    // Functions
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void handleEvent(const sf::Event &event) override;
    void calculateScale();

public:
    // Constructor
    Grid(const sf::Vector2f &position, const sf::Vector2f &size, const int &width, const int &height);

    void drawAxes();

    // Functions

    // Setters
    void setonCellClick(std::function<void(int, int)> callback) { onCellClick = callback; }
};

#endif // GRID_HPP