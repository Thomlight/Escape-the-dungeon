#include "Entity.hpp"

Entity::Entity(const Texture& texture) {
    sprite.setTexture(texture);
}

const Sprite& Entity::getSprite() const {
    return sprite;
}

void Entity::setTexture(const Texture& texture) {
    sprite.setTexture(texture);
}

void Entity::draw(RenderWindow& window) const {
    window.draw(sprite);
}