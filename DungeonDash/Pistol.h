#pragma once
#include "PowerUp.h"
class Pistol :
    public PowerUp
{
public:
    Pistol(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName);


protected:

    virtual void AI();

private:
    static sf::Texture* pistolTexture;
};

