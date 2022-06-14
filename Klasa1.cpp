#include "Klasa1.h"

//konstruktor
Player::Player()
{
    sf::Texture tekstura;
    //ustaw kolory 
    paletka.setFillColor(sf::Color::White);
    kolo.setFillColor(sf::Color::White);

    //ustaw rozmiar float x float
    paletka.setSize(sf::Vector2f(70.f,10.f));
    //ustaw promien
    kolo.setRadius(10.f);

    //ustaw pozycje
    paletka.setPosition(sf::Vector2f(0.f,590.f));
    kolo.setPosition(sf::Vector2f(50.f,50.f));
    sprite.setPosition(sf::Vector2f(100.f,100.f));

    //zaladuj teksture do spirtea
    position = 35.f;
    length_right = 35.f;
    length_left = 35.f;
}

void Player::display_shapes(sf::RenderWindow &window)
{
    window.draw(paletka);
}

void Player::step(bool left)
{
    float velocity = 10.f;
    paletka.setSize(sf::Vector2f(length_left + length_right,10.f));

    if (position + length_right < 600.f && left == false)
    { 
        position = position + velocity;
        paletka.setPosition(sf::Vector2f(position - length_left, 590.f));
    }
    if (position - length_left > 0.f && left == true)
    {
        position = position - velocity;
        paletka.setPosition(sf::Vector2f(position - length_left, 590.f));
    }
    
}