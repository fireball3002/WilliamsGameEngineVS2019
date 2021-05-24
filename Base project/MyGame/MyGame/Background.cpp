#include "Background.h"
#include "Laser.h"
#include <memory>

const float SPEED = 0.2f;

void Background::update(sf::Time& elapsed) {
	sf::Vector2f pos = sprite1.getPosition();
	float x = pos.x;
	float y = pos.y;
	bool is = true;
	int msElapsed = elapsed.asMilliseconds();
	if (is) x -= SPEED * msElapsed;
	if (x < -800)
	{
		x = 800;
	}
	sf::Vector2f pos2 = sprite2.getPosition();
	float x2 = pos2.x;
	float y2 = pos2.y;
	bool is2 = true;
	int msElapsed2 = elapsed.asMilliseconds();
	if (is2) x2 -= SPEED * msElapsed2;
	if (x2 < -800)
	{
		x2 = 800;
	}
	sprite1.setPosition(sf::Vector2f(x, y));
	sprite2.setPosition(sf::Vector2f(x2, y2));
}

Background::Background()
{
	sprite1.setTexture(GAME.getTexture("Resources/background.png"));
	sprite1.setPosition(sf::Vector2f(0, 100));
	sprite2.setTexture(GAME.getTexture("Resources/background.png"));
	sprite2.setPosition(sf::Vector2f(800, 100));
	assignTag("Background");
}
void Background::draw()
{
	GAME.getRenderWindow().draw(sprite1);
	GAME.getRenderWindow().draw(sprite2);
}