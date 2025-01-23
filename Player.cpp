#include "Player.hpp"
#include <iostream>

Player::Player(const sf::Texture& texture, const sf::Vector2f& startPosition, float initialSpeed)
    : position(startPosition), speed(initialSpeed) {
    sprite.setTexture(texture);
    sprite.setPosition(position);
}

void Player::handleInput(const Map& map) {
    sf::Vector2f newPosition = position;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        newPosition.y -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        newPosition.y += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        newPosition.x -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        newPosition.x += speed;
    }

    // Check for collision before updating the position
    if (!checkCollision(map, newPosition)) {
        position = newPosition;
    }
}

void Player::update(float deltaTime) {
    position += velocity * deltaTime;
    sprite.setPosition(position);
}

void Player::draw(sf::RenderWindow& window) const {
    window.draw(sprite);
}

sf::Sprite& Player::getSprite()  {
    return sprite;
}

const sf::Vector2f& Player::getPosition() {
    return position;
}

const sf::Vector2f& Player::getVelocity() const {
    return velocity;
}

void Player::setPosition(const sf::Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

void Player::setVelocity(const sf::Vector2f& newVelocity) {
    velocity = newVelocity;
}

void Player::speedUp() {
    speed += 5;
    std::cout << "player speed up" << std::endl;
}

void Player::keyUp() {
    nbKeys++;
    std::cout << "player got a key" << std::endl;
}

bool Player::checkCollision(const Map& map, const sf::Vector2f& newPosition) const {
    sf::FloatRect newBounds(newPosition, sprite.getGlobalBounds().getSize());
    return map.checkCollision(newBounds);
}