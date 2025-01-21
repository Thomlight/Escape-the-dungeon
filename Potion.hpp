#ifndef POTION_H
#define POTION_H

#include "Item.hpp"

class Potion : public Item {
public:
    Potion(const Texture& texture, const Vector2f& startPosition, Player* playerPtr, bool isAcive);
    ~Potion();

    void update(float DeltaTime) override;
    void interact(Player& player) override;
};

#endif // POTION_H
