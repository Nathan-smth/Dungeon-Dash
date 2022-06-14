#pragma once
#include "GameObject.h"
class PowerUp :
    public GameObject
{
public:
	//constructor
	PowerUp(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName);


	//functions
	virtual void Update(sf::Time deltaTime) override;
	std::string GetPowerUpName();


protected:
	//data
	sf::Sprite powerUpSprite;
	std::string whereSpawn;
	std::string powerUpName;

	void SetTarget(sf::Vector2f newTarget);
	virtual void AI();

private:

	sf::Vector2f movementTarget;
	float arrivalDistance;
	bool arrivedAtTarget;
};

