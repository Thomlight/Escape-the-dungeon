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

sf::Sprite& Player::getSprite() {
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
    speed += 2;
    std::cout << "Player speed up" << std::endl;
}

void Player::keyUp() {
    nbKeys++;
    std::cout << "Player got a key" << std::endl;
}

bool Player::hasKey() const {
    return nbKeys > 0;
}

void Player::useKey() {
    if (nbKeys > 0) {
        nbKeys--;
        std::cout << "Player used a key" << std::endl;
    }
}

bool Player::checkCollision(const Map& map, const sf::Vector2f& newPosition) const {
    sf::FloatRect newBounds(newPosition, sprite.getGlobalBounds().getSize());
    return map.checkCollision(newBounds);
}

void Player::handleDoorInteraction(Map& map) {
    std::cout << "Checking door interaction..." << std::endl;
    sf::FloatRect playerBounds = sprite.getGlobalBounds();
    if (map.checkDoorCollision(playerBounds)) {
        std::cout << "Player collided with a door." << std::endl;
        if (hasKey()) {
            std::cout << "Player has a key." << std::endl;
            useKey();
            map.removeDoor(playerBounds);
            std::cout << "Door opened at (" << playerBounds.left << ", " << playerBounds.top << ")" << std::endl;
        } else {
            std::cout << "Player does not have a key." << std::endl;
        }
    }
}

void Player::setSpeed(float newSpeed) {
	speed = newSpeed;
}   