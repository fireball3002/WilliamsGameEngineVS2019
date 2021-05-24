#pragma once

#include "Engine/GameEngine.h"

class Background : public GameObject
{
public:
	// Creates our ship.
	Background();
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite1;
	sf::Sprite sprite2;
	int fireTimer_ = 0;
};
typedef std::shared_ptr<Background> BackgroundPtr;
