#include "EndScreen.h"
sf::Texture* EndScreen::endScreenTexture = nullptr;
EndScreen::EndScreen()
	:	Background	()
{

	if (endScreenTexture == nullptr)
	{
		endScreenTexture = new sf::Texture();

		endScreenTexture->loadFromFile("Assets/Graphics/Menu.png");
		BackgroundSprite.setTexture(*endScreenTexture);
	}

	BackgroundSprite.setScale(3.8, 2);

}
