#pragma once
#include "PowerUp.h"
class OldDrink :
    public PowerUp
{
public:
    OldDrink(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName);

protected:
    virtual void AI();

private:
    static sf::Texture* oldDrinkTexture;
    sf::Vector2f screenSize;
};

