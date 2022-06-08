#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Klasa1.h"
/*
FORMATKA NA KOLOSA

UWAGA!!!
ZMIENCIE POZYCJE POCZATKOWE SPRITOW I KSZTALTOW!!!
*/


Klasa1 klasa1;


int main()
{
    //ustawienia okna
    sf::RenderWindow window(sf::VideoMode(600,600), "GAME");
    window.setFramerateLimit(60);

    //GLOWNA PETLA
    while (window.isOpen())
    {
        window.clear();
        //EVENTY
        sf::Event event;
        while (window.pollEvent(event))
        {
            //ZAMKNIECIE OKNA
            if (event.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }
            //KLAWISZE
            if (event.type == sf::Event::KeyPressed)
            {
                switch (event.key.code)
                {
                    //klawisz W
                    case sf::Keyboard::W:
                        break;

                    //klawisz escape - zamkniecie
                    case sf::Keyboard::Escape:
                        window.close();
                        return 0;
                }
            }
        }
        //rysowanie
        klasa1.display_shapes(window);
        window.display();
    }
    return 0;
}