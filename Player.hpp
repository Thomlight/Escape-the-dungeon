#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map.hpp"
using namespace sf;
using namespace std;

class Player {
public:
    Player(const sf::Texture& texture, const sf::Vector2f& startPosition, float initialSpeed);

    void handleInput(const Map& map);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window) const;
    sf::Sprite& getSprite();
    const sf::Vector2f& getPosition();
    const sf::Vector2f& getVelocity() const;
    void setPosition(const sf::Vector2f& newPosition);
    void setVelocity(const sf::Vector2f& newVelocity);
	void setSpeed(float newSpeed);  
    void speedUp();
    void keyUp();
    bool hasKey() const;
    void useKey();
    bool checkCollision(const Map& map, const sf::Vector2f& newPosition) const;
    void handleDoorInteraction(Map& map);  // New method to handle door interaction

private:
    sf::Vector2f position;
    sf::Vector2f velocity;
    float speed;
    sf::Sprite sprite;
    int nbKeys = 0;  // Number of keys the player has
};

#endif // PLAYER_HPP