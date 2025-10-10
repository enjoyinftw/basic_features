#include "Game/Player.h"
#include "config.h"
#include <string>
#include <stdexcept>

namespace gp {
    Player::Player()
        : player_speed {100}, 
        player_position{},
        player_texture{},
        player_sprite{player_texture},
        isTeleportOnCooldown{false},
        teleportCooldownTime{sf::Time::Zero},
        player_teleport_distance{25.f}
    {
        std::string texture_path = (GetResourceDir() + "player.png");
        if (!player_texture.loadFromFile(texture_path)) {
            throw std::runtime_error("Failed to load texture!");
        }
        player_sprite.setTexture(player_texture, true);
    };

    void Player::update(const sf::Time& timePerFrame) {
        changeTeleportCooldownTime(-timePerFrame);
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

    sf::Vector2f Player::processInputs() 
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
            if (!getTeleportCooldownStatus()) {
                int teleport_distance = useTeleportSkill();
                positionChange.x *= teleport_distance;
                positionChange.y *= teleport_distance;
            }
        }
        return positionChange;
    }

    void Player::setTeleportCooldownStatus(bool value) {
        isTeleportOnCooldown = value;
    }

    const bool Player::getTeleportCooldownStatus() const {
        return isTeleportOnCooldown;
    }

    void Player::changeTeleportCooldownTime(sf::Time value) {
        teleportCooldownTime += value;
        if (teleportCooldownTime <= sf::Time::Zero) {
            setTeleportCooldownTime(sf::Time::Zero);
            setTeleportCooldownStatus(false);
        }
    }

    void Player::setTeleportCooldownTime(sf::Time value) {
        teleportCooldownTime = value;
    }

    sf::Time Player::getTeleportCooldownTime() const {
        return teleportCooldownTime;
    }

    void Player::setTeleportDistance(float value) {
        player_teleport_distance = value;
    }

    const float Player::getTeleportDistance() const {
        return player_teleport_distance;
    }

    int Player::useTeleportSkill() {
        setTeleportCooldownStatus(true);
        setTeleportCooldownTime(sf::seconds(6.f));
        return player_teleport_distance;
    }

}
