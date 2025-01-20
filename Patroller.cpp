#include "Patroller.hpp"

Patroller::Patroller(const Texture& texture, const Vector2f& startPosition, float speed, const vector<Vector2f>& waypoints)
    : Enemy(texture, startPosition, speed), waypoints(waypoints), currentWaypointIndex(0), reverse(false) {
    if (!waypoints.empty()) {
        setPosition(waypoints[0]); // Start at the first waypoint
    }
}

void Patroller::update(float deltaTime) {
    if (waypoints.empty()) return; // No waypoints, no movement

    Vector2f target = waypoints[currentWaypointIndex];
    Vector2f direction = target - getPosition();
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    // Normalize direction
    if (distance > 0) {
        direction /= distance;
    }

    // Move towards the target waypoint
    setVelocity(direction * speed);
    position += getVelocity() * deltaTime;
    setPosition(position);

    // Check if the patroller reached the current waypoint
    if (distance < speed * deltaTime) {
        // Snap to the waypoint and advance to the next one
        setPosition(target);

        if (!reverse) {
            currentWaypointIndex++;
            if (currentWaypointIndex >= waypoints.size()) {
                reverse = true; // Reverse direction at the end
                currentWaypointIndex = waypoints.size() - 2;
            }
        }
        else {
            if (currentWaypointIndex == 0) {
                reverse = false; // Switch direction at the start
                currentWaypointIndex = 1;
            }
            else {
                currentWaypointIndex--;
            }
        }
    }
}

void Patroller::setWaypoints(const vector<Vector2f>& newWaypoints) {
    waypoints = newWaypoints;
    currentWaypointIndex = 0;
    reverse = false;
    if (!waypoints.empty()) {
        setPosition(waypoints[0]); // Reset to the first waypoint
    }
}

const vector<Vector2f>& Patroller::getWaypoints() const {
    return waypoints;
}
