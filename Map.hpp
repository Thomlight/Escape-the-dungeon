#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Map {
public:
    // Constructor that loads a map from a file and textures for walls, doors, and tiles
    Map(const std::string& filename, const std::string& wallTextureFile, const std::string& doorTextureFile, const std::string& tileTextureFile);

    // Method to draw the map on the window
    void draw(sf::RenderWindow& window) const;

    // Method to check collision with the walls and doors
    bool checkCollision(const sf::FloatRect& bounds) const;

    // Method to check collision specifically with doors
    bool checkDoorCollision(const sf::FloatRect& bounds) const;

    // Method to remove a door tile
    void removeDoor(const sf::FloatRect& bounds);

private:
    // Vector to store the tiles of the map
    std::vector<sf::RectangleShape> tiles;
    std::vector<sf::RectangleShape> doorTiles;

    // Textures for the tiles
    sf::Texture wallTexture;
    sf::Texture doorTexture;
    sf::Texture tileTexture; // New texture for regular tiles

    // Method to load the map from a file
    bool loadMapFromFile(const std::string& filename);
};

#endif // MAP_HPP