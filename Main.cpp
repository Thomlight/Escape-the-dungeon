#include "Player.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace std;
using namespace sf;

float Deltatime;

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
        throw runtime_error("Erreur : Impossible de charger la texture de dave !");
    }

    // Création des sprites
    Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);

    Sprite startButtonSprite;
    startButtonSprite.setTexture(startButtonTexture);
    startButtonSprite.setPosition(455, 400);

    Sprite playerSprite;
    playerSprite.setTexture(playerTexture);
    Player Dave(playerSprite,1);

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

            // Gestion des clics sur le bouton
            //if (!startPressed && event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                //Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
               // if (startButtonSprite.getGlobalBounds().contains(mousePos)) {
                    // Action du bouton : changement du fond
                   // startPressed = true;
                   // cout << "Bouton Start clique ! Fond change." << endl;

                    // Mise à jour du fond d'écran
                   // backgroundSprite.setTexture(newBackgroundTexture);

                    // Mise à l'échelle pour le nouveau fond
                    //Vector2u newTextureSize = newBackgroundTexture.getSize();
                    //scaleX = static_cast<float>(windowSize.x) / newTextureSize.x;
                    //scaleY = static_cast<float>(windowSize.y) / newTextureSize.y;
                    //backgroundSprite.setScale(scaleX, scaleY);

                    // Masquer et désactiver le bouton
                    //startButtonSprite.setColor(Color::Transparent);
                //}
            //}

            Dave.handleInput();

        }

        // Affichage
        window.clear();
        //window.draw(backgroundSprite); // Dessin du fond d'écran
        //if (!startPressed) {
           // window.draw(startButtonSprite); // Dessin du bouton uniquement si non pressé
        //}
        window.draw(playerSprite);
        window.display();
    }

    return 0;
}
