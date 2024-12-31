#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <string>

#include <SFML/Graphics.hpp>

#include "gui/BoardFrame.hpp"

#define FONT_ROUTE "./resources/fonts/Roboto-Medium.ttf"

using namespace sf;

class MainWindow
{
private:
    // MainWindow attributes
    int width;
    int height;
    Color backgroundColor;
    std::string tittle;
    Font font;
    std::string font_route = FONT_ROUTE;
    
    // Frames
    BoardFrame board_frame;

    // Lines

    // Text

    // Buttons

    // Functions

public:
    // Constructor
    MainWindow(int width, int height, std::string tittle, Color backgroundColor);

    RenderWindow window;

    // Functions
    void mainLoop();

    // Drawers
};



#endif // MAIN_WINDOW_HPP