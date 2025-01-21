// Player.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.hpp"

using namespace sf;

class Player : public Entity {
    private:
    Vector2f position;
    Vector2f velocity;
    float speed;
    int nbKeys = 0; // Ajout d'une variable pour suivre le nombre de clés
public:
    Player(const Texture& texture, const Vector2f& startPosition, float initialSpeed);

    void handleInput();
    void update(float deltaTime);
    void draw(RenderWindow& window) const;

    const Vector2f& getPosition();
    const Vector2f& getVelocity() const;
    void setPosition(const Vector2f& newPosition);
    void setVelocity(const Vector2f& newVelocity);

    void speedUp();
    void keyUp();
};
