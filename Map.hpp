#ifndef MAP_HPP
#define MAP_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

class Map {
public:
    // Constructor that loads a map from a file
    Map(const std::string& filename, const std::string& wallTextureFile, const std::string& doorTextureFile);

    // Method to draw the map on the window
    void draw(sf::RenderWindow& window) const;

    // Method to check collision with the walls and doors
    bool checkCollision(const sf::Sprite& sprite) const;

private:
    // Vector to store the tiles of the map
    std::vector<sf::RectangleShape> tiles;

    // Textures for the tiles
    sf::Texture wallTexture;
    sf::Texture doorTexture;

    // Method to load the map from a file
    bool loadMapFromFile(const std::string& filename);
};

#endif // MAP_HPP