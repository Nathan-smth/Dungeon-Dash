#include "SpikeShoe.h"
sf::Texture* SpikeShoe::spikeShoeTexture = nullptr;
SpikeShoe::SpikeShoe(sf::Vector2f newScreenSize, std::string newWhereSpawn, std::string newPowerUpName)
	: PowerUp(newScreenSize, newWhereSpawn, newPowerUpName)
{

	if (spikeShoeTexture == nullptr)
	{
		spikeShoeTexture = new sf::Texture();
		spikeShoeTexture->loadFromFile("Assets/Graphics/SpikeShoe.png");
	}

	objectSprite.setTexture(*spikeShoeTexture);

}

void SpikeShoe::AI()
{
	sf::Vector2f spikeShoePos = GetPosition();
	SetTarget(sf::Vector2f(-50, spikeShoePos.y));
}

