#include "Game/Game.h"
#include "Game/Player.h"

namespace gp {
    Game::Game() :
        window{ sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Basic Features") } {
        window.setFramerateLimit(144);
    }
    void Game::run()
    {
        Player player{};

        while (window.isOpen())
        {
            processEvents();
            update();
            render();
            player.render(window);
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
 
        window.display();
        window.clear(sf::Color::Blue);//later swap this to before display

    }
}