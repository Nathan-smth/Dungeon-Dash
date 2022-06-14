#pragma once
#include "Enemy.h"
class Dart :
    public Enemy
{
public:
    Dart(sf::Vector2f newScreenSize, std::string newWhereSpawn);


protected:

    virtual void AI();


private:
    static sf::Texture* dartTexture;

};

