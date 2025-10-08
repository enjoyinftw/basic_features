#pragma once
#include <SFML/Graphics.hpp>

namespace gp {
    class Game {
    public:
        Game();
        void run();

    private:
        sf::RenderWindow window;
        void processEvents();
        void update(const sf::Time& timePerFrame);
        void render();
    };
}