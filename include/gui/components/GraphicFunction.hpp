#ifndef GRAPHIC_FUNCTION_HPP
#define GRAPHIC_FUNCTION_HPP

#include <vector>
#include <functional>

#include <SFML/Graphics.hpp>

class GraphicFunction
{
private:
    // Elements
    sf::Vector2f origin;
    sf::Vector2f scale;
    sf::Vector2f min_pos;
    sf::Vector2f max_pos;

    std::vector<sf::CircleShape> dots;
    std::vector<sf::VertexArray> lines;

    sf::CircleShape default_dot;
    sf::VertexArray default_line;

    bool has_dot;
    bool has_line;

    void calculatePosition(sf::Vector2f &position, const sf::Vector2f &scale, const sf::Vector2f &origin);

public:
    // Constructor
    GraphicFunction(const sf::Vector2f &position, const sf::Vector2f &size,
                    const sf::Vector2f &origin, const sf::Vector2f &scale);

    // Functions
    void addPoint(sf::Vector2f position, bool connect_last = true);
    void rescale(const sf::Vector2f &scale, const sf::Vector2f &origin);

    // Getters
    std::vector<sf::CircleShape> getDots() const { return dots; }
    std::vector<sf::VertexArray> getLines() const { return lines; }

    // Setters
    void setDefaultDot(const sf::CircleShape &default_dot);
    void setDefaultLine(const sf::VertexArray &default_line);
    void setDots(std::vector<sf::CircleShape> &dots) { this->dots = dots; }
    void setLines(std::vector<sf::VertexArray> &lines) { this->lines = lines; }
};

#endif // GRAPHIC_FUNCTION_HPP