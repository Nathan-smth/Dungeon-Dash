#include "BrokenWatch.h"
sf::Texture* BrokenWatch::brokenWatchTexture = nullptr;
BrokenWatch::BrokenWatch(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName)
	:	PowerUp(newScreenSize, newWhereSpawn, newPowerUpName)
{


	if (brokenWatchTexture == nullptr)
	{
		brokenWatchTexture = new sf::Texture();
		brokenWatchTexture->loadFromFile("Assets/Graphics/BrokenWatch.png");
	}

	objectSprite.setTexture(*brokenWatchTexture);

}

void BrokenWatch::AI()
{
	sf::Vector2f pistolPos = GetPosition();
	SetTarget(sf::Vector2f(-50, pistolPos.y));
}
