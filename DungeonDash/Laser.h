#pragma once
#include "Enemy.h"
class Laser :
    public Enemy
{
public:
    Laser(sf::Vector2f newScreenSize, std::string newWhereSpawn);

   virtual bool isLaser() override;
  
protected:
    virtual void AI();

private:
    static sf::Texture* laserTexture;
};

