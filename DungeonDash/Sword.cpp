#include "Sword.h"
#include"Player.h"

sf::Texture* Sword::swordTexture = nullptr;

Sword::Sword(sf::Vector2f newScreenSize, std::string newWhereSpawn, sf::Vector2f newPlayerPos)
	:	Enemy	(newScreenSize,newWhereSpawn)
	
{

	if (swordTexture == nullptr)
	{
		swordTexture = new sf::Texture();
		swordTexture->loadFromFile("Assets/Graphics/Sword.png");
	}

	objectSprite.setTexture(*swordTexture);
}

bool Sword::isSword()
{
	return true;
}

bool Sword::IsItOverTimeToLive()
{
	bool shouldBeGone = false;
	sf::Time liveTime = sf::seconds(6.0f);
	if (timeSinceSpawned >= liveTime)
	{
		shouldBeGone = true;
	}
	return shouldBeGone;
}

void Sword::AI()
{
	SetTarget(playerPos);
	
}


