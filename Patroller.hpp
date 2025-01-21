#ifndef PATROLLER_H
#define PATROLLER_H

#include "Enemy.hpp"
#include <vector>

class Patroller : public Enemy {
private:
    vector<Vector2f> waypoints; // List of waypoints for the patroller to follow
    size_t currentWaypointIndex;         // Current waypoint index
    bool reverse;                        // Direction of movement (true: backward, false: forward)

public:
    Patroller(const Texture& texture, const Vector2f& startPosition, float speed, const vector<Vector2f>& waypoints);

    void updateP(float deltaTime);

    void setWaypoints(const vector<Vector2f>& newWaypoints);
    const vector<Vector2f>& getWaypoints() const;
};

#endif // PATROLLER_H