#pragma once
#include "SFML/Graphics.hpp"

namespace gp {
    class Player {
    public:
        Player();
        void render(sf::RenderWindow &window);
        void update(const sf::Time& timePerFrame);

        void setPosition(const sf::Vector2f& position);
        sf::Vector2f getPosition() const;

        const bool getTeleportCooldownStatus() const;
        void setTeleportCooldownStatus(bool value);
   

        void changeTeleportCooldownTime(sf::Time value);
        sf::Time getTeleportCooldownTime() const;
        void setTeleportCooldownTime(sf::Time value);
     

        const float getTeleportDistance() const;
        void setTeleportDistance(float value);


        int useTeleportSkill();

    private:
        sf::Vector2f processInputs();

        float player_speed;
        sf::Texture player_texture;
        sf::Sprite player_sprite;
        sf::Vector2f player_position;
        bool isTeleportOnCooldown;
        sf::Time teleportCooldownTime;
        float player_teleport_distance;
    };
}