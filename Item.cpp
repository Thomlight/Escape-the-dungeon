#include "Item.hpp"

Item::Item(const Texture& texture, const Vector2f& startPosition, Player* playerPtr, bool isActive)
    : Entity(texture), position(startPosition), isActive(true), player(playerPtr) {
    sprite.setPosition(position);
}

void Item::draw(RenderWindow& window) const {
    if (isActive) { // Ne dessine que si l'objet est actif
        window.draw(sprite);
    }
}

const Vector2f& Item::getPosition() const {
    return position;
}

void Item::setPosition(const Vector2f& newPosition) {
    position = newPosition;
    sprite.setPosition(position);
}

bool Item::getIsActive() const {
    return isActive;
}

