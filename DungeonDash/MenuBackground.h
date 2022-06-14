#pragma once
#include "Background.h"
class MenuBackground :
    public Background
{
public:
    MenuBackground();


private:
    static sf::Texture* menuTexture;
};

