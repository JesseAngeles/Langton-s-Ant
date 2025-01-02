#include "gui/MainWindow.hpp"

// Constructor
MainWindow::MainWindow(int width, int height, const std::string &title, const Color &background_color)
    : window(VideoMode(width, height), title), background_color(background_color) {}

// Private functions
void MainWindow::handleEvent()
{
    Event event;
    while (window.pollEvent(event))
    {
        if(event.type == Event::Closed)
            window.close();

        // Frame events
        for (std::shared_ptr<Frame> &frame : frames)
            frame->handleEvent(event);
    }
    
}

void MainWindow::render()
{
    window.clear(background_color);

    // Render frames
    for (const std::shared_ptr<Frame> &frame : frames)
        window.draw(*frame);

    window.display();
}

// Public functions
void MainWindow::run()
{
    while (window.isOpen())
    {
        handleEvent();
        render();
    }
}