#include "Entity.hpp"
#include <stdexcept>

// Constructeur
Entity::Entity() {
    if (!texture.loadFromFile("default.png")) {
        throw std::runtime_error("Erreur lors du chargement de la texture par défaut");
    }
    sprite.setTexture(texture);
}

// Destructeur
Entity::~Entity() {}
