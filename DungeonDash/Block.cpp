#include "Block.h"
#include	"Player.h"
sf::Texture* Block::blockTexture = nullptr;
Block::Block(sf::Vector2f newScreenSize, std::string newWhereSpawn)
	: Enemy	(newScreenSize, newWhereSpawn)
	, onTop	(false)
	, onSide (false)
{

	if (blockTexture == nullptr)
	{
		blockTexture = new sf::Texture();
		blockTexture->loadFromFile("Assets/Graphics/Block.png");
	}

	objectSprite.setTexture(*blockTexture);
}

void Block::HandelCollistion(Player* target)
{
	sf::FloatRect blockCollider = GetCollider();
	sf::FloatRect playerCollider = target->GetCollider();

	if (blockCollider.intersects(playerCollider))
	{

		sf::Vector2f depth = CollisionDepth(playerCollider, blockCollider);
		sf::Vector2f absDepth = sf::Vector2f(abs(depth.x), abs(depth.y));
		sf::Vector2f normal;

		if (absDepth.x < absDepth.y)
		{
			sf::Vector2f playerPos = target->GetPosition();
			playerPos.x += depth.x;
			target->SetPosition(playerPos);

			if (depth.x > 0)
			{
				normal = sf::Vector2f(-1, 0);
				onSide = true;
			}
			else
			{
				normal = sf::Vector2f(1, 0);
				onSide = true;
			}

		}
		else
		{
			sf::Vector2f playerPos = target->GetPosition();
			playerPos.y += depth.y;
			target->SetPosition(playerPos);

			if (depth.y > 0)
			{
					normal = sf::Vector2f(0, 1);
			}
			else
			{
				onTop = true;
			}
		}

		if (onTop == false)
		{
			sf::Vector2f playerVelocity = target->GetVelocity();
			sf::Vector2f newPlayerVelocity;

			newPlayerVelocity = playerVelocity - 2.0f * normal * (VectorDot(playerVelocity, normal));
		}
		else if (onTop==true&& onSide==false)
		{
			bool onGround = true;
			target->SetOnGround(onGround);
		
			
		}
		
	}
}

void Block::AI()
{
	sf::Vector2f blockPos = GetPosition();
	SetTarget(sf::Vector2f(-50, blockPos.y));
}

sf::Vector2f Block::CollisionDepth(sf::FloatRect a, sf::FloatRect b)
{
	
		//width nad height of each rect 
		sf::Vector2f aWH = sf::Vector2f(a.width, a.height);
		sf::Vector2f bWH = sf::Vector2f(b.width, b.height);


		//centre point for each rect
		sf::Vector2f aCentre = sf::Vector2f(a.left, a.top) + 0.5f * aWH;
		sf::Vector2f bCentre = sf::Vector2f(b.left, b.top) + 0.5f * bWH;

		sf::Vector2f distance = aCentre - bCentre;
		sf::Vector2f minDisatnce = 0.5f * aWH + 0.5f * bWH;

		//account for directon of collision
		if (distance.x < 0)
			minDisatnce.x = -minDisatnce.x;
		if (distance.y < 0)
			minDisatnce.y = -minDisatnce.y;

		sf::Vector2f depth = minDisatnce - distance;

		return depth;
	
}

float Block::VectorDot(sf::Vector2f a, sf::Vector2f b)
{
	return  a.x * b.x + a.y * b.y;
}
