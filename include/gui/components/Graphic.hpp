#ifndef GRAPHIC_HPP
#define GRAPHIC_HPP

#include <vector>
#include <optional>

#include "gui/components/Frame.hpp"
#include "gui/components/GraphicFunction.hpp"

class Graphic : public Frame
{
protected:
    std::vector<sf::VertexArray> axes;
    std::vector<std::shared_ptr<GraphicFunction>> functions;

    sf::Vector2f min_point;
    sf::Vector2f max_point;

    sf::Vector2f scale;
    sf::Vector2f origin;

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void calculateScale();
    void calculateCenter();

public:
    // Constructor
    Graphic(const sf::Vector2f &position, const sf::Vector2f &size,
            const sf::Color color, const sf::Vector2f &min_point, const sf::Vector2f &max_point);

    void drawAxes();

    void rescale(const sf::Vector2f &min_point, const sf::Vector2f &max_point);

    virtual std::shared_ptr<GraphicFunction> drawFunction(
        std::function<float(float)> function, const float &min, const float &max, const float &increment,
        const sf::CircleShape &circle, const std::optional<sf::VertexArray> line = std::nullopt);

    // Getters
    std::vector<std::shared_ptr<GraphicFunction>> getfuntions() const { return functions; }

    // Setters
    void setFunctions(const std::vector<std::shared_ptr<GraphicFunction>> &functions) { this->functions = functions; }
};

#endif // GRAPHIC_HPP