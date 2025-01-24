#include "Key.hpp"
#include <iostream>


Key::Key(const Texture& texture, const Vector2f& startPosition, Player* playerPtr, bool isActive)
    : Item(texture, startPosition, playerPtr, isActive) {
}

Key::~Key() {}

void Key::update(float DeltaTime) {

}

void Key::interact(Player& player) {
    if (isActive && player.getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds())) {
        player.keyUp();
        cout << "Key activated" << endl;
        isActive = false;
    }
}

void Key::setIsActive() {
	isActive = true;
}   