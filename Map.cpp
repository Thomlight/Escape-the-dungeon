#include "Map.hpp"
#include <fstream>
#include <iostream>

// Constructor that loads a map from a file and textures for walls and doors
Map::Map(const std::string& filename, const std::string& wallTextureFile, const std::string& doorTextureFile) {
    if (!wallTexture.loadFromFile(wallTextureFile)) {
        std::cerr << "Failed to load wall texture from file." << std::endl;
    }
    else {
        std::cout << "Wall texture loaded successfully." << std::endl;
    }

    if (!doorTexture.loadFromFile(doorTextureFile)) {
        std::cerr << "Failed to load door texture from file." << std::endl;
    }
    else {
        std::cout << "Door texture loaded successfully." << std::endl;
    }

    if (!loadMapFromFile(filename)) {
        std::cerr << "Failed to load map from file." << std::endl;
    }
    else {
        std::cout << "Map loaded successfully from file." << std::endl;
    }
}

// Method to draw the map on the window
void Map::draw(sf::RenderWindow& window) const {
    for (const auto& tile : tiles) {
        window.draw(tile);
    }
}

// Method to check collision with the walls and doors
bool Map::checkCollision(const sf::Sprite& sprite) const {
    // Get the bounding box of the sprite
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();

    // Check if the sprite's bounding box intersects with any tile's bounding box
    for (const auto& tile : tiles) {
        if (tile.getGlobalBounds().intersects(spriteBounds)) {
            return true;
        }
    }
    return false;
}

// Method to load the map from a file
bool Map::loadMapFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open map file." << std::endl;
        return false;
    }
    else {
        std::cout << "Map file opened successfully." << std::endl;
    }

    std::string line;
    int y = 0;
    while (std::getline(file, line)) {
        for (int x = 0; x < line.size(); ++x) {
            sf::RectangleShape tile(sf::Vector2f(32, 32)); // Size of a tile
            tile.setPosition(x * 32, y * 32);

            if (line[x] == 'W') {
                tile.setTexture(&wallTexture); // Apply the wall texture to the tile
                tiles.push_back(tile);
                std::cout << "Wall tile added at (" << x << ", " << y << ")." << std::endl;
            }
            else if (line[x] == 'D') {
                tile.setTexture(&doorTexture); // Apply the door texture to the tile
                tiles.push_back(tile);
                std::cout << "Door tile added at (" << x << ", " << y << ")." << std::endl;
            }
            else if (line[x] == '#') {
                std::cout << "Empty tile at (" << x << ", " << y << ")." << std::endl;
            }
        }
        ++y;
    }

    return true;
}