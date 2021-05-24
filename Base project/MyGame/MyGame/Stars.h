#pragma once

#include "Engine/GameEngine.h"
class Stars : public GameObject
{
public:
	// Creates our Meteor.
	Stars(sf::Vector2f pos);
	// Functions overridden from GameObject:
	void draw();
	void update(sf::Time& elapsed);
private:
	sf::Sprite sprite_;
};
typedef std::shared_ptr<Stars> StarsPtr;