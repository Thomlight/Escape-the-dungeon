#include "Map.hpp"
#include <fstream>
#include <iostream>

// Constructor that loads a map from a file and textures for walls, doors, and tiles
Map::Map(const std::string& filename, const std::string& wallTextureFile, const std::string& doorTextureFile, const std::string& tileTextureFile) {
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

    if (!tileTexture.loadFromFile(tileTextureFile)) {
        std::cerr << "Failed to load tile texture from file." << std::endl;
    }
    else {
        std::cout << "Tile texture loaded successfully." << std::endl;
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
bool Map::checkCollision(const sf::FloatRect& bounds) const {
    for (const auto& tile : tiles) {
        if (tile.getGlobalBounds().intersects(bounds)) {
            std::cout << "collide"; 
            return true;
        }
    }
    return false;
}

// Method to check collision specifically with doors
bool Map::checkDoorCollision(const sf::FloatRect& bounds) const {
    std::cout << "Checking door collisions..." << std::endl; // Debug statement
    for (const auto& doorTile : doorTiles) {
        if (doorTile.getGlobalBounds().intersects(bounds)) {
            std::cout << "Collision with door at (" << doorTile.getPosition().x << ", " << doorTile.getPosition().y << ")" << std::endl; // Debug statement
            return true;
        }
    }
    return false;
}

// Method to remove a door tile
void Map::removeDoor(const sf::FloatRect& bounds) {
    for (auto it = doorTiles.begin(); it != doorTiles.end(); ++it) {
        if (it->getGlobalBounds().intersects(bounds)) {
            std::cout << "Door removed at (" << it->getPosition().x << ", " << it->getPosition().y << ")" << std::endl;
            doorTiles.erase(it);
            break;
        }
    }
    // Also remove from the main tiles vector
    tiles.erase(std::remove_if(tiles.begin(), tiles.end(),
        [&bounds](const sf::RectangleShape& tile) {
            return tile.getGlobalBounds().intersects(bounds);
        }),
        tiles.end());
}

// Method to load the map from a file
bool Map::loadMapFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Failed to open map file: " << filename << std::endl;
        return false;
    }
    else {
        std::cout << "Map file opened successfully: " << filename << std::endl;
    }

    std::string line;
    int y = 0;
    while (std::getline(file, line)) {
        std::cout << "Reading line: " << line << std::endl; // Debug statement
        for (int x = 0; x < line.size(); ++x) {
            sf::RectangleShape tile(sf::Vector2f(64, 64)); // Size of a tile
            tile.setPosition(x * 64, y * 64);

            if (line[x] == 'W') {
                tile.setTexture(&wallTexture); // Apply the wall texture to the tile
                tiles.push_back(tile);
                std::cout << "Wall tile added at (" << x * 64 << ", " << y * 64 << ")." << std::endl;
            }
            else if (line[x] == 'D') {
                tile.setTexture(&doorTexture); // Apply the door texture to the tile
                doorTiles.push_back(tile);
                tiles.push_back(tile); // Add to main tiles as well for drawing
                std::cout << "Door tile added at (" << x * 64 << ", " << y * 64 << ")." << std::endl;
            }
            else if (line[x] == '#') {
                tile.setTexture(&tileTexture); // Apply the tile texture to the tile
                tiles.push_back(tile); // Add empty tile to the vector
                std::cout << "Empty tile added at (" << x * 64 << ", " << y * 64 << ")." << std::endl;
            }
        }
        ++y;
    }

    return true;
}