#pragma once
#include "PowerUp.h"
class BrokenWatch :
    public PowerUp
{
public:
    BrokenWatch(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName);

protected:
    virtual void AI();


private:

    static sf::Texture* brokenWatchTexture;
};

