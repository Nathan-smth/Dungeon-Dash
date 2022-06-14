#include "Enemy.h"
#include"Player.h"

Enemy::Enemy(sf::Vector2f newScreenSize, std::string newWhereSpawn)
	:	GameObject			()
	,	whereSpawn			(newWhereSpawn)
	,	movementTarget		(0,0)
	,	arrivalDistance		(10)
	,	arrivedAtTarget		(true)
	,	playerPos			()
	,	timeSinceSpawned	()
	,	isAlaser			(false)
	,	laserLiveTime		()
	,	timeThatLaserDies	(0.25f)
	
{
		sf::Vector2f newPosition(0, 0);
	//randomNumber = lower + rand() % (upper - lower)
	float estimateSpriteHeight = 100;
	float screenGap = 100;
	

	if (whereSpawn == "Right")
	{
		float lowerBound = newScreenSize.y/3;
		float upperBound = newScreenSize.y - screenGap - estimateSpriteHeight;
		newPosition.x = (int)newScreenSize.x;
		newPosition.y = lowerBound + rand() % (int)(upperBound - lowerBound);
		SetPosition(newPosition);
	}
	else if (whereSpawn == "Top")
	{
		float lowerBound = screenGap;
		float upperBound = newScreenSize.x - screenGap - estimateSpriteHeight;
		newPosition.y = newScreenSize.y / 3-70;
		newPosition.x = lowerBound + rand() % (int)(upperBound - lowerBound);
		SetPosition(newPosition);
	}
	

	//set up our move speed
	//moveSpeed = 200;
	
	
	

}

void Enemy::Update(sf::Time deltaTime)
{
	
	timeSinceSpawned +=deltaTime;
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

		if (isAlaser == true)
		{
			laserLiveTime += deltaTime;
			if (laserLiveTime.asSeconds() >= timeThatLaserDies)
			{
				

				TakeDamage(100);
				laserLiveTime =  sf::Time();
			}
		}
		else
		{
			TakeDamage(100);
		}
		
	
		
	}
}

void Enemy::HandelCollistion(Player* target)
{
	sf::FloatRect enemyCollider = GetCollider();
	sf::FloatRect playerCollider = target->GetCollider();

	if (enemyCollider.intersects(playerCollider))
	{
		if (target->GetCurrentPowerUp() == "ActiveSpikeShoe")
		{
			TakeDamage(100);
		}
		else

		{
			target->SetPlayHit(true);
			target->TakeDamage(100);
			TakeDamage(100);
			
			
		}
		
	}
}

void Enemy::HandelEnemyCollistion(Enemy* target)
{
	sf::FloatRect laserCollider = GetCollider();
	sf::FloatRect enemyCollider = target->GetCollider();
	if (isAlaser == true)
	{
		if (laserCollider.intersects(enemyCollider))
		{


			target->TakeDamage(100);


		}
	}

}



void Enemy::SetTarget(sf::Vector2f newTarget)
{
	movementTarget = newTarget;
	arrivedAtTarget = false;
}

void Enemy::AI()
{
}

void Enemy::SetPlayerPos(sf::Vector2f _playerPos)
{
	playerPos = _playerPos;
}

bool Enemy::isSword()
{
	return false;
}

bool Enemy::IsItOverTimeToLive()
{
	return false;
}

bool Enemy::isLaser()
{
	return isAlaser;
}

void Enemy::SetMoveSpeed(float newMoveSpeed)
{
	moveSpeed = newMoveSpeed;
}


