#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "SFML Tutorial", sf::Style::Default ); 

    while (window.isOpen()) {

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
    }
    return 0;
}