#ifndef PATROLLER_H
#define PATROLLER_H

#include "Enemy.hpp"
#include <vector>

class Patroller : public Enemy {
private:
    std::vector<sf::Vector2f> waypoints; // List of waypoints for the patroller to follow
    size_t currentWaypointIndex;         // Current waypoint index
    bool reverse;                        // Direction of movement (true: backward, false: forward)

public:
    Patroller(const sf::Texture& texture, const sf::Vector2f& startPosition, float speed, const std::vector<sf::Vector2f>& waypoints);

    void update(float deltaTime) override;

    void setWaypoints(const std::vector<sf::Vector2f>& newWaypoints);
    const std::vector<sf::Vector2f>& getWaypoints() const;
};

#endif // PATROLLER_H