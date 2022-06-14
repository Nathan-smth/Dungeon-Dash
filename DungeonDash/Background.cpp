#include "Background.h"

Background::Background()
	:	BackgroundTexture		()
	,	BackgroundSprite		()
	,	whatBackgroundTexture	()
	,	scrollSpeed				(150)
	

{
	
}

void Background::setUpBackground(sf::Vector2f screenSize)
{

	//sf::Vector2f spriteSize;
	//spriteSize.x = screenSize.x / 515;
	//spriteSize.y = screenSize.y / 527;
	//BackgroundSprite.setScale(spriteSize.x,spriteSize.y);
}

void Background::backgroundDraw(sf::RenderTarget& target)
{
	target.draw(BackgroundSprite);
}

void Background::titleScreen()
{
	BackgroundTexture.loadFromFile("Assets/Graphics/Title.png");
	BackgroundSprite.setTexture(BackgroundTexture);
	

}

void Background::gameBackground()
{
	BackgroundTexture.loadFromFile("Assets/Graphics/wall.png");
	BackgroundSprite.setTexture(BackgroundTexture);
}

void Background::MenuBackground()
{
	BackgroundTexture.loadFromFile("Assets/Graphics/Menu.png");
	BackgroundSprite.setTexture(BackgroundTexture);
}

void Background::Update(sf::Time deltaTime)
{

}
