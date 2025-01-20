#ifndef CHASER_H
#define CHASER_H

#include "Enemy.hpp"
#include <SFML/Graphics.hpp>

class Chaser : public Enemy {
private:
    const sf::Vector2f* playerPosition; // Pointer to the player's position

public:
    Chaser(const sf::Texture& texture, const sf::Vector2f& startPosition, float initialSpeed);

    void update(float deltaTime) override;

    void setTarget(const sf::Vector2f& playerPos);
};

#endif // CHASER_H
