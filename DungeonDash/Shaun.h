#pragma once
#include "Player.h"
class Game;
class Shaun :
    public Player
{
public:
    Shaun(int newPlayerNum, Game* newGame);


private:

    //data
    static sf::Texture* PlayerTexture;
    static sf::Texture* PlayerRunFrame1Texture;
    static sf::Texture* PlayerRunFrame2Texture;
    static sf::Texture* PlayerRunFrame3Texture;
    static sf::Texture* PlayerRunFrame4Texture;
    static sf::Texture* PlayerRunFrame5Texture;
    static sf::Texture* PlayerRunFrame6Texture;
};

