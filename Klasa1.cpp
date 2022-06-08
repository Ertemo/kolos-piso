#include "Klasa1.h"

//konstruktor
Klasa1::Klasa1()
{
    //ustaw kolory 
    prostokat.setFillColor(sf::Color::White);
    kolo.setFillColor(sf::Color::White);

    //ustaw rozmiar float x float
    prostokat.setSize(sf::Vector2f(10.f,10.f));
    //ustaw promien
    kolo.setRadius(10.f);

    //ustaw pozycje
    prostokat.setPosition(sf::Vector2f(0.f,0.f));
    kolo.setPosition(sf::Vector2f(50.f,50.f));
    sprite.setPosition(sf::Vector2f(100.f,100.f));

    //zaladuj teksture do spirtea
    sf::Texture tekstura;
    if (!tekstura.loadFromFile("plik.png"))
    {
        std::cout<<"NIE UDALO SIE ZALADOWAC TESKTURY"<<std::endl;
    }
    else
    {
        //zaladuj teksture do spritea
        //TEKSTURA ZOSTANIE ZAPISANA DO SPIRTEA I NIE JEST DALEJ POTRZEBNA
        sprite.setTexture(tekstura);
    }
}

void Klasa1::display_shapes(sf::RenderWindow &window)
{
    window.draw(prostokat);
    window.draw(kolo);
    window.draw(sprite);
}