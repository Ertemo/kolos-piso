#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Player
{
    public:
        //konstruktor
        Player();
        void display_shapes(sf::RenderWindow &window);
        void step(bool left);
        float position;
        float length_right;
        float length_left;
        sf::RectangleShape paletka;
    private:
        sf::Sprite sprite;
        sf::CircleShape kolo;
};