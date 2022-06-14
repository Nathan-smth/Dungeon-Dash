#include "Text.h"
sf::Font* Text::myFont = nullptr;

Text::Text(std::string newWhatIsDisplayed)
	:	myText			()
	,	wordsInText		()
	,	whatIsDisplayed	()
	,	position		(0,0)
{
	if (myFont == nullptr)
	{
		myFont = new sf::Font();
		myFont->loadFromFile("Assets/Fonts/Minecraft.ttf");


		myText.setFont(*myFont);
	}

	
	myText.setFillColor(sf::Color::White);
	myText.setCharacterSize(25);
	
}

void Text::Update(sf::Time delaTime)
{
	myText.setString(wordsInText);
}

void Text::SetUpText(std::string _wordsInText)
{
	wordsInText = _wordsInText;
}

std::string Text::GetWhatIsDisplayed()
{
	return whatIsDisplayed;
}

void Text::SetPosition(sf::Vector2f _position)
{
	position = _position;
	myText.setPosition(position);
}

void Text::Draw(sf::RenderTarget& target)
{
	target.draw(myText);
	
}


