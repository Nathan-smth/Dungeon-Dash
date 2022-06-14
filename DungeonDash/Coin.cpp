#include "Coin.h"
sf::Texture* Coin::coinTetxure = nullptr;

Coin::Coin(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName)
	:	PowerUp	(newScreenSize,newWhereSpawn,newPowerUpName)
{


	if (coinTetxure == nullptr)
	{
		coinTetxure = new sf::Texture();
		coinTetxure->loadFromFile("Assets/Graphics/Coin.png");
	}

	objectSprite.setTexture(*coinTetxure);
}

void Coin::AI()
{
	sf::Vector2f pistolPos = GetPosition();
	SetTarget(sf::Vector2f(-50, pistolPos.y));
}
