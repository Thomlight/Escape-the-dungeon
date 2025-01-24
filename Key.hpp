#ifndef KEY_H
#define KEY_H

#include "Item.hpp"
#include "Player.hpp"

class Key : public Item {
public:
    Key(const Texture& texture, const Vector2f& startPosition, Player* playerPtr, bool isAcive);
    ~Key();

    void update(float DeltaTime) override;
    void interact(Player& player) override;
};

#endif // Key_H
