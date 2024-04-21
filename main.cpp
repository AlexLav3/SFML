#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"
#include "player.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Default ); 
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(512.0f,512.0f));
    sf::Texture playerTexture; 
    playerTexture.loadFromFile("wolfsheet3.png"); 

    Player player(&playerTexture, sf::Vector2u(5, 8), 0.3f, 100.0f); 
    
    float deltaTime = 0.0f; 
    sf::Clock clock; 
  
    while (window.isOpen()) {

       deltaTime =   clock.restart().asSeconds(); 

        sf::Event evnt; 
        while (window.pollEvent(evnt)) {

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }

            switch (evnt.type) {

            case sf::Event::Closed:
                window.close(); 
                break;

            case sf::Event::Resized: 

                std::cout << evnt.size.width << evnt.size.height << std::endl; 
                printf("New Window width : %i New Window Height : %i \n", evnt.size.width, evnt.size.height);
                break; 

            case sf::Event::TextEntered: 
                if (evnt.text.unicode < 128) {
                    printf("%c", evnt.text.unicode);
                }

            }
        }
        player.Update(deltaTime); 
        view.setCenter(player.GetPosition()); 

        window.clear(); 
        window.setView(view); 
        player.Draw(window); 
        window.display(); 
    }
    return 0;
}