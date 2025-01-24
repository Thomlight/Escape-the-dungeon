#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "Map.hpp"
#include "Player.hpp"
#include "Chaser.hpp"
#include "Patroller.hpp"
#include "Potion.hpp"
#include "Key.hpp"

using namespace std;
using namespace sf;

float DeltaTime;

void checkCollisions(Sprite sprite1, Sprite sprite2) {
    FloatRect bounds1 = sprite1.getGlobalBounds();
    FloatRect bounds2 = sprite2.getGlobalBounds();
    if (bounds1.intersects(bounds2)) {
        cout << "Collision detected!" << endl;
        cout << "not gud !" << endl;
    }
}

int main() {

    Clock clock;
    // Création de la fenêtre
    RenderWindow window(VideoMode(1440, 1000), "Escape the Dungeon");
    Event event;

    // Chargement des textures
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Title_Background.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du fond d'écran !");
    }

    Texture newBackgroundTexture;
    if (!newBackgroundTexture.loadFromFile("Normal_Background.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du nouveau fond d'écran !");
    }

    Texture startButtonTexture;
    if (!startButtonTexture.loadFromFile("Start_Button.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du bouton !");
    }

    Texture playerTexture;
    if (!playerTexture.loadFromFile("Crazy_Dave.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du joueur");
    }

    Texture ChaserTexture;
    if (!ChaserTexture.loadFromFile("Michael_Jackson_Zombie.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du zombie");
    }

    Texture PatrollerTexture;
    if (!PatrollerTexture.loadFromFile("Disco_Zombie.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du zombie");
    }

    Texture PotionTexture;
    if (!PotionTexture.loadFromFile("Potion.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du zombie");
    }

    Texture KeyTexture;
    if (!KeyTexture.loadFromFile("Key.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du zombie");
    }

    // Chargement des textures des murs et des portes
    Texture wallTexture;
    if (!wallTexture.loadFromFile("Wall_Nut.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture des murs");
    }

    Texture doorTexture;
    if (!doorTexture.loadFromFile("Door_Zombie.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture des portes");
    }

    // Création de la carte
    Map map("map.txt", "Wall_Nut.png", "Door_Zombie.png");

    // Création des sprites
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    Sprite startButtonSprite;
    startButtonSprite.setTexture(startButtonTexture);
    startButtonSprite.setPosition(455, 400);

    // Create the player sprite and scale it
    Player player(playerTexture, Vector2f(300, 400), 10.f);
    player.getSprite().setScale(sf::Vector2f(0.1f, 0.1f)); // Correct usage of setScale

    Sprite ChaserSprite;
    ChaserSprite.setTexture(ChaserTexture);
    Chaser chaser(ChaserTexture, Vector2f(600, 400), 100.f);
    chaser.setTarget(player.getPosition());
    chaser.getSprite().setScale(0.4f, 0.4f);

    Sprite PatrollerSprite;
    PatrollerSprite.setTexture(PatrollerTexture);
    vector<sf::Vector2f> path = { {100.f, 100.f},{200.f, 100.f},{200.f, 200.f},{100.f, 200.f} };
    Patroller patroller(PatrollerTexture, path[0], 100.f, path);
    patroller.getSprite().setScale(0.5f, 0.5f);

    Sprite PotionSprite;
    PotionSprite.setTexture(PotionTexture);
    Potion potion(PotionTexture, Vector2f(1000, 500), &player, true);

    Sprite KeySprite;
    KeySprite.setTexture(KeyTexture);
    Key key(KeyTexture, Vector2f(1000, 300), &player, true);

    // Flag pour changer le fond d'écran
    bool startPressed = false;

    // Boucle principale
    while (window.isOpen()) {
        // Gestion des événements
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }
        window.setFramerateLimit(60);
        DeltaTime = clock.restart().asSeconds();
        chaser.setTarget(player.getPosition());
        // Affichage

        window.clear();

        player.handleInput(map);
        player.update(DeltaTime);
        chaser.update(DeltaTime);
        patroller.updateP(DeltaTime);

        potion.interact(player);
        key.interact(player);

        // Check for collisions with doors and remove them if the player has a key
        if (player.hasKey()) {
            sf::FloatRect playerBounds = player.getSprite().getGlobalBounds();
            if (map.checkCollision(playerBounds)) {
                std::cout << "Player collided with a door." << std::endl;
                map.removeDoor(playerBounds);
                player.useKey();
            }
        }

        map.draw(window); // Draw the map
        player.draw(window);
        chaser.draw(window);
        patroller.draw(window);
        potion.draw(window);
        key.draw(window);

        cout << player.getKey() << endl;

        window.display();
    }

    return 0;
}