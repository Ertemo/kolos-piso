#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Klasa1
{
    public:
        //konstruktor
        Klasa1();
        void display_shapes(sf::RenderWindow &window);
    private:
        sf::Sprite sprite;
        sf::RectangleShape prostokat;
        sf::CircleShape kolo;
};