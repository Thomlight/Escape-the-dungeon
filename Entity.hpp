#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;
const int Width = 1440;
const int Height = 1080;
class Entity {
protected:
    Sprite sprite; // Rendu accessible aux classes dérivées
public:
    Entity(const Texture& texture);

    const Sprite& getSprite() const; // Doit retourner une référence constante

    void setTexture(const sf::Texture& texture);

    virtual void update(float deltaTime) = 0;
    virtual void draw(RenderWindow& window) const = 0;

    virtual ~Entity() = default; // Destructeur virtuel
};

#endif // ENTITY_H