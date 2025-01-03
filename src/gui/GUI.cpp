#include "gui/GUI.hpp"

// Constructor
GUI::GUI(const std::shared_ptr<Space> &space)
    : space(space),
      MainWindow(1920, 1080, "Langton's Ant"),
      frame(Vector2f(0, 0), Vector2f(1920, 1080), Color(245, 245, 245)),
      graphic(std::make_shared<MainGraphic>(this)),
      grid(std::make_shared<MainGrid>(this, space->getSpace().size(), space->getSpace()[0].size())),
      tb_rule(std::make_shared<TextBoxRule>(this, default_text)),
      btn_start(std::make_shared<ButtonStart>(this, default_text)),
      btn_step(std::make_shared<ButtonStep>(this, default_text)),
      btn_reset(std::make_shared<ButtonReset>(this, default_text)),
      btn_state(std::make_shared<ButtonState>(this, default_text)),
      btn_ant(std::make_shared<ButtonAnt>(this, default_text)),
      btn_colony(std::make_shared<ButtonColony>(this, default_text))
{
    initDefaultText();
    rule_size = space->getStates();

    tb_rule->setText(default_text);

    btn_start->setText(default_text);
    btn_start->setText("Start");

    btn_step->setText(default_text);
    btn_step->setText("Step");

    btn_reset->setText(default_text);
    btn_reset->setText("Reset");

    btn_state->setText(default_text);
    btn_state->setText("Set state");

    btn_ant->setText(default_text);
    btn_ant->setText("Add ant");

    btn_colony->setText(default_text);
    btn_colony->setText("Add colony");

    frame.addChild(graphic);
    frame.addChild(grid);
    frame.addChild(tb_rule);
    frame.addChild(btn_start);
    frame.addChild(btn_step);
    frame.addChild(btn_reset);
    frame.addChild(btn_ant);
    frame.addChild(btn_state);
    frame.addChild(btn_colony);

    addFrame(frame);
}

// Private functions
void GUI::initDefaultText()
{
    if (!font.loadFromFile("./resources/fonts/Roboto-Medium.ttf"))
    {
        throw std::runtime_error("No se pudo cargar la fuente.");
    }

    default_text.setFont(font);
    default_text.setFillColor(Color::Black);
    default_text.setCharacterSize(20);
    default_text.setString("Default Text");

    max_generation_text = default_text;
    max_generation_text.setPosition(1275, 7);
    max_generation_text.setString("Max: 0");

    generation_count_text = default_text;
    generation_count_text.setPosition(1275, 617);
    generation_count_text.setString("Generation: 0");
}

void GUI::render()
{
    window.clear(background_color);

    // Render frames
    for (const std::shared_ptr<Frame> &frame : frames)
        window.draw(*frame);

    window.draw(max_generation_text);
    window.draw(generation_count_text);

    window.display();
}

// Public functions
void GUI::run()
{
    Clock clock;
    float elapsed_time = 0.0f;

    while (window.isOpen())
    {
        float delta_time = clock.restart().asSeconds();
        if (is_running)
        {
            elapsed_time += delta_time;
            if (elapsed_time >= 0.0f)
            {
                move();
                elapsed_time = 0.0f; // Reinicia el tiempo acumulado
            }
        }

        handleEvent();
        render();
    }
}

void GUI::move()
{

    generation_count++;
    setGenerationCountText();

    space->move();
    std::vector<std::vector<Cell>> new_space = space->getSpace();
    for (int i = 0; i < new_space.size(); i++)
        for (int j = 0; j < new_space[i].size(); j++)
            if (new_space[i][j].ant.has_value())
                grid->setGridColor(i, j, Color::Red);
            else
            {
                grid->setGridColor(i, j, colors[new_space[i][j].state]);
                // if (new_space[i][j].state)
                //     grid->setGridColor(i,j, colors[0]);
                // else
                //     grid->setGridColor(i,j, colors[1]);
            }
    graphic->updateFunction();
}

void GUI::clear()
{
    if (isRunning())
        switchRunning();

    btn_start->setText("Start");

    space->clear();
    move();
    resetGenerationCount();

    graphic->clear();
}

void GUI::initColors()
{
    colors.clear();

    std::cout << "Size: " << rule_size << "\n";

    for (int i = 0; i < rule_size; i++)
        colors.push_back(generateRandomColor());

    graphic->setColors(colors);
}

sf::Color GUI::generateRandomColor()
{
    // Inicializar la semilla aleatoria (solo una vez en el programa)
    static bool initialized = false;
    if (!initialized)
    {
        srand(static_cast<unsigned>(time(nullptr)));
        initialized = true;
    }

    // Generar valores RGB aleatorios
    sf::Uint8 red = static_cast<sf::Uint8>(rand() % 256);
    sf::Uint8 green = static_cast<sf::Uint8>(rand() % 256);
    sf::Uint8 blue = static_cast<sf::Uint8>(rand() % 256);

    return sf::Color(red, green, blue);
}