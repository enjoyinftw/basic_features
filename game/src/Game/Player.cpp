#include "Game/Player.h"
#include "config.h"
#include <string>
#include <stdexcept>

namespace gp {
    Player::Player()
        : player_position{},
        player_texture{},
        player_sprite{player_texture}
    {
        std::string texture_path = (GetResourceDir() + "player.png");
        if (!player_texture.loadFromFile(texture_path)) {
            throw std::runtime_error("Failed to load texture!");
        }
        player_sprite.setTexture(player_texture, true);
    };

    void Player::render(sf::RenderWindow &window)
    {
        window.draw(player_sprite);
    }

    void Player::setPosition(const sf::Vector2f& position)
    {
        player_sprite.setPosition(position);
    }

    const sf::Vector2f Player::getPosition() const
    {

        return player_sprite.getPosition();
    }
}
