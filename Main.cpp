#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <sstream>
#include "Map.hpp"
#include "Player.hpp"
#include "Chaser.hpp"
#include "Patroller.hpp"
#include "Potion.hpp"
#include "Key.hpp"

using namespace std;
using namespace sf;

float DeltaTime;
bool gameLost = false;
Clock gameClock;
Time gameTime;

void checkCollisions(Sprite sprite1, Sprite sprite2) {
    FloatRect bounds1 = sprite1.getGlobalBounds();
    FloatRect bounds2 = sprite2.getGlobalBounds();
    if (bounds1.intersects(bounds2)) {
        cout << "Collision detected! Game Over!" << endl;
        gameLost = true;
        gameTime = gameClock.getElapsedTime();
    }
}

void Start(Player& player, Chaser& chaser, Patroller& patroller, Potion& potion, Key& key, Clock& clock) {
    // Set initial positions for player, enemies, and items
    player.setPosition(Vector2f(300, 400));
    player.setSpeed(5.f);
    chaser.setPosition(Vector2f(600, 400));
    patroller.setPosition(Vector2f(100, 100));
    potion.setPosition(Vector2f(1000, 500));
    potion.setActive();
    key.setPosition(Vector2f(1000, 300));
    key.setIsActive();

    // Reset the clocks for DeltaTime and game time
    clock.restart();
    gameClock.restart();
}

int main() {
    Clock clock;
    // Create the window
    RenderWindow window(VideoMode(1410, 1000), "Escape the Garden");
    Event event;

    // Load textures
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("Title_Background.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du fond d'écran !");
    }

    Texture lostBackgroundTexture;
    if (!lostBackgroundTexture.loadFromFile("Lost_Background.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du fond perdu !");
    }

    Texture startButtonTexture;
    if (!startButtonTexture.loadFromFile("Start_Button.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture du bouton !");
    }

    Texture exitButtonTexture;
    if (!exitButtonTexture.loadFromFile("Exit_Button.png")) {
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

    // Load wall and door textures
    Texture wallTexture;
    if (!wallTexture.loadFromFile("Wall_Nut.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture des murs");
    }

    Texture doorTexture;
    if (!doorTexture.loadFromFile("Door_Zombie.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture des portes");
    }

    Texture grassTexture;
    if (!grassTexture.loadFromFile("Grass.png")) {
        throw runtime_error("Erreur : Impossible de charger la texture de l'herbe");
    }

    // Create the map
    Map map("map.txt", "Wall_Nut.png", "Door_Zombie.png", "Grass.png");

    // Create sprites
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(
        window.getSize().x / backgroundSprite.getLocalBounds().width,
        window.getSize().y / backgroundSprite.getLocalBounds().height
    );

    Sprite lostBackgroundSprite;
    lostBackgroundSprite.setTexture(lostBackgroundTexture);
    lostBackgroundSprite.setScale(
        window.getSize().x / lostBackgroundSprite.getLocalBounds().width,
        window.getSize().y / lostBackgroundSprite.getLocalBounds().height
    );

    Sprite startButtonSprite;
    startButtonSprite.setTexture(startButtonTexture);
    startButtonSprite.setPosition(455, 400);

    Sprite exitButtonSprite;
    exitButtonSprite.setTexture(exitButtonTexture);
    exitButtonSprite.setPosition(455, 600);

    // Create the player sprite and scale it
    Player player(playerTexture, Vector2f(300, 400), 5.f);
    player.getSprite().setScale(sf::Vector2f(0.1f, 0.1f)); // Correct usage of setScale

    Sprite ChaserSprite;
    ChaserSprite.setTexture(ChaserTexture);
    Chaser chaser(ChaserTexture, Vector2f(600, 400), 100.f);
    chaser.setTarget(player.getPosition());
    chaser.getSprite().setScale(0.2f, 0.2f);

    Sprite PatrollerSprite;
    PatrollerSprite.setTexture(PatrollerTexture);
    vector<sf::Vector2f> path = { {100.f, 100.f},{200.f, 100.f},{200.f, 200.f},{100.f, 200.f} };
    Patroller patroller(PatrollerTexture, path[0], 100.f, path);
    patroller.getSprite().setScale(0.3f, 0.3f);

    Sprite PotionSprite;
    PotionSprite.setTexture(PotionTexture);
    Potion potion(PotionTexture, Vector2f(1000, 500), &player, true);

    Sprite KeySprite;
    KeySprite.setTexture(KeyTexture);
    Key key(KeyTexture, Vector2f(1000, 300), &player, true);

    // Create the font and text for displaying the elapsed time
    Font font;
    if (!font.loadFromFile("comicneuesansid.ttf")) {
        throw runtime_error("Erreur : Impossible de charger la police !");
    }

    Text elapsedTimeText;
    elapsedTimeText.setFont(font);
    elapsedTimeText.setCharacterSize(30);
    elapsedTimeText.setFillColor(Color::Black); // Set text color to black
    elapsedTimeText.setPosition(600, 300);

    // Flag to check if the game has started
    bool gameStarted = false;

    // Main loop
    while (window.isOpen()) {
        // Handle events
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);
                if (!gameStarted || gameLost) {
                    if (startButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        gameStarted = true;
                        gameLost = false;
                        Start(player, chaser, patroller, potion, key, clock);  // Initialize game objects
                    }
                    if (exitButtonSprite.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        window.close();
                    }
                }
            }
        }

        window.clear();

        // Check if the game has started and not lost
        if (!gameStarted) {
            window.draw(backgroundSprite);
            window.draw(startButtonSprite);
            window.draw(exitButtonSprite);
        }
        else if (gameLost) {
            window.draw(lostBackgroundSprite);
            window.draw(startButtonSprite);
            window.draw(exitButtonSprite);

            // Display elapsed time
            stringstream ss;
            ss << "Temps de jeu: " << gameTime.asSeconds() << " seconds";
            elapsedTimeText.setString(ss.str());
            window.draw(elapsedTimeText);
        }
        else {
            window.setFramerateLimit(60);
            DeltaTime = clock.restart().asSeconds();
            chaser.setTarget(player.getPosition());

            player.handleInput(map);
            player.update(DeltaTime);
            chaser.update(DeltaTime);
            patroller.updateP(DeltaTime);

            // Check for collisions
            checkCollisions(player.getSprite(), chaser.getSprite());
            checkCollisions(player.getSprite(), patroller.getSprite());

            potion.interact(player);
            key.interact(player);

            map.draw(window); // Draw the map
            player.draw(window);
            chaser.draw(window);
            patroller.draw(window);
            potion.draw(window);
            key.draw(window);
        }

        window.display();
    }

    return 0;
}