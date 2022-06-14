#include "Buttons.h"

Buttons::Buttons(int newWhichButton)
	:	buttonSprite		()
	,	userInput			()
	,	whichButton			(newWhichButton)
	,	highlightedButton	(2)
	,	position			()
{
}

void Buttons::Update(sf::Time deltaTime)
{
	//UserInput();
}

std::string Buttons::getScreenResult()
{
	std::string screenMode;

	//check which button was pressed then change and return the acording screen.

	if (whichButton == 1)
	{
		screenMode = "Menu";
	}
	else if (whichButton == 2)
	{
		screenMode = "Game";
	}
	else if (whichButton == 3)
	{
		screenMode = "Game";
	
	}


	return screenMode;
}

void Buttons::Draw(sf::RenderTarget& target)
{
		target.draw(buttonSprite);
	
}

void Buttons::TitleButtton()
{
	

	sf::Vector2f spriteSize;
	spriteSize.x =	6;
	spriteSize.y = 3;
	buttonSprite.setScale(spriteSize.x,spriteSize.y);


}

void Buttons::MenuButton()
{
	
		
		
	
	
	sf::Vector2f spriteSize;
	spriteSize.x = 6;
	spriteSize.y = 3;
	buttonSprite.setScale(spriteSize.x, spriteSize.y);
}

void Buttons::SetPosition(sf::Vector2f _position)
{
	position = _position;
	buttonSprite.setPosition(position);
}

void Buttons::UserInput()
{
	 //this didnt work :( 

	/// 1 = Title screen button
	/// 2 = 1 player menu button 
	/// 3 = 2 player menu button
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//{
	//	if (highlightedButton == whichButton)
	//	{

	//	}
	//	else if (highlightedButton==3 && whichButton==3)
	//	{
	//		highlightedButton = 2;
	//	}
	//}

	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//{
	//	if (highlightedButton == whichButton)
	//	{

	//	}
	//	else if (highlightedButton == 2 && whichButton == 2)
	//	{
			//highlightedButton = 3;
	//	}
	//}
//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
//	{
//		getScreenResult();
//	}
}
