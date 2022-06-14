#pragma once
#include "Buttons.h"
class TitleButton :
    public Buttons
{
public:
    TitleButton(int newWhichButton);

private:
    static sf::Texture* titleBTexture;
};

