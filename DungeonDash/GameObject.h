#pragma once
#include <SFML/Graphics.hpp>
class GameObject
{

public:
	//construtors 
	GameObject();

	//deconstructors

	//functions

	void Draw(sf::RenderTarget& target);
	virtual void Update(sf::Time deltaTime);
	
	//setters
	void SetVelocity(sf::Vector2f _velocity);
	void SetPosition(sf::Vector2f _position);
	void TakeDamage(int damage);
	void SetHealth(int heal);


	//getters
	sf::Vector2f GetPosition();
	sf::Vector2f GetVelocity();
	sf::FloatRect	GetCollider();
	bool IsAlive();


protected:
	//data 
	sf::Sprite	objectSprite;
	sf::Vector2f position;
	sf::Vector2f velocity;
	float moveSpeed;
	int maxHealth;
	int currentHealth;

	void Move(sf::Vector2f direction);

private:
	//data
	
};

