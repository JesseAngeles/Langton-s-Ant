#include "gui/BoardFrame.hpp"

// Constructor
BoardFrame::BoardFrame(int width, int height, Vector2f relative_pos, Color getBackgroundColor)
    : Frame(width, height, relative_pos, background_color)
{
}

void BoardFrame::draw(RenderWindow &window)
{
    Frame::draw(window);
}
