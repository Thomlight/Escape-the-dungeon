#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Main.hpp"
#include "Entity.hpp"

class Player : public Entity {
public:
    // Constructeur et destructeur
    Player();
    ~Player();

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

private:
    // Ajout de variables spécifiques à Player, si nécessaire
};

#endif // PLAYER_HPP
