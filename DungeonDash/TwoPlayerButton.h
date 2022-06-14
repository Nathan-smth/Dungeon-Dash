#pragma once
#include "Buttons.h"
class TwoPlayerButton :
    public Buttons
{
public:
    TwoPlayerButton(int newWhichButton);
private:
    static sf::Texture* twoPBTexture;
};

