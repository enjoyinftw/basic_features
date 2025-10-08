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

        sf::Clock clock;
        sf::Time timeSinceLastUpdate = sf::Time::Zero;
        const auto timePerFrame = sf::seconds(1.f / 60.f);
        while (window.isOpen())
        {
            
            timeSinceLastUpdate += clock.restart();
            while (timeSinceLastUpdate > timePerFrame) {
                timeSinceLastUpdate -= timePerFrame;
                processEvents();
                update(timePerFrame);
            }
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

    void Game::update(const sf::Time& timePerFrame)
    {
    }

    void Game::render() {
 
        window.display();
        window.clear(sf::Color::Blue);//later swap this to before display

    }
}