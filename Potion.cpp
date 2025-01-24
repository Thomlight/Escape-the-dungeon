#include "Potion.hpp"
#include "Player.hpp"
#include <iostream>

Potion::Potion(const Texture& texture, const Vector2f& startPosition, Player* playerPtr, bool isActive)
    : Item(texture, startPosition,  playerPtr, isActive) {
}

Potion::~Potion(){}

void Potion::update(float DeltaTime) {
    
}

void Potion::interact(Player& player) {
    if (isActive && player.getSprite().getGlobalBounds().intersects(this->getSprite().getGlobalBounds())) {
        player.speedUp();
        cout << "potion activated" << endl;
        isActive = false;
    }
}

void Potion::setActive() {
	isActive = true;
}   