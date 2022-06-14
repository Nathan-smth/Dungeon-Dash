#include "TwoPlayerButton.h"
sf::Texture* TwoPlayerButton::twoPBTexture = nullptr;
TwoPlayerButton::TwoPlayerButton(int newWhichButton)
	: Buttons(newWhichButton)
{
	if (twoPBTexture == nullptr)
	{
		twoPBTexture = new sf::Texture();

		twoPBTexture->loadFromFile("Assets/Graphics/M2Button .png");
		buttonSprite.setTexture(*twoPBTexture);
	}
}

