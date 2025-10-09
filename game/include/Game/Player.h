#pragma once
#include "SFML/Graphics.hpp"

namespace gp {
    class Player {
    public:
        Player();
        void render(sf::RenderWindow &window);
        void setPosition(const sf::Vector2f& position);
        void update(const sf::Time& timePerFrame);
        sf::Vector2f getPosition() const;


    private:
        sf::Vector2f processInputs() const;

        float player_speed;
        sf::Texture player_texture;
        sf::Sprite player_sprite;
        sf::Vector2f player_position;
    };
}