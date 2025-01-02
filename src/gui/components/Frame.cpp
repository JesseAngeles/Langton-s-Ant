#include "gui/components/Frame.hpp"

// Constructor
Frame::Frame(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color)
    : position(position), size(size)
{
    background.setPosition(position);
    background.setSize(size);
    background.setFillColor(color);
}

// Protected functions
void Frame::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(background, states);
    for (const std::shared_ptr<Frame> &child : children)
        target.draw(*child, states);
}

// Public functions
void Frame::handleEvent(const sf::Event &event)
{
    for (const std::shared_ptr<Frame> &child : children)
        child->handleEvent(event);
}

void Frame::updatePosition(const sf::Vector2f &relative_position)
{
    position += relative_position;
    background.setPosition(position);
    for (const std::shared_ptr<Frame> &child : children)
        child->updatePosition(relative_position);
}

void Frame::addChild(const std::shared_ptr<Frame> &child)
{
    children.push_back(child);
    child->updatePosition(this->position);
}

// Settters
void Frame::setPosition(const sf::Vector2f &new_position)
{
    position = new_position;
    background.setPosition(position);
    for (const std::shared_ptr<Frame> &child : children)
        child->updatePosition(this->position);
}

void Frame::setSize(const sf::Vector2f &new_size)
{
    size = new_size;
    background.setSize(size);
}
