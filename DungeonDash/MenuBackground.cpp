#include "MenuBackground.h"
sf::Texture* MenuBackground::menuTexture = nullptr;

MenuBackground::MenuBackground()
	: Background()
{


	if (menuTexture == nullptr)
	{
		menuTexture = new sf::Texture();

		menuTexture->loadFromFile("Assets/Graphics/Menu.png");
		BackgroundSprite.setTexture(*menuTexture);
	}


	BackgroundSprite.setScale(3.8, 2);
}
