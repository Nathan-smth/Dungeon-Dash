#include "Dart.h"


sf::Texture* Dart::dartTexture = nullptr;

Dart::Dart(sf::Vector2f newScreenSize, std::string newWhereSpawn)
	:	Enemy	(newScreenSize, newWhereSpawn)
{

	if (dartTexture == nullptr)
	{
		dartTexture = new sf::Texture();
		dartTexture->loadFromFile("Assets/Graphics/Dart.png");
	}

	objectSprite.setTexture(*dartTexture);
}

void Dart::AI()
{
	sf::Vector2f dartPos = GetPosition();
	SetTarget(sf::Vector2f(-50,dartPos.y));
}
