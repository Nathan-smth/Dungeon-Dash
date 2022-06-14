#include "TitleButton.h"
sf::Texture* TitleButton::titleBTexture = nullptr;
TitleButton::TitleButton(int newWhichButton)
	:	Buttons	(newWhichButton)
{
	if (titleBTexture == nullptr)
	{
		titleBTexture = new sf::Texture();

		titleBTexture->loadFromFile("Assets/Graphics/TButton.png");
		buttonSprite.setTexture(*titleBTexture);
	}
}
