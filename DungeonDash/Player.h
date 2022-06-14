#pragma once
#include "AnimatingObject.h"
#include <SFML/Audio.hpp>
class PowerUp;
class Game;
class Player :
    public AnimatingObject
{
public:
    //constructors 
    Player(int newPlayerNum,Game* newGame);

    //deconstructors


    //functions
    virtual void Update(sf::Time deltaTime) override;

    void SetCurrentPowerUp(std::string _currentPowerUp);

    void HandelCollistion(PowerUp* target);

    void HandelPlayerCollistion(Player* target);

    int GetPlayerNum();

   

    void SetScore(int _currentScore);
    int GetScore();

    std::string GetCurrentPowerUp();

    void SubtractScore(int amount);

    void SetSpeed(float newSpeed);

    void Reset();

    void IsAGhost(std::string isIt);
    
    void IsControlsInverted(bool isIt);

    void SetYAcceleration(float y);
    void SetYVelocity(float y);
    void SetOnGround(float _onGround);
    bool GetOnGround();
    
    void SetPlayHit(bool hit);
    void SetPlayCoin(bool pickUpCoin);
    void SetPlayGhost(bool GhoustHaunting);

    bool GetPlayHit();
    bool GetPlayCoin();
    bool GetPlayGhostt();



protected:

    //function
    void Move(sf::Vector2f direction);


    //data
    float moveSpeed;
    float accelerationRate;
    sf::Vector2f playerAcceleration;
    float drag;
    float jumpSpeed;
    float gravity;



    float BOTGAP;

    int score;


    void Fire(sf::Vector2f _moveDirection);
    void IncreaseScore();


  
private:

    //private functions
    void Input();

  
    int playerNum;
    
    sf::Vector2f playerVelocity;
    bool isJumping;
    float jumpHeight;
    std::string currentPowerUp;

    sf::Vector2f fireingOffSet;
    Game* myGame;

    sf::Time timeSinceUsedAbility;
    float spikeShoePowerLength;
    int howManyHits;
    float brokenWatchPowerLength;
    float oldDrinkPowerLength;

    bool isAGhost;
    bool hauntOffCoolDown;
    sf::Time timeSinceHauntUsed;
    sf::Time coolDownTime;
    float haunttTimeLength;
    float coolDownTimeLength;

    bool controlsInverted;
    bool cantMoveRight;
    bool cantMoveLeft;
    bool onGround;
    bool cantJumpHigher;

    bool playHit;
    bool playCoinSound;
    bool playGhostSound;


   
};

