#include "Player.hpp"
#include "Enemy.hpp"
#include "Chaser.hpp"
#include "Patroller.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
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

    // Création des sprites
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    Sprite startButtonSprite;
    startButtonSprite.setTexture(startButtonTexture);
    startButtonSprite.setPosition(455, 400);

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    Player player(playerTexture, Vector2f(300,200), 10.f);
    player.getSprite().setScale(0.5f, 0.5f);

    Sprite ChaserSprite;
    ChaserSprite.setTexture(ChaserTexture);
    Chaser chaser(ChaserTexture, Vector2f(600, 400), 100.f);
    chaser.setTarget(playerSprite.getPosition());
    chaser.getSprite().setScale(1.0f, 1.0f);

    Sprite PatrollerSprite;
    PatrollerSprite.setTexture(PatrollerTexture);
    vector<sf::Vector2f> path = {
    {100.f, 100.f},
    {200.f, 100.f},
    {200.f, 200.f},
    {100.f, 200.f}
    };
    Patroller patroller(PatrollerTexture, path[0], 100.f, path );
    patroller.getSprite().setScale(0.5f, 0.5f);

    // Mise à l'échelle du fond pour couvrir la fenêtre
    //Vector2u textureSize = backgroundTexture.getSize(); // Taille de la texture
    //Vector2u windowSize = window.getSize();             // Taille de la fenêtre

    //float scaleX = static_cast<float>(windowSize.x) / textureSize.x;
    //float scaleY = static_cast<float>(windowSize.y) / textureSize.y;

    //backgroundSprite.setScale(scaleX, scaleY); // Ajustement de l'échelle

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
        //window.draw(backgroundSprite); // Dessin du fond d'écran
        //if (!startPressed) {
           // window.draw(startButtonSprite); // Dessin du bouton uniquement si non pressé
        //}

        player.handleInput();
        player.update(DeltaTime);
        chaser.update(DeltaTime);
        patroller.update(DeltaTime);

        checkCollisions(player.getSprite(),chaser.getSprite());
        checkCollisions(player.getSprite(), patroller.getSprite());

        player.draw(window);
        chaser.draw(window);
        patroller.draw(window);
        window.display();
    }

    return 0;
}
