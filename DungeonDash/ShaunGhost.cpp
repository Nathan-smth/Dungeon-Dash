#include "ShaunGhost.h"
sf::Texture* ShaunGhost::shaunGTexture = nullptr;
ShaunGhost::ShaunGhost(int newPlayerNum, Game* newGame)
	:	Player	(newPlayerNum,newGame)
{
	if (shaunGTexture == nullptr)
	{
		shaunGTexture = new sf::Texture();

		shaunGTexture->loadFromFile("Assets/Graphics/Player1Ghost.png");
		objectSprite.setTexture(*shaunGTexture);
	}

}
