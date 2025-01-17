#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SFML/Graphics.hpp"
using namespace std;
using namespace sf;

class Entity {
public:

	Texture texture;
	Sprite sprite;	

	// Méthodes

	virtual void update(float deltaTime) = 0;

	virtual void draw(RenderWindow& window) = 0;
};

#endif // ENTITY_HPP
