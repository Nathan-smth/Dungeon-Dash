#include "GameObject.h"

GameObject::GameObject()
	:	objectSprite	()
	,	position		(0,0)
	,	velocity		(0,0)
	,	moveSpeed		(0.0f)
	,	maxHealth		(100)
	,	currentHealth	(100)

{
}

void GameObject::Draw(sf::RenderTarget& target)
{
	target.draw(objectSprite);
}

void GameObject::Update(sf::Time deltaTime)
{
	SetPosition(position + velocity * deltaTime.asSeconds());
}

void GameObject::SetVelocity(sf::Vector2f _velocity)
{
	velocity = _velocity;
}

void GameObject::SetPosition(sf::Vector2f _position)
{
	position = _position;
	objectSprite.setPosition(position);
}

void GameObject::TakeDamage(int damage)
{
	currentHealth = -damage;
}

void GameObject::SetHealth(int heal)
{
	currentHealth + heal;
}

sf::Vector2f GameObject::GetPosition()
{
	return position;
}

sf::Vector2f GameObject::GetVelocity()
{
	return velocity;
}

sf::FloatRect GameObject::GetCollider()
{
	return objectSprite.getGlobalBounds();
}

bool GameObject::IsAlive()
{
	return currentHealth>0;
}

void GameObject::Move(sf::Vector2f direction)
{
	float magnitude = sqrtf(direction.x * direction.x + direction.y * direction.y);

	if (magnitude == 0)
	{
		SetVelocity(sf::Vector2f(0, 0));
	}
	else
	{
		sf::Vector2f directionNorm = direction / magnitude;

		SetVelocity(directionNorm * moveSpeed);

	}
}
