#ifndef CHASER_H
#define CHASER_H

#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class Chaser : public Enemy {
private:
    const Vector2f* playerPosition; // Pointer to the player's position

public:
    Chaser(const Texture& texture, const Vector2f& startPosition, float initialSpeed);

    void update(float deltaTime) override;

    void setTarget(const Vector2f& playerPos);
};

#endif // CHASER_H
