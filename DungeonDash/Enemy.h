#pragma once
#include "GameObject.h"
class Player;
class Enemy :
	public GameObject
{
public:
	//constructor
	Enemy(sf::Vector2f newScreenSize, std::string newWhereSpawn);


	//functions
	virtual void Update(sf::Time deltaTime) override;

	virtual void HandelCollistion(Player* target);
	void HandelEnemyCollistion(Enemy* target);

	void SetPlayerPos(sf::Vector2f _playerPos);
	virtual bool isSword();
	virtual bool IsItOverTimeToLive();
	virtual bool isLaser();

	void SetMoveSpeed(float newMoveSpeed);


protected:
	//data
	sf::Sprite enemySprite;
	std::string whereSpawn;
	

	void SetTarget(sf::Vector2f newTarget);
	virtual void AI();
	sf::Time timeSinceSpawned;

	sf::Vector2f playerPos;

	bool isAlaser;
	sf::Time laserLiveTime;
	float timeThatLaserDies;


private:
	sf::Vector2f movementTarget;
	float arrivalDistance;
	bool arrivedAtTarget;
	




};

