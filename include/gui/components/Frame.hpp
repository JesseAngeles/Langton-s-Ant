#ifndef FRAME_HPP
#define FRAME_HPP

#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

class Frame : public sf::Drawable
{
protected:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::RectangleShape background;
    std::vector<std::shared_ptr<Frame>> children;

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

public:
    // Constructor
    Frame(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color = sf::Color(0, 0, 0));

    // Functions
    virtual void handleEvent(const sf::Event &event);
    virtual void updatePosition(const sf::Vector2f &relative_position);
    void addChild(const std::shared_ptr<Frame> &child);

    // Settters
    void setPosition(const sf::Vector2f &new_position);
    void setSize(const sf::Vector2f &new_size);
};

#endif // FRAME_HPP