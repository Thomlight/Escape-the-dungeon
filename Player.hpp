#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class Player : public Entity {
private:
    Vector2f position; // Position actuelle du joueur
    Vector2f velocity; // Vitesse actuelle du joueur
    float speed; // Vitesse de déplacement

public:
    Player(const Texture& texture, const Vector2f& startPosition, float initialSpeed);


    void update(float deltaTime) override;


    void draw(RenderWindow& window) const override;

    const Vector2f& getVelocity() const;
    const Vector2f& getPosition();

    void setPosition(const Vector2f& newPosition);
    void setVelocity(const Vector2f& newVelocity);

    void handleInput();
};

#endif // PLAYER_H