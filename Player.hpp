#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>
#include "Map.hpp"

class Player {
public:
    Player(const sf::Texture& texture, const sf::Vector2f& startPosition, float initialSpeed);

    // Method to handle player input
    void handleInput(const Map& map);

    // Method to update player position and check collisions
    void update(float deltaTime);

    // Method to draw the player on the window
    void draw(sf::RenderWindow& window) const;

    // Getter for the player sprite
    sf::Sprite& getSprite();

    // Getter for the player position
    const sf::Vector2f& getPosition();

    // Getter for the player velocity
    const sf::Vector2f& getVelocity() const;

    int getKey();

    // Setter for the player position
    void setPosition(const sf::Vector2f& newPosition);

    // Setter for the player velocity
    void setVelocity(const sf::Vector2f& newVelocity);

    // Method to speed up the player
    void speedUp();

    // Method to increase the number of keys the player has
    void keyUp();

    // Check if the player has a key
    bool hasKey() const;

    // Consume a key
    void useKey();

private:
    sf::Sprite sprite;
    sf::Vector2f position;
    sf::Vector2f velocity;
    float speed;
    int nbKeys = 0;

    // Method to check collision with the map
    bool checkCollision(const Map& map, const sf::Vector2f& newPosition) const;
};

#endif // PLAYER_HPP