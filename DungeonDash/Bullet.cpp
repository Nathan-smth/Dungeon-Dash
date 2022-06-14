#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"

sf::Texture* Bullet::bulletTexture = nullptr;

Bullet::Bullet(int newWhoFired, float newFireDirection, Player* newPlayer)
	:	GameObject			()
	
	,	whoFired			(newWhoFired)
	,	movementTarget		(0, 0)
	,	arrivalDistance		(10)
	,	arrivedAtTarget		(true)
	,	fireDirection		(newFireDirection)
	,	screenSize			(0,0)
	,	fireingOffSet		(0,0)
	,	myPlayer			(newPlayer)


{
	if (bulletTexture == nullptr)
	{
		bulletTexture = new sf::Texture();
		bulletTexture->loadFromFile("Assets/Graphics/Bullet.png");
	}

	objectSprite.setTexture(*bulletTexture);


	moveSpeed = 250;

	fireingOffSet = sf::Vector2f(75, 43);

	SetPosition(myPlayer->GetPosition() + fireingOffSet);

}

void Bullet::HandelPlayerCollistion(Player* target)
{
	sf::FloatRect bulletCollider = GetCollider();
	sf::FloatRect PlayerCollider = target->GetCollider();


	if (target->GetPlayerNum() != whoFired)
	{
		if (bulletCollider.intersects(PlayerCollider))
		{
			target->TakeDamage(100);
			TakeDamage(100);
		}
	}

	
}

void Bullet::HandelEnemyCollistion(Enemy* target)
{

	sf::FloatRect bulletCollider = GetCollider();
	sf::FloatRect EnemyCollider = target->GetCollider();


	
		if (bulletCollider.intersects(EnemyCollider))
		{
			target->TakeDamage(100);
			TakeDamage(100);
		}
	
}

void Bullet::SetWhoFired(int _whoFired)
{
	whoFired = _whoFired;
}



void Bullet::SetScreenSize(sf::Vector2f newScreenSize)
{
	screenSize = newScreenSize;
}

void Bullet::SetTarget(sf::Vector2f newTarget)
{
	movementTarget = newTarget;
	arrivedAtTarget = false;
}

void Bullet::Update(sf::Time deltaTime)
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

void Bullet::AI()
{
	sf::Vector2f bulletPos = GetPosition();
	SetTarget(sf::Vector2f(screenSize.x + (fireDirection * 50), bulletPos.y));
}
