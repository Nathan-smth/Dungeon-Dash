#pragma once
#include <vector>
#include <SFML/Graphics.hpp>


class Animation
{
public:

	Animation();

	void AddFrame(sf::Texture* newFrame);
	void SetSprite(sf::Sprite* newSprite);
	void SetPlayBackSpeed(float newPlayBackSpeed);
	void SetLoop(bool newLoop);
	bool GetPlaying();


	void Update(sf::Time frameTime);
	void Play();
	void Pause();
	void Stop();

private:

	std::vector<sf::Texture*> frames;
	sf::Sprite* sprite;
	float playBackSpeed;
	bool loop;


	sf::Time nextFrameChange;
	int currentFrame;
	bool playing;
};

