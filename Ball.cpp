#include "Ball.h"

Ball::Ball()
{
    pilka.setRadius(7.f);
    pilka.setPosition(sf::Vector2f(300.f, 300.f));
    posx = 300.f;
    posy = 300.f;
    velocityx = 2.f;
    velocityy = -5.f;
    gravit = 0.00001f;
    if (!tekstura.loadFromFile("pobrane.jpeg"))
    {
        std::cout<<"NIE UDALO SIE ZALADOWAC TESKTURY"<<std::endl;
    }
        //zaladuj teksture do spritea
    pilka.setTexture(&tekstura);
}

void Ball::step(sf::Time time)
{
    posx = posx + velocityx;
    posy = posy + velocityy;
    if (posx < 0.f || posx > 600.f)
    {
        velocityx = - velocityx;
    }
    if (posy < 0.f)
    {
        velocityy = -velocityy;
    }
    velocityy = velocityy + gravit * time.asMilliseconds();
    pilka.setPosition(sf::Vector2f(posx,posy));
}
