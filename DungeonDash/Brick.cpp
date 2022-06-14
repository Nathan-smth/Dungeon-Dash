#include "Brick.h"

sf::Texture* Brick::brickTexture = nullptr;

Brick::Brick(sf::Vector2f newScreenSize, std::string newWhereSpawn)
	:	Enemy		(newScreenSize,newWhereSpawn)
	,	screenSize	(newScreenSize)
{

	if (brickTexture == nullptr)
	{
		brickTexture = new sf::Texture();
		brickTexture->loadFromFile("Assets/Graphics/Brick.png");
	}

	objectSprite.setTexture(*brickTexture);
	

	sf::Vector2f spriteSize = objectSprite.getScale();
	
	objectSprite.setScale(spriteSize.x*2,spriteSize.y*2);
}

void Brick::AI()
{
	sf::Vector2f brickPos = GetPosition();
	SetTarget(sf::Vector2f(brickPos.x, screenSize.y));
}
