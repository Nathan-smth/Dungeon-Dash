#include "Shaun.h"
sf::Texture* Shaun::PlayerTexture = nullptr;
sf::Texture* Shaun::PlayerRunFrame1Texture = nullptr;
sf::Texture* Shaun::PlayerRunFrame2Texture = nullptr;
sf::Texture* Shaun::PlayerRunFrame3Texture = nullptr;
sf::Texture* Shaun::PlayerRunFrame4Texture = nullptr;
sf::Texture* Shaun::PlayerRunFrame5Texture = nullptr;
sf::Texture* Shaun::PlayerRunFrame6Texture = nullptr;

Shaun::Shaun(int newPlayerNum, Game* newGame)
	:	Player	(newPlayerNum, newGame)
{
	if (PlayerTexture == nullptr)
	{
		PlayerTexture = new sf::Texture();

		PlayerTexture->loadFromFile("Assets/Graphics/Shaun.png");
		
	}

	if (PlayerRunFrame1Texture == nullptr)
	{
		PlayerRunFrame1Texture = new sf::Texture();

		PlayerRunFrame1Texture->loadFromFile("Assets/Graphics/ShaunAniFrame1.png");
	
	}

	if (PlayerRunFrame2Texture == nullptr)
	{
		PlayerRunFrame2Texture = new sf::Texture();

		PlayerRunFrame2Texture->loadFromFile("Assets/Graphics/ShaunAniFrame2.png");
		
	}

	if (PlayerRunFrame3Texture == nullptr)
	{
		PlayerRunFrame3Texture = new sf::Texture();

		PlayerRunFrame3Texture->loadFromFile("Assets/Graphics/ShaunAniFrame3.png");
		
	}

	if (PlayerRunFrame4Texture == nullptr)
	{
		PlayerRunFrame4Texture = new sf::Texture();

		PlayerRunFrame4Texture->loadFromFile("Assets/Graphics/ShaunAniFrame4.png");
		
	}

	if (PlayerRunFrame5Texture == nullptr)
	{
		PlayerRunFrame5Texture = new sf::Texture();

		PlayerRunFrame5Texture->loadFromFile("Assets/Graphics/ShaunAniFrame5.png");
	
	}

	if (PlayerRunFrame6Texture == nullptr)
	{
		PlayerRunFrame6Texture = new sf::Texture();

		PlayerRunFrame6Texture->loadFromFile("Assets/Graphics/ShaunAniFrame6.png");
		
	}

	//objectSprite.setTexture(*PlayerTexture);


	Animation* Run = CreateAnimation("ShaunRun");
	Run->AddFrame(PlayerRunFrame1Texture);
	Run->AddFrame(PlayerRunFrame2Texture);
	Run->AddFrame(PlayerRunFrame3Texture);
	Run->AddFrame(PlayerRunFrame4Texture);
	Run->AddFrame(PlayerRunFrame5Texture);
	Run->AddFrame(PlayerRunFrame6Texture);
	Run->SetPlayBackSpeed(8);
	Run->SetLoop(true);

	Play("ShaunRun");

}
