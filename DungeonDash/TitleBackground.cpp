#include "TitleBackground.h"
sf::Texture* TitleBackground::titleTexture = nullptr;

TitleBackground::TitleBackground()
	:	Background	()
{

	if (titleTexture == nullptr)
	{
		titleTexture = new sf::Texture();

		titleTexture->loadFromFile("Assets/Graphics/Title.png");
		BackgroundSprite.setTexture(*titleTexture);
	}

	BackgroundSprite.setScale(3.8, 2);
}
