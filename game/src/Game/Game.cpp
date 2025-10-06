#include "Game/Game.h"

namespace gp {
    Game::Game() :
        window{ sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Basic Features") } {
        window.setFramerateLimit(144);
    }
    void Game::run()
    {
        while (window.isOpen())
        {
            processEvents();
            update();
            render();
        }
    }

    void Game::processEvents()
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }
    }

    void Game::update()
    {
    }

    void Game::render() {
        window.clear(sf::Color::Blue);
        window.display();

    }
}