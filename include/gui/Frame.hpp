#ifndef FRAME_HPP
#define FRAME_HPP

#include <SFML/Graphics.hpp>

using namespace sf;

class Frame
{
protected:
    // Frame
    int width;
    int height;
    Vector2f relative_pos;
    Color background_color;
    RectangleShape frame;

public:
    // Constructor
    Frame(int width, int height, Vector2f relative_pos, Color background_color);

    // Drawers
    void draw(RenderWindow &window);

    // Getters
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Vector2i getSize() const { return Vector2i(width, height); }
    Vector2f getRelativePosition() const { return relative_pos; }
    Color getBackgroundColor() const { return background_color; }

    // Setters
    void setWidth(int width);
    void setHeight(int h);
    void setSize(int w, int h);
    void setRelativePosition(Vector2f pos);
    void setBackgroundColor(Color color);
};

#endif // FRAME_HPP