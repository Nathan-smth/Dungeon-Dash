#pragma once
#include "Player.h"
class Game;
class JohnGhost :
    public Player
{
public: 
    JohnGhost(int neewPlayerNum, Game* newGame);


private:
    //data 
    static sf::Texture* johnGTexture;
};

