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
		// Chargement d'une texture par d�faut (exemple)
		if (!texture.loadFromFile("default.png")) {
			throw std::runtime_error("Erreur lors du chargement de la texture par d�faut");
		}
		sprite.setTexture(texture);
	}

	// Destructeur
	virtual ~Entity() {
		// Nettoyage si n�cessaire
		// Par exemple, lib�rer des ressources ou r�initialiser des �l�ments
	}

	// M�thodes

	virtual void update(float deltaTime) = 0;

	virtual void draw(RenderWindow& window) = 0;
};

#endif // ENTITY_HPP
