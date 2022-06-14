#pragma once
#include "PowerUp.h"
class Coin :
    public PowerUp
{
public:
    Coin(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName);

protected:
    virtual void AI();

private:
    static sf::Texture* coinTetxure;
};

