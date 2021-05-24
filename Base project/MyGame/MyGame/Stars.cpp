#include "Stars.h"
#include "Explosion.h"
#include <chrono>
#include <thread>
#include "GameScene.h"



; const float SPEED = 0.2f;

Stars::Stars(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/star.png"));
	sprite_.setPosition(pos);
	assignTag("stars");
}

void Stars::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Stars::update(sf::Time& elapsed)
{
	int msElapsed = elapsed.asMilliseconds();
	sf::Vector2f pos = sprite_.getPosition();
	if (pos.x < sprite_.getGlobalBounds().width * -1)
	{	
		makeDead();
	}
	else
	{
		sprite_.setPosition(sf::Vector2f(pos.x - SPEED * msElapsed, pos.y));
	}
}