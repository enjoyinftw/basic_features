#pragma once
#include <SFML/Graphics.hpp>

namespace gp {
    class Game {
    public:
        Game();
        void start();

    private:
        sf::RenderWindow window;
        void processEvents();
        void update();
        void render();
    };
}