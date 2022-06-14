#pragma once
#include <SFML/Graphics.hpp>
class Background
{
public:

	//constructors
	Background();

	//deconstrutors

	//functions
	void setUpBackground(sf::Vector2f screenSize);
	void backgroundDraw(sf::RenderTarget& target);
	void titleScreen();
	void gameBackground();
	void MenuBackground();


	virtual void Update(sf::Time deltaTime);
protected:
	//data
	sf::Sprite BackgroundSprite;
	float scrollSpeed;


private:
	//data
	sf::Texture BackgroundTexture;
	
	sf::String	whatBackgroundTexture;

	
};

