#pragma once
#include "Buttons.h"
class OnePlayerButton :
    public Buttons
{
public:
    OnePlayerButton(int newWhichButton);
private:

    static sf::Texture* OnePBTexture;
};

