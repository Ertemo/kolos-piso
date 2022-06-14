#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Ball
{
    public:
        Ball();
        sf::CircleShape pilka;
        void step(sf::Time time);
        float velocityx;
        float velocityy;
        float posx;
        float posy;
        float gravit;
        sf::Texture tekstura;
};