#include "OldDrink.h"
sf::Texture* OldDrink::oldDrinkTexture = nullptr;
OldDrink::OldDrink(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName)
	:	PowerUp	(newScreenSize, newWhereSpawn, newPowerUpName)
	,	screenSize	(newScreenSize)
{
	if (oldDrinkTexture == nullptr)
	{
		oldDrinkTexture = new sf::Texture();
		oldDrinkTexture->loadFromFile("Assets/Graphics/OldDrink.png");
	}

	objectSprite.setTexture(*oldDrinkTexture);
}

void OldDrink::AI()
{


	sf::Vector2f oldDrinklPos = GetPosition();
	if (whereSpawn == "Right")
	{
		
		SetTarget(sf::Vector2f(-50, oldDrinklPos.y));

	}
	else if (whereSpawn == "Top")
	{
		SetTarget(sf::Vector2f(oldDrinklPos.x, screenSize.y));
	}
	
}
