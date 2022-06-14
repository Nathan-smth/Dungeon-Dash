#pragma once
#include <SFML/Graphics.hpp>
class Text
{
public:
	Text(std::string newWhatIsDisplayed);
	virtual void Update(sf::Time delaTime);

	void SetUpText(std::string _wordsInText);


	std::string GetWhatIsDisplayed();

	void SetPosition(sf::Vector2f _position);

	void Draw(sf::RenderTarget& target);
protected:



private:
	sf::Text myText;
	std::string wordsInText;
	static sf::Font* myFont;
	std::string whatIsDisplayed;
	sf::Vector2f position;

};

