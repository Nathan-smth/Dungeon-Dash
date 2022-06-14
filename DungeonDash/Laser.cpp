#include "Laser.h"

sf::Texture* Laser::laserTexture = nullptr;

Laser::Laser(sf::Vector2f newScreenSize, std::string newWhereSpawn)
	:	Enemy	(newScreenSize, newWhereSpawn)
{
	if (laserTexture==nullptr)
	{
		laserTexture = new sf::Texture();
		laserTexture->loadFromFile("Assets/Graphics/Laser.png");

	}
	objectSprite.setTexture(*laserTexture);

	objectSprite.setScale(sf::Vector2f(2.0f, 1.0f));
}

bool Laser::isLaser()
{
	isAlaser = true;
	return isAlaser;
}



void Laser::AI()
{
	isAlaser = isLaser();
	
	sf::Vector2f laserPos = GetPosition();
	SetTarget(sf::Vector2f(-50, laserPos.y));
}
