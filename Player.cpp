#include "Player.hpp"

// Constructeur
Player::Player(Sprite playerSprite, float playerSpeed) {
    // Initialisation sp�cifique au joueur, si n�cessaire
    sprite = playerSprite;
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
void Player::update(float deltaTime) {}

// Impl�mentation de la m�thode draw
void Player::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Player::handleInput() {
    // Vecteur pour accumuler le d�placement
    sf::Vector2f movement(0.f, 0.f);

    // Gestion des entr�es clavier
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        movement.y -= playerSpeed; // D�placement vers le haut
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        movement.y += playerSpeed; // D�placement vers le bas
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        movement.x -= playerSpeed; // D�placement vers la gauche
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        movement.x += playerSpeed; // D�placement vers la droite
    }

    // Appliquer le d�placement au sprite du joueur
    sprite.move(movement);
}
