#include "Enemy.hpp"

Enemy::Enemy(const Texture& texture, const Vector2f& startPosition, float initialSpeed)
    : Entity(texture), position(startPosition), speed(initialSpeed){
    sprite.setPosition(position);
}

void Enemy::update(float deltaTime) {
    position += velocity * deltaTime;
    sprite.setPosition(position);
}

void Enemy::draw(RenderWindow& window) const {
    window.draw(sprite);
}

const Vector2f& Enemy::getPosition() const {
    return position;
}

const Vector2f& Enemy::getVelocity() const {
    return velocity;
}

void Enemy::setPosition(const Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

void Enemy::setVelocity(const Vector2f& newVelocity) {
    velocity = newVelocity;
}

