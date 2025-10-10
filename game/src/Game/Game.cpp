#include "Game/Game.h"


namespace gp {
    Game::Game() :
        window{ sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Basic Features") },
        player{} {
        window.setFramerateLimit(144);
    }
    void Game::run()
    {
        sf::Clock clock{};
        sf::Time timeSinceLastUpdate{ sf::Time::Zero };
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
        player.update(timePerFrame);
    }

    void Game::render() {
 
        window.clear(sf::Color::Blue);
        player.render(window);
        window.display();
       

    }

}