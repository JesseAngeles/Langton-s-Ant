#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <string>
#include <vector>
#include <memory>

#include <SFML/Graphics.hpp>

#include "gui/components/Frame.hpp"

using namespace sf;

class MainWindow
{
private:
    RenderWindow window;
    Color background_color;

    // Frames
    std::vector<std::shared_ptr<Frame>> frames;

    void handleEvent();
    void render();

public:
    // Constructor
    MainWindow(int width, int height, const std::string &title, const Color &background_color = Color::Black);

    void addFrame(Frame frame) { frames.push_back(std::make_shared<Frame>(frame)); }

    // Drawer
    void run();
};

#endif // MAIN_WINDOW_HPP