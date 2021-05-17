#include "Meteor.h"
#include "Explosion.h"
#include <chrono>
#include <thread>
#include "GameScene.h"
#include "Score.h"


; const float SPEED = 0.25f;
int score_ = 0;

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
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.decreaseLives();
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
		GameScene& scene = (GameScene&)GAME.getCurrentScene();
		scene.increaseScore();
		otherGameObject.makeDead();
	}
	sf::Vector2f pos = sprite_.getPosition();
	sf::FloatRect bounds = sprite_.getGlobalBounds();
	float x = pos.x;
	float y = pos.y;
	float explosionX = x + (bounds.width / 2.0f);
	float explosionY = y + (bounds.height / 2.0f);
	ExplosionPtr explosion = std::make_shared<Explosion>(sf::Vector2f(explosionX, explosionY));
	GAME.getCurrentScene().addGameObject(explosion);
	score_ += 10;
	makeDead();
}
