#include "gui/MainGraphic.hpp"

#include "gui/GUI.hpp"

void MainGraphic::updateFunction()
{
    for (int i = 0; i < functions.size(); i += 2)
    {
        int count = 0;
        std::vector<std::vector<Cell>> space = gui->space->getSpace();

        for (const std::vector<Cell> &line : space)
            for (const Cell &cell : line)
            {
                if (cell.state == i / 2)
                    count++;
            }

        if (count > max)
        {
            max = count;
            gui->setMaxGenerationText(max);
        }

        int x = gui->getGenerationCount();
        this->rescale(sf::Vector2f(0, 0), sf::Vector2f(x, max));
        functions[i]->addPoint(Vector2f(x, count), false);

        functions[i + 1]->addPoint(Vector2f(x, log2(count)), false);
    }
}

void MainGraphic::clear()
{
    std::vector<sf::CircleShape> dots;
    std::vector<sf::VertexArray> lines;

    for (const std::shared_ptr<GraphicFunction> &function : functions)
        function->clear();

    max = 3;
}