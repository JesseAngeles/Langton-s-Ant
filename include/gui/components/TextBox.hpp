#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include <functional>

#include "gui/components/Frame.hpp"

class TextBox : public Frame
{
protected:
    // Attributes
    sf::Text text;
    std::string input_string;
    size_t char_limit;
    bool is_active;
    std::function<void(const std::string &)> onEnter;

    virtual void updateTextPosition();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void handleEvent(const sf::Event &event) override;

public:
    // Constructor
    TextBox(const sf::Vector2f &position, const sf::Vector2f &size, const sf::Color &color,
            const sf::Text &text, const std::string &input_string, size_t char_limit = 20);

    // Setters
    void setOnEnter(std::function<void(const std::string &)> callback) { onEnter = callback; }
    void setString(const std::string &input_string);
};

#endif // TEXT_BOX_HPP