#pragma once
#include "SFML/Graphics.hpp"

namespace gp {
    class Player {
    public:
        Player();
        void render(sf::RenderWindow &window);
       

    private:
        sf::Texture player_texture;
        sf::Sprite player_sprite;
        sf::Vector2f player_position;
    };
}