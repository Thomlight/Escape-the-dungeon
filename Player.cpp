#include "Player.hpp"

// Constructeur
Player::Player() {
    // Initialisation spécifique au joueur, si nécessaire
}

// Destructeur
Player::~Player() {
    // Nettoyage, si nécessaire
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

// Implémentation de la méthode update
void Player::update(float deltaTime) {
    // Exemple : Déplacement simple
    sprite.move(100 * deltaTime, 0); // Déplacement à droite
}

// Implémentation de la méthode draw
void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}
