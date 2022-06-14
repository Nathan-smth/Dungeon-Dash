#pragma once
#include "Player.h"
class Game;
class ShaunGhost :
    public Player
{
public:
    ShaunGhost(int newPlayerNum, Game* newGame);



private:
    //data 
    static sf::Texture* shaunGTexture;
};

