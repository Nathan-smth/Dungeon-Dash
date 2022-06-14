#pragma once
#include "Background.h"
class GameBackground :
    public Background
{
public:

    GameBackground();
    virtual void Update(sf::Time deltaTime);
    void SetVelocity(sf::Vector2f _velocity);
    void SetPosition(sf::Vector2f _position);
    sf::Vector2f GetPosition();


private:
    static sf::Texture* gameTexture;
    sf::Vector2f velocity;
    sf::Vector2f position;


    void Move(sf::Vector2f direction);

};

