#include "GameBackground.h"
sf::Texture* GameBackground::gameTexture = nullptr;

GameBackground::GameBackground()
	: Background()
{


	if (gameTexture == nullptr)
	{
		gameTexture = new sf::Texture();

		gameTexture->loadFromFile("Assets/Graphics/GameScreen.png");
		BackgroundSprite.setTexture(*gameTexture);
	}

	BackgroundSprite.setScale(2, 1.28);
}

void GameBackground::Update(sf::Time deltaTime)
{
	SetPosition(position + velocity * deltaTime.asSeconds());
	Background::Update( deltaTime);
	sf::Vector2f direction(-1, 0);

	if (position.x <= -((float)gameTexture->getSize().x / 4))
	{
		position=sf::Vector2f(0,0);
	}
	else
	{
		Move(direction);
	}


	


}

void GameBackground::SetVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void GameBackground::SetPosition(sf::Vector2f _position)
{
	position = _position;
	BackgroundSprite.setPosition(position);
}

sf::Vector2f GameBackground::GetPosition()
{
	return position;
}


void GameBackground::Move(sf::Vector2f direction)
{
	float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);

	if (magnitude == 0)
	{
		SetVelocity(sf::Vector2f(0, 0));
	}
	else
	{
		sf::Vector2f directionNorm = direction / magnitude;

		SetVelocity(directionNorm * scrollSpeed);

	}
}

