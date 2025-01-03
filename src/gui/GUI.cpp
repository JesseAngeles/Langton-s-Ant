#include "gui/GUI.hpp"

// Constructor
GUI::GUI(const std::shared_ptr<Space> &space)
    : space(space),
      MainWindow(1920, 1080, "Langton's Ant"),
      frame(Vector2f(0, 0), Vector2f(1920, 1080), Color::White),
      grid(this, space->getSpace().size(), space->getSpace()[0].size()),
      tb_rule(this, default_text),
      btn_start(this, default_text),
      btn_reset(this, default_text),
      btn_state(this, default_text),
      btn_ant(this, default_text),
      btn_colony(this, default_text)
{
    initDefaultText();
    rule_rize = space->getStates();

    tb_rule.setText(default_text);

    btn_start.setText(default_text);
    btn_start.setText("Start");

    btn_reset.setText(default_text);
    btn_reset.setText("Reset");

    btn_state.setText(default_text);
    btn_state.setText("Set state");

    btn_ant.setText(default_text);
    btn_ant.setText("Add ant");

    btn_colony.setText(default_text);
    btn_colony.setText("Add colony");

    frame.addChild(std::make_shared<Graphic>(graphic));
    frame.addChild(std::make_shared<Grid>(grid));
    frame.addChild(std::make_shared<TextBox>(tb_rule));
    frame.addChild(std::make_shared<Button>(btn_start));
    frame.addChild(std::make_shared<Button>(btn_reset));
    frame.addChild(std::make_shared<Button>(btn_ant));
    frame.addChild(std::make_shared<Button>(btn_state));
    frame.addChild(std::make_shared<Button>(btn_colony));

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
            if (elapsed_time >= 5.0f)
            {
                std::cout << "Han pasado 5 segundos." << std::endl;
                elapsed_time = 0.0f; // Reinicia el tiempo acumulado
            }
        }

        handleEvent();
        render();
    }
}