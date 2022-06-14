#pragma once
#include "GameObject.h"
#include    "Animation.h"
class AnimatingObject :
    public GameObject
{

public:
    AnimatingObject();

    Animation* CreateAnimation(std::string name);


    void Play();
    void Play(std::string newAnimation);
    void Pause();
    void Stop();

    virtual void Update(sf::Time frameTime) override;

private:
    std::map<std::string, Animation> animations;
    Animation* currentAnimation;
};

