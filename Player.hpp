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

    // M�thodes h�rit�es de Entity
    void update(float deltaTime) override;
    void draw(RenderWindow& window) override;

private:
    // Ajout de variables sp�cifiques � Player, si n�cessaire
};

#endif // PLAYER_HPP
