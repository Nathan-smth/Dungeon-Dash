#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include"Background.h"
#include"Player.h"
#include"Buttons.h"
#include"Enemy.h"
#include"PowerUp.h"
#include"Bullet.h"

class Game
{
public:


	//Constructors
	Game();

	//deconstructors

	//functions
	void Run();
	void Draw();
	void Update();
	
	void SetScreen(std::string _whatScreen);
	void AddBullet(Bullet* bulletToAdd);
private:
	//functions
	void SetUpGame();
	void TitleScreen();
	void GameScreen();
	void MenuScreen();
	void SpawnEnemy();
	float getRandomNum(float upper,float lower);

	void SpawnPowerUp();

	void SetUpPlayers();

	void CreateGhost(int playerNum);

	void Reset();
	
			
	//data
	sf::RenderWindow window;
	sf::Clock gameClock;
	sf::Texture backGround;
	sf::Sprite objectSprite;
	
	//Background stuff data
	std::vector<Background*>	backgroundVector;
	std::string whatScreen;


	//player Data
	std::vector<Player*>	playerVector;
	sf::Vector2f player1Pos;
	sf::Vector2f player2Pos;
	int GameMode;
	std::vector<Player*>	ghostVector;


	//enemy Data

	std::vector<Enemy*> enemyVector;
	sf::Time timeSinceEnemy;
	int randomStuff;
	sf::Time spawnRateMultiplyer;
	float enemySpawnRate;


	//button Data
	std::vector<Buttons*> buttonVector;

	//power up Data 
	std::vector<PowerUp*> powerUpVector;
	sf::Time timeSincePowerUp;
	std::vector<Bullet*> bulletVector;

	sf::Text p1;
	sf::Text p2;

	sf::Text p1Score;
	sf::Text p2Score;

	sf::Text p1PowerUp;
	sf::Text p2PowerUp;

	sf::Text p1Time;
	sf::Text p2Time;

	sf::Time player1Time;
	sf::Time player2Time;

	sf::Text winner;

	sf::Font mainFont;


	bool gameModeChosen;

	//Ghost stuff

	bool isPlayerOneGhost;
	bool isPlayerTwoGhost;
	bool ghostHaveBeenCreated;


	sf::Time endScreenDisplayTime;
	float endScreenTimeLimit;

	sf::Time laserCoolDownTime;
	float lengthOfLaserCoolDown;
	bool canLaserSpawn;


	sf::Music gameMusic;

	sf::Sound hit;
	sf::Sound pickUpCoin;
	sf::Sound ghostHaunting;

   sf::SoundBuffer hitBuffer;
   sf::SoundBuffer pickUpCoinBuffer;
   sf::SoundBuffer ghostHauntingBuffer;

};

