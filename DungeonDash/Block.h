#pragma once
#include "Enemy.h"
class Block :
    public Enemy
{
public:
    Block(sf::Vector2f newScreenSize, std::string newWhereSpawn);


    virtual void HandelCollistion(Player* target) override;

protected:
    virtual void AI();
private:
    static sf::Texture* blockTexture;
    bool onTop;
    bool onSide;

    sf::Vector2f CollisionDepth(sf::FloatRect a, sf::FloatRect b);
    float VectorDot(sf::Vector2f a, sf::Vector2f b);


};

