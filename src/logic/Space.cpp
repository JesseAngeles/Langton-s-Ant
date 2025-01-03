#include "logic/Space.hpp"

// Constructor
Space::Space(int width, int height, int states, std::set<std::shared_ptr<Ant>> ants)
    : space(width, std::vector<Cell>(height, Cell(0))), states(states), ants(ants), randomizer()
{
    for (const std::shared_ptr<Ant> &ant : ants)
        this->space[ant->getPos().x][ant->getPos().y].ant = ant;
}

// Private functions

// Public functions
void Space::move()
{
    // Rotar todas las hormigas
    for (const std::shared_ptr<Ant> &ant : ants)
    {
        Position2D pos = ant->getPos();
        ant->rotate(space[pos.x][pos.y].state);
    }

    // Obtener todas las casillas que seran ocupadas
    std::map<Position2D, std::vector<std::shared_ptr<Ant>>> taken_cells;

    for (const std::shared_ptr<Ant> &ant : ants)
    {
        Position2D next_move = ant->getNextMove();

        auto it = taken_cells.find(next_move);
        if (it != taken_cells.end())
            it->second.push_back(ant);
        else
            taken_cells[next_move] = {ant};
    }

    // Buscar aquellas casillas que puede ser tomada por dos o mas, y seleccionar una al azar
    std::vector<std::shared_ptr<Ant>> movable_ants;
    for (std::pair<Position2D, std::vector<std::shared_ptr<Ant>>> cell : taken_cells)
        if (cell.second.size() == 1)
            movable_ants.push_back(cell.second[0]);
        else
            movable_ants.push_back(cell.second[std::round(randomizer.generate(0, cell.second.size()))]);

    // Eliminar referencia de ants
    for (const std::shared_ptr<Ant> &ant : movable_ants)
        space[ant->getPos().x][ant->getPos().y].ant = std::nullopt;

    // Mover movable_ants
    Position2D pos;
    for (const std::shared_ptr<Ant> &ant : movable_ants)
    {
        Position2D pos = ant->getPos();
        Position2D new_pos = ant->getNextMove();
        ant->setPos(new_pos);
        space[pos.x][pos.y].state = (space[pos.x][pos.y].state + 1) % states;
        space[new_pos.x][new_pos.y].ant = ant;
    }
}

bool Space::insertAnt(std::shared_ptr<Ant> &ant)
{
    Position2D pos = ant->getPos();
    if (!space[pos.x][pos.y].ant.has_value())
    {
        ants.insert(ant);
        space[pos.x][pos.y].ant = ant;

        return true;
    }

    return false;
}

void Space::removeAnt(Position2D pos)
{
    if (space[pos.x][pos.y].ant.has_value())
    {
        std::shared_ptr<Ant> ant = space[pos.x][pos.y].ant.value();
        space[pos.x][pos.y].ant = std::nullopt;

        ants.erase(ant);
    }
}

void Space::clear()
{
    for (std::vector<Cell> &line : space)
        for (Cell &cell : line)
        {
            cell.ant = std::nullopt;
            cell.state = 0;
        }
    
    ants.clear();
}

int Space::insertColony(Position2D center, float radius, int population, std::vector<Rule> rules, int colony)
{
    // Create N ants
    int i = 0, j = 0;
    int total_count = std::sqrt(8) * std::pow(radius, 2);
    Position2D current_space(space.size(), space[0].size());

    while (i < population || j++ < total_count)
    {
        int x_pos = randomizer.generate(center.x + radius, center.x - radius);
        int y_pos = randomizer.generate(center.y + radius, center.y - radius);
        int direction = randomizer.generate(0, 4);

        Direction new_direction;
        switch (direction)
        {
        case 0:
            new_direction = Direction::LEFT;
            break;
        case 1:
            new_direction = Direction::UP;
            break;
        case 2:
            new_direction = Direction::DOWN;
            break;
        case 3:
            new_direction = Direction::RIGHT;
            break;
        }

        std::shared_ptr<Ant> new_ant = std::make_shared<Ant>(Position2D(x_pos, y_pos), current_space, new_direction, rules, colony);

        if (insertAnt(new_ant))
            i++;
    }

    return i;
}

// Setters
void Space::setSpace(std::vector<std::vector<Cell>> &space)
{
    this->space = space;
    Position2D new_space(space.size(), space[0].size());
    for (const std::shared_ptr<Ant> &ant : ants)
        ant->setSpace(new_space);
}

// Displays
void Space::displaySpace()
{
    std::cout << std::endl;
    for (const std::vector<Cell> &line : space)
    {
        for (const Cell &cell : line)
            std::cout << cell.state << " ";
        std::cout << std::endl;
    }
}

void Space::displayAnts()
{
    std::vector<std::vector<Cell>> space_copy(space);

    std::cout << std::endl;
    for (const std::vector<Cell> &line : space_copy)
    {
        for (const Cell &cell : line)
            std::cout << (cell.ant.has_value() ? "1" : "0") << " ";
        std::cout << std::endl;
    }
}

void Space::display()
{
    std::vector<std::vector<Cell>> space_copy(space);
    for (const std::shared_ptr<Ant> &ant : ants)
        space_copy[ant->getPos().x][ant->getPos().y].state = states;

    std::cout << std::endl;
    for (const std::vector<Cell> &line : space_copy)
    {
        for (const Cell &cell : line)
            std::cout << cell.state << " ";
        std::cout << std::endl;
    }
}