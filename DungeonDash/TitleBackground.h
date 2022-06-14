#pragma once
#include"Background.h"
class TitleBackground :
    public Background
{
public:
    TitleBackground();


private:
    static sf::Texture* titleTexture;
};

