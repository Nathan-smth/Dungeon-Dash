#pragma once
#include "Enemy.h"
class Brick :
    public Enemy
{
public:
    Brick(sf::Vector2f newScreenSize, std::string newWhereSpawn);
protected:

    virtual void AI();


private:
    static sf::Texture* brickTexture;
    sf::Vector2f screenSize;
};

