#ifndef BOARD_FRAME_HPP
#define BOARD_FRAME_HPP

#include "gui/Frame.hpp"

class BoardFrame : public Frame
{
private:
public:
    // Constructor
    BoardFrame(int width, int height, Vector2f relative_pos, Color getBackgroundColor);

    void draw(RenderWindow &window);
};

#endif // BOARD_FRAME_HPP