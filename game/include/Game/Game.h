#pragma once
#include <SFML/Graphics.hpp>
#include "Game/Player.h"

namespace gp {
    class Game {
    public:
        Game();
        void run();

    private:
        sf::RenderWindow window;
        Player player;
        void processEvents();
        void update(const sf::Time& timePerFrame);
        void render();
    };
}