#include "Pistol.h"
sf::Texture* Pistol::pistolTexture = nullptr;

Pistol::Pistol(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName)
	:	PowerUp	(newScreenSize,newWhereSpawn,newPowerUpName)

{
	if (pistolTexture == nullptr)
	{
		pistolTexture = new sf::Texture();
		pistolTexture->loadFromFile("Assets/Graphics/Pistol.png");
	}

	objectSprite.setTexture(*pistolTexture);


}

void Pistol::AI()
{
	sf::Vector2f pistolPos = GetPosition();
	SetTarget(sf::Vector2f(-50, pistolPos.y));
}
