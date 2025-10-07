#pragma once
#include "SFML/Graphics.hpp"

namespace gp {
    class Player {
    public:
        Player();
        void render(sf::RenderWindow &window);
        void setPosition(const sf::Vector2f& position);
        const sf::Vector2f getPosition() const;

    private:
        sf::Texture player_texture;
        sf::Sprite player_sprite;
        sf::Vector2f player_position;
    };
}