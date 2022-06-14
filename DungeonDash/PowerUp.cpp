#include "PowerUp.h"

PowerUp::PowerUp(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName)
	:	GameObject		()
	,	powerUpSprite	()
	,	whereSpawn		(newWhereSpawn)
	,	powerUpName		(newPowerUpName)
	,	movementTarget	(0,0)
	,	arrivalDistance	(10)
	,	arrivedAtTarget	(true)
{
	sf::Vector2f newPosition(0, 0);
	float estimateSpriteHeight = 100;
	float screenGap = 100;


	if (whereSpawn == "Right")
	{
		float lowerBound = newScreenSize.y / 3;
		float upperBound = newScreenSize.y - screenGap - estimateSpriteHeight;
		newPosition.x = (int)newScreenSize.x;
		newPosition.y = lowerBound + rand() % (int)(upperBound - lowerBound);
		SetPosition(newPosition);
	}
	else if (whereSpawn == "Top")
	{
		float lowerBound = screenGap;
		float upperBound = newScreenSize.x - screenGap - estimateSpriteHeight;
		newPosition.y = newScreenSize.y / 3 - 70;
		newPosition.x = lowerBound + rand() % (int)(upperBound - lowerBound);
		SetPosition(newPosition);
	}

	//set up our move speed
	moveSpeed = 250;

}

void PowerUp::Update(sf::Time deltaTime)
{
	AI();
	if (!arrivedAtTarget)
	{
		sf::Vector2f direction = movementTarget - GetPosition();
		Move(direction);
	}
	else
	{
		SetVelocity(sf::Vector2f(0, 0));

	}

	GameObject::Update(deltaTime);

	sf::Vector2f distanceVector = movementTarget - GetPosition();
	float distance = sqrtf(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);
	if (distance <= arrivalDistance)
	{
		//we have arrived!
		arrivedAtTarget = true;
		TakeDamage(100);
	}
}

std::string PowerUp::GetPowerUpName()
{
	return powerUpName;
}

void PowerUp::SetTarget(sf::Vector2f newTarget)
{
	movementTarget = newTarget;
	arrivedAtTarget = false;
}

void PowerUp::AI()
{
}

