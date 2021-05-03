#include "Meteor.h"

; const float SPEED = 0.25f;

Meteor::Meteor(sf::Vector2f pos)
{
	setCollisionCheckEnabled(true);
	sprite_.setTexture(GAME.getTexture("Resources/meteor.png"));
	sprite_.setPosition(pos);
	assignTag("meteor");
}

void Meteor::draw()
{
	GAME.getRenderWindow().draw(sprite_);
}

void Meteor::update(sf::Time& elapsed) 
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
sf::FloatRect Meteor::getCollisionRect()
{
	return sprite_.getGlobalBounds();
}

void Meteor::handleCollision(GameObject& otherGameObject)
{
	if (otherGameObject.hasTag("laser"))
	{
		otherGameObject.makeDead();
	}
	sprite_.setTexture(GAME.getTexture("Resources/explosion01.png"));
	GAME.getRenderWindow().draw(sprite_);
	sprite_.setTexture(GAME.getTexture("Resources/explosion02.png"));
	GAME.getRenderWindow().draw(sprite_);
	sprite_.setTexture(GAME.getTexture("Resources/explosion03.png"));
	sprite_.setTexture(GAME.getTexture("Resources/explosion04.png"));
	sprite_.setTexture(GAME.getTexture("Resources/explosion05.png"));
	sprite_.setTexture(GAME.getTexture("Resources/explosion06.png"));
	sprite_.setTexture(GAME.getTexture("Resources/explosion07.png"));
	sprite_.setTexture(GAME.getTexture("Resources/explosion08.png"));
	sprite_.setTexture(GAME.getTexture("Resources/explosion09.png"));
	makeDead();
}
