#include "OnePlayerButton.h"
sf::Texture* OnePlayerButton::OnePBTexture = nullptr;
OnePlayerButton::OnePlayerButton(int newWhichButton)
	: Buttons (newWhichButton)
{
	if (OnePBTexture == nullptr)
	{
		OnePBTexture = new sf::Texture();

		OnePBTexture->loadFromFile("Assets/Graphics/M1Button.png");
		buttonSprite.setTexture(*OnePBTexture);
	}
}
