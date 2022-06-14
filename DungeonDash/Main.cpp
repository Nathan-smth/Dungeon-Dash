#include "Game.h"
int main()
{
    //seeding random number generator
    srand(time(NULL));
    Game ourGame;

    ourGame.Run();
    

    return 0;
}