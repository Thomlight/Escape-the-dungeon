#ifndef ITEM_H
#define ITEM_H

#include "Entity.hpp"
#include "Player.hpp"

class Item : public Entity {
protected:
	Vector2f position; // Position actuelle de l'objet
    bool isActive = false;
    Player* player;
public:
    Item(const Texture& texture, const Vector2f& startPosition, Player* player, bool isActive);

    void draw(RenderWindow& window) const override;
    virtual void update(float DeltaTime) = 0;
    const Vector2f& getPosition() const;
    void setPosition(const Vector2f& newPosition);
    bool getIsActive() const; // Vérifie si l'objet est actif
    virtual void interact(Player& player) = 0;
};

#endif // ITEM_H