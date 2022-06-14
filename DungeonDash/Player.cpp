#include "Player.h"
#include "PowerUp.h"
#include "Bullet.h"
#include "Game.h"

Player::Player(int NewPlayerNum,Game* newGame)
	:	AnimatingObject			()
	,	moveSpeed				(600.f)
	,	accelerationRate		(200.0f)
	,	playerAcceleration		(0,0)
	,	drag					(0.003f)
	,	jumpSpeed				(1.0f)
	,	gravity					(400.0f)
	,	BOTGAP					(200)
	,	playerNum				(NewPlayerNum)
	,	playerVelocity			(0,0)
	,	isJumping				(false)
	,	jumpHeight				(100.0f)
	,	fireingOffSet			(0,0)
	,	myGame					(newGame)
	,	score					(0)
	,	timeSinceUsedAbility	()
	,	spikeShoePowerLength	(5)
	,	howManyHits				(0)
	,	brokenWatchPowerLength	(10)
	,	oldDrinkPowerLength		(5)
	,	isAGhost				(false)
	,	hauntOffCoolDown		(true)
	,	timeSinceHauntUsed		()
	,	coolDownTime			()
	,	haunttTimeLength		(3)
	,	coolDownTimeLength		(15)
	,	controlsInverted		(false)
	,	cantMoveRight			(false)
	,	cantMoveLeft			(false)
	,	onGround				(false)
	,	cantJumpHigher			(false)
	,	playHit					(false)
	,	playCoinSound			(false)
	,	playGhostSound			(false)


{

	

	playerAcceleration.y = gravity;
}

void Player::Update(sf::Time deltaTime)
{
	
	Input();

	IncreaseScore();

	AnimatingObject::Update(deltaTime);

	


	if (currentPowerUp == "ActiveSpikeShoe")
	{
		timeSinceUsedAbility += deltaTime;
		if (timeSinceUsedAbility.asSeconds() >= spikeShoePowerLength)
		{
			SetCurrentPowerUp(  "");

			timeSinceUsedAbility = sf::Time();
		}
	}

	if (currentPowerUp == "ActiveBrokenWatch")
	{
		timeSinceUsedAbility += deltaTime;
		if (timeSinceUsedAbility.asSeconds() >= brokenWatchPowerLength)
		{
			SetCurrentPowerUp("");

			timeSinceUsedAbility = sf::Time();
		}
	}

	if (currentPowerUp == "ActiveOldDrink")
	{
		timeSinceUsedAbility += deltaTime;
		if (timeSinceUsedAbility.asSeconds() >= oldDrinkPowerLength)
		{
			SetCurrentPowerUp("");

			timeSinceUsedAbility = sf::Time();
		}
	}

	if (position.y >= sf::VideoMode::getDesktopMode().height - 60 - BOTGAP)
	{
		onGround = true;
		
		position.y = sf::VideoMode::getDesktopMode().height - 60 - BOTGAP;
		
	}

	if (position.y <= sf::VideoMode::getDesktopMode().height / 3 - 70)
	{
		
		cantJumpHigher = true;
	}
	else
	{
		cantJumpHigher = false;
	}

	if (onGround == true)
	{
		playerAcceleration.y = 0;
		playerVelocity.y = 0;
		onGround = false;
	}
	else
	{
		//doing gravity and stuff
		playerAcceleration.y = gravity ;
	}




	if (position.x <= 0)
	{
		cantMoveLeft = true;
	}
	else
	{
		cantMoveLeft = false;
	}

	if (position.x >= sf::VideoMode::getDesktopMode().width-50)
	{
		cantMoveRight = true;
	}
	else
	{
		cantMoveRight = false;
	}

	
	sf::Vector2f deltaVelocity;
	
	float MoveDeltaTime = deltaTime.asSeconds();
	sf::Vector2f deltaPosition;

	deltaVelocity = playerAcceleration * MoveDeltaTime;

	playerVelocity = playerVelocity + deltaVelocity;

	//Change in velocity due to drag 
	playerVelocity.x = playerVelocity.x - playerVelocity.x * drag;


	deltaPosition = playerVelocity * MoveDeltaTime;
	position = position + deltaPosition;
	

	SetVelocity(playerVelocity);


	///
	///
	/// Ghost time
	/// 
	/// 

	if (isAGhost == true)
	{

		
		if (currentPowerUp == "ActiveGhostlyHaunting")
		{
			timeSinceHauntUsed += deltaTime;
			if (timeSinceHauntUsed.asSeconds() >= haunttTimeLength)
			{
				SetCurrentPowerUp("");

				timeSinceUsedAbility = sf::Time();
				hauntOffCoolDown = false;
			}
		}
		else if(hauntOffCoolDown == true)
		{
			currentPowerUp = "GhostlyHaunting";
		}
			



				if (currentPowerUp == "" && hauntOffCoolDown == false)
				{
					coolDownTime += deltaTime;
					if (coolDownTime.asSeconds() >= coolDownTimeLength)
					{
						coolDownTime = sf::Time();
						hauntOffCoolDown = true;
					}
				}
			


		
	}

}

void Player::SetCurrentPowerUp(std::string _currentPowerUp)
{
	currentPowerUp = _currentPowerUp;
}

void Player::HandelCollistion(PowerUp* target)
{
	sf::FloatRect playerCollider = GetCollider();
	sf::FloatRect powerUpCollider = target->GetCollider();

	if (playerCollider.intersects(powerUpCollider)&&GetCurrentPowerUp()=="")
	{
		target->TakeDamage(100);
		SetCurrentPowerUp(target->GetPowerUpName());

		
	}
	else if (playerCollider.intersects(powerUpCollider) && target->GetPowerUpName() == "Coin")
	{
		target->TakeDamage(100);
		SetCurrentPowerUp(target->GetPowerUpName());
		//PlayPickUpCoin();

	}

}

void Player::HandelPlayerCollistion(Player* target)
{

	sf::FloatRect currentplayerCollider = GetCollider();
	sf::FloatRect otherPlayerCollider = target->GetCollider();

	if (currentplayerCollider.intersects(otherPlayerCollider))
	{
		if (currentPowerUp == "ActiveSpikeShoe"&&target->GetCurrentPowerUp()!="ActiveSpikeShoe"&&howManyHits<4)
		{
			howManyHits++;
			target->SubtractScore(40);
		}


	}
	
}

int Player::GetPlayerNum()
{
	return playerNum;
}

void Player::SetScore(int _currentScore)
{
	score = _currentScore;
}

int Player::GetScore()
{
	return score;
}

std::string Player::GetCurrentPowerUp()
{
	return currentPowerUp;
}

void Player::SubtractScore(int amount)
{
	score -= amount;
}

void Player::SetSpeed(float newSpeed)
{
	moveSpeed=newSpeed;
}

void Player::Reset()
{
	currentHealth = 100;
	score = 0;
	currentPowerUp = "";
}

void Player::IsAGhost(std::string isIt)
{
	if (isIt == "Yes")
	{
		isAGhost = true;
	}
	else
	{
		isAGhost = false;
	}
	
}

void Player::IsControlsInverted(bool isIt)
{
	controlsInverted = isIt;
}

void Player::SetYAcceleration(float y)
{
	playerAcceleration.y = y;
}

void Player::SetYVelocity(float y)
{
	playerVelocity.y = y;
}

void Player::SetOnGround(float _onGround)
{
	onGround = _onGround;
}

bool Player::GetOnGround()
{
	return onGround;
}

void Player::SetPlayHit(bool hit)
{
	playHit = hit;
}

void Player::SetPlayCoin(bool pickUpCoin)
{
	playCoinSound = pickUpCoin;
}

void Player::SetPlayGhost(bool GhoustHaunting)
{
	playGhostSound = GhoustHaunting;
}

bool Player::GetPlayHit()
{
	return playHit;
}

bool Player::GetPlayCoin()
{
	return playCoinSound;
}

bool Player::GetPlayGhostt()
{
	return playGhostSound;
}





void Player::Move(sf::Vector2f direction)
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

void Player::Fire(sf::Vector2f _moveDirection)
{

	sf::Vector2f moveDir = _moveDirection;
	float fireDirection = moveDir.x;


	//create a bullet 

	Bullet* newBullet = new Bullet(playerNum, fireDirection,this);



	

	//give the bullet to the game to manage

	myGame->AddBullet(newBullet);



}

void Player::IncreaseScore()
{
	if (currentPowerUp == "Coin")
	{
		SetScore(score + 100);
		SetCurrentPowerUp("");
		SetPlayCoin(true);
	}
	else
	{
		SetPlayCoin(false);
	}

	
}



void Player::Input()
{
	sf::Vector2f moveDirection(0, 0);

	const int PLAYER_ONE = 1;
	const int PLAYER_TWO = 2;

	int whichPlayer = playerNum;

	switch (whichPlayer)
	{
	case PLAYER_ONE:
		if (controlsInverted == true)
		{
			//left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&cantMoveLeft==false)
			{
				moveDirection.x = -1.0f;
			}

			//right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && cantMoveRight == false)
			{
				moveDirection.x = 1.0f;
			}

			//jump

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && cantJumpHigher == false)
			{



				moveDirection.y = -jumpSpeed;



			}
		}
		else
		{
			//left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && cantMoveLeft == false)
			{
				moveDirection.x = -1.0f;
			}

			//right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && cantMoveRight == false)
			{
				moveDirection.x = 1.0f;
			}

			//jump

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && cantJumpHigher == false)
			{



				moveDirection.y = -jumpSpeed;



			}
		}
		
		
		




		/// <summary>
		/// 
		/// Power Up stuff :D
		/// 
		/// </summary>
	
		if (currentPowerUp == "Pistol")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				Fire(moveDirection);
				SetCurrentPowerUp("");
			}
		}

		if (currentPowerUp == "SpikeShoe")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				SetCurrentPowerUp ( "ActiveSpikeShoe");
			}
		}


		if (currentPowerUp == "BrokenWatch")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				SetCurrentPowerUp("ActiveBrokenWatch");
			}
		}

		if (currentPowerUp == "OldDrink")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				SetCurrentPowerUp("ActiveOldDrink");
			}
		}

		if (currentPowerUp == "GhostlyHaunting")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
			{
				SetPlayGhost(true);
				SetCurrentPowerUp("ActiveGhostlyHaunting");
				
			}
		}

		break;

	case PLAYER_TWO:
		
		if (controlsInverted == true)
		{
			//left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && cantMoveLeft == false)
			{
				moveDirection.x = -1.0f;
			}

			//right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && cantMoveRight == false)
			{
				moveDirection.x = 1.0f;
			}

			//jump

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)&& cantJumpHigher==false)
			{
				moveDirection.y = -jumpSpeed;
			}
		}
		else
		{
			//left
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && cantMoveLeft == false)
			{
				moveDirection.x = -1.0f;
			}

			//right
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && cantMoveRight == false)
			{
				moveDirection.x = 1.0f;
			}

			//jump

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && cantJumpHigher == false)
			{
				moveDirection.y = -jumpSpeed;
			}
		}
		
		




		/// <summary>
		/// 
		/// Power Up stuff :D
		/// 
		/// </summary>

		if (currentPowerUp == "Pistol")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{

				Fire(moveDirection);
				SetCurrentPowerUp("");
			}
		}

		if (currentPowerUp == "SpikeShoe")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				SetCurrentPowerUp("ActiveSpikeShoe");
			}
		}

		if (currentPowerUp == "BrokenWatch")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				SetCurrentPowerUp("ActiveBrokenWatch");
			}
		}

		if (currentPowerUp == "OldDrink")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				SetCurrentPowerUp("ActiveOldDrink");
			}
		}

		if (currentPowerUp == "GhostlyHaunting")
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4))
			{
				SetPlayGhost(true);
				SetCurrentPowerUp("ActiveGhostlyHaunting");
			}
		}

		break;

	}
	Move(moveDirection);

}
