#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "Main.hpp"

class Entity {
private:
	Texture texture;
	Sprite sprite;
public:
	// Constructeur
	Entity() {
		// Chargement d'une texture par défaut (exemple)
		if (!texture.loadFromFile("default.png")) {
			throw std::runtime_error("Erreur lors du chargement de la texture par défaut");
		}
		sprite.setTexture(texture);
	}

	// Destructeur
	virtual ~Entity() {
		// Nettoyage si nécessaire
		// Par exemple, libérer des ressources ou réinitialiser des éléments
	}

	// Méthodes

	virtual void update(float deltaTime) = 0;

	virtual void draw(RenderWindow& window) = 0;
};

#endif // ENTITY_HPP
