#include "Player.hpp"

Player::Player(const Texture& texture, const Vector2f& startPosition, float initialSpeed)
    : Entity(texture), position(startPosition), speed(initialSpeed) {
    sprite.setPosition(position);
}

void Player::handleInput() {

    if (sf::Keyboard::isKeyPressed(Keyboard::Z)) {
        position.y = position.y - speed;
    }
    if (sf::Keyboard::isKeyPressed(Keyboard::S)) {
        position.y = position.y + speed;
    }
    if (sf::Keyboard::isKeyPressed(Keyboard::Q)) {
        position.x = position.x - speed;
    }
    if (sf::Keyboard::isKeyPressed(Keyboard::D)) {
        position.x = position.x + speed;
    }
}

void Player::update(float deltaTime) {
    position += velocity * deltaTime;
    sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

const sf::Vector2f& Player::getPosition() const {
    return position;
}

const sf::Vector2f& Player::getVelocity() const {
    return velocity;
}

void Player::setPosition(const Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

void Player::setVelocity(const Vector2f& newVelocity) {
    velocity = newVelocity;
}