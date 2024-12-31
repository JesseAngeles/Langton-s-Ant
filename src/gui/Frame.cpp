#include "gui/Frame.hpp"

// Constructor
Frame::Frame(int width, int height, Vector2f relative_pos, Color background_color)
    : width(width), height(height), relative_pos(relative_pos), background_color(background_color)
{
    frame = RectangleShape(Vector2f(width, height));
    frame.setPosition(relative_pos);
    frame.setFillColor(background_color);
}

// Draw method
void Frame::draw(RenderWindow &window)
{
    window.draw(frame);
}

// Setters
void Frame::setWidth(int w)
{
    width = w;
    frame.setSize(Vector2f(width, height));
}

void Frame::setHeight(int h)
{
    height = h;
    frame.setSize(Vector2f(width, height));
}

void Frame::setSize(int w, int h)
{
    width = w;
    height = h;
    frame.setSize(Vector2f(width, height));
}

void Frame::setRelativePosition(Vector2f pos)
{
    relative_pos = pos;
    frame.setPosition(relative_pos);
}

void Frame::setBackgroundColor(Color color)
{
    background_color = color;
    frame.setFillColor(color);
}
