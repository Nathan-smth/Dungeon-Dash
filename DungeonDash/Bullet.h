#pragma once
#include "GameObject.h"
class Player;
class Enemy;
class Bullet :
    public GameObject
{
public:
    Bullet(int newWhoFired, float newFireDirection,Player* newPlayer);

    void HandelPlayerCollistion(Player* target);
    void HandelEnemyCollistion(Enemy* target);
    void SetWhoFired(int _whoFired);
   
    void SetScreenSize(sf::Vector2f newScreenSize);
    void SetTarget(sf::Vector2f newTarget);
    

    virtual void Update(sf::Time deltaTime) override;
private:

    void AI();

    static sf::Texture* bulletTexture;
   
    int whoFired;


    sf::Vector2f movementTarget;
    float arrivalDistance;
    bool arrivedAtTarget;
    float fireDirection;
   
    sf::Vector2f screenSize;
    sf::Vector2f fireingOffSet;

    Player* myPlayer;
};

