#pragma once
#include "Background.h"
class EndScreen :
    public Background
{
public:
    EndScreen();

private:
    static sf::Texture* endScreenTexture;
};

