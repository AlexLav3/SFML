#include <SFML/Graphics.hpp>
#include <iostream>
#include "animation.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Default ); 
    sf::RectangleShape player(sf::Vector2f(150.0f, 100.0f)); 
    sf::Texture playerTexture; 
    playerTexture.loadFromFile("wolfsheet1.png"); 
    player.setTexture(&playerTexture); 

    player.setOrigin(50.0f, 50.f); 

    animation animation(&playerTexture, sf::Vector2u(3,9), 0.3f); 

    float deltaTime = 0.0f; 
    sf::Clock clock; 
  
    while (window.isOpen()) {

       deltaTime =   clock.restart().asSeconds(); 

        sf::Event evnt; 
        while (window.pollEvent(evnt)) {

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
            
            player.move(-0.1f, 0.0f); 
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {

            player.move(0.1f, 0.0f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {

            player.move(0.0f, -0.1f);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {

            player.move(0.0f, 0.01f);
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

            sf::Vector2i MousePos = sf::Mouse::getPosition(window);
            player.setPosition((float)MousePos.x, static_cast<float>(MousePos.y));
        }

        animation.Update(0, deltaTime); 
        player.setTextureRect(animation.uvRect); 

        window.clear(); 
        window.draw(player); 
        window.display(); 
    }
    return 0;
}