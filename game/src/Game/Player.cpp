#include "Game/Player.h"
#include "config.h"
#include <string>
#include <stdexcept>

namespace gp {
    Player::Player()
        : player_speed {100}, 
        player_position{},
        player_texture{},
        player_sprite{player_texture}
    {
        std::string texture_path = (GetResourceDir() + "player.png");
        if (!player_texture.loadFromFile(texture_path)) {
            throw std::runtime_error("Failed to load texture!");
        }
        player_sprite.setTexture(player_texture, true);
    };

    void Player::update(const sf::Time& timePerFrame) {
        auto newPositionChange = processInputs();
        auto currentPosition = getPosition();
        currentPosition += newPositionChange * timePerFrame.asSeconds() * player_speed;
        setPosition(currentPosition);
        
    }

    void Player::render(sf::RenderWindow &window)
    {
        window.draw(player_sprite);
    }

    void Player::setPosition(const sf::Vector2f& position)
    {
        player_sprite.setPosition(position);
    }

    sf::Vector2f Player::getPosition() const
    {

        return player_sprite.getPosition();
    }

    sf::Vector2f Player::processInputs() const
    {
        sf::Vector2f positionChange{};
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            positionChange.x -= 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
            positionChange.y -= 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
            positionChange.x += 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) ||
            sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
            positionChange.y += 1;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) {
            positionChange.x *= 25;
            positionChange.y *= 25;
        }
        return positionChange;
    }


}
