#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <functional>

#include "gui/components/Frame.hpp"

class Button : public Frame
{
protected:
    sf::Text text;
    std::function<void()> onClick;

    virtual void updateTextPosition();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void handleEvent(const sf::Event &event) override;
    void updatePosition(const sf::Vector2f &relative_position) override;

public:
    Button(const sf::Vector2f &position, const sf::Vector2f &size,
           const sf::Color &color, const sf::Text &text);

    // Setters
    void setOnClick(std::function<void()> callback) { onClick = callback; }
    void setText(const std::string &text_content);
};

#endif // BUTTON_HPP