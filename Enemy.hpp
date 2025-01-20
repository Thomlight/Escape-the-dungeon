#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Enemy : public Entity {
protected:
    Vector2f position; // Position actuelle de l'ennemi
    Vector2f velocity; // Vitesse actuelle de l'ennemi
    float speed; // Vitesse de déplacement

public:
    Enemy(const Texture& texture, const Vector2f& startPosition, float initialSpeed);

    void update(float deltaTime) override;

    void draw(RenderWindow& window) const override;

    const Vector2f& getVelocity() const;
    const Vector2f& getPosition() const;

    void setPosition(const Vector2f& newPosition);
    void setVelocity(const Vector2f& newVelocity);
};

#endif // ENEMY_H