#include "gui/MainWindow.hpp"

// Constructor
MainWindow::MainWindow(int width, int height, std::string tittle, Color backgroundColor)
    : width(width), height(height), tittle(tittle), backgroundColor(backgroundColor),
      window(VideoMode(width, height), tittle, Style::Close),
      board_frame(200, 200, Vector2f(30, 30), Color(100, 100, 255))
{
}

void MainWindow::mainLoop()
{
    Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            // Manejar el clic del botón
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mouse_pos(event.mouseButton.x, event.mouseButton.y);

                // Click en cuadricula
            }

            window.clear(backgroundColor);

            // Dibujar elementos estaticos

            // Frames
            board_frame.draw(window);

            // Text

            // Buttons

            window.display();
        }
    }
}