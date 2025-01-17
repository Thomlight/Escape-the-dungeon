#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Entity.hpp"

class Player : public Entity {
private:
    float playerSpeed;

public:
    // Constructeur et destructeur
    Player(Sprite playerSprite, float playerSpeed);
    virtual ~Player();

    // Getters pour la position du sprite
    float getX() const;
    float getY() const;
    Vector2f getPosition() const;

    // Setters pour la position du sprite
    void setPosition(float x, float y);
    void setPosition(const Vector2f& position);

    // Méthodes héritées de Entity
    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;

    void handleInput();
};
#endif // PLAYER_HPP