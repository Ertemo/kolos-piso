#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include "Klasa1.h"
#include "Ball.h"
/*
FORMATKA NA KOLOSA

UWAGA!!!

PRZYSPIESZENIE DZIALA PO PIERWSZYM ODBICIU!!!
*/


Player player;
Ball ball;

int main()
{
    bool odb = true;
    //ustawienia okna
    sf::RenderWindow window(sf::VideoMode(600,600), "GAME");
    window.setFramerateLimit(60);
    
    sf::Clock clock;
    sf::Clock clock1;
    sf::Time time;
    sf::Time time1;
    clock.restart();
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
                    //klawisz
                    case sf::Keyboard::Left:
                        player.step(true);
                        break;
                    case sf::Keyboard::Right:
                        player.step(false);
                        break;
                    //klawisz escape - zamkniecie
                    case sf::Keyboard::Escape:
                        window.close();
                        return 0;
                }
            }
        }
        //rysowanie
        if ((player.position - player.length_left <= ball.posx) && (player.position + player.length_right >= ball.posx) && (ball.posy > 590.f))
        {
            ball.velocityy = - abs(ball.velocityy);
            if (odb = true)
            {
                player.paletka.setFillColor(sf::Color::Red);
            }
            else
            {
                player.paletka.setFillColor(sf::Color::White);
            }
            odb = !odb;
        }
        time = clock.getElapsedTime();
        if (time.asSeconds() >= 5 && (player.length_right + player.length_left > 30.f))
        {
            player.length_left = player.length_left - 5.f;
            player.length_right = player.length_right - 5.f;
            clock.restart();
        }
        time1 = clock1.getElapsedTime();
        ball.step(time1);
        player.display_shapes(window);
        window.draw(ball.pilka);
        window.display();
        if (ball.posy > 600.f)
        {
            std::cout<<"KONIEC GRY"<<std::endl;
            return 0;
        }
    }
    return 0;
}