#pragma once
#include <SFML/Graphics.hpp>

class Buttons
{
public:
	//construtors
	Buttons(int newWhichButton);
	
	//functions
	virtual void Update(sf::Time deltaTime);
	std::string	getScreenResult();
	void Draw(sf::RenderTarget& target);

	void TitleButtton();
	void MenuButton();

	void SetPosition(sf::Vector2f _position);

protected:
	//data 
	std::string userInput;
	sf::Sprite buttonSprite;


private:

	//function
	
	void UserInput();
	

	//data
	
	
	int whichButton;
	int highlightedButton;
	sf::Vector2f position;
};

