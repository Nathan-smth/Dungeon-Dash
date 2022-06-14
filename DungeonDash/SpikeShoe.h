#pragma once
#include "PowerUp.h"
class SpikeShoe :
    public PowerUp
{
public:
    SpikeShoe(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName);


protected:

    virtual void AI();
private:
    static sf::Texture* spikeShoeTexture;

};

