#include "Player.hpp"

// Constructeur
Player::Player(Sprite playerSprite, float playerSpeed) {
    // Initialisation spécifique au joueur, si nécessaire
    sprite = playerSprite;
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
void Player::update(float deltaTime) {}

// Implémentation de la méthode draw
void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Player::handleInput() {
    // Vecteur pour accumuler le déplacement
    sf::Vector2f movement(0.f, 0.f);

    // Gestion des entrées clavier
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        movement.y -= playerSpeed; // Déplacement vers le haut
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += playerSpeed; // Déplacement vers le bas
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        movement.x -= playerSpeed; // Déplacement vers la gauche
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += playerSpeed; // Déplacement vers la droite
    }

    // Appliquer le déplacement au sprite du joueur
    sprite.move(movement);
}
