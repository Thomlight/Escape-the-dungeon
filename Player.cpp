#include "Player.hpp"

// Constructeur
Player::Player() {
    // Initialisation sp�cifique au joueur, si n�cessaire
}

// Destructeur
Player::~Player() {
    // Nettoyage, si n�cessaire
}

// Getters
float Player::getX() const {
    return sprite.getPosition().x;
}

float Player::getY() const {
    return sprite.getPosition().y;
}

Vector2f Player::getPosition() const {
    return sprite.getPosition();
}

// Setters
void Player::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

void Player::setPosition(const Vector2f& position) {
    sprite.setPosition(position);
}

// Impl�mentation de la m�thode update
void Player::update(float deltaTime) {
    // Exemple : D�placement simple
    sprite.move(100 * deltaTime, 0); // D�placement � droite
}

// Impl�mentation de la m�thode draw
void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}
