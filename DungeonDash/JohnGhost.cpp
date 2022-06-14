#include "JohnGhost.h"
sf::Texture* JohnGhost::johnGTexture = nullptr;

JohnGhost::JohnGhost(int newPlayerNum, Game* newGame)
	:	Player	(newPlayerNum, newGame)
{
	if (johnGTexture == nullptr)
	{
		johnGTexture = new sf::Texture();

		johnGTexture->loadFromFile("Assets/Graphics/Player2Ghost.png");
		objectSprite.setTexture(*johnGTexture);
	}
}
