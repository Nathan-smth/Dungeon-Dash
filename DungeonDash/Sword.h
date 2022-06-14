#pragma once
#include "Enemy.h"
class Player;

class Sword :
    public Enemy
{
public:
    Sword(sf::Vector2f newScreenSize, std::string newWhereSpawn, sf::Vector2f newPlayerPos);

     virtual  bool isSword() override;
    virtual bool IsItOverTimeToLive() override;

protected:

    virtual void AI() override;
   


private:
    static sf::Texture* swordTexture;
  




};

