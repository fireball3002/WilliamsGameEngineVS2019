#include "Starspawner.h"
// The number of milliseconds between meteor spawns.
const int SPAWN_DELAY = 500;
void Starspawner::update(sf::Time& elapsed) {
	// Determine how much time has passed and adjust our timer.
	int msElapsed = elapsed.asMilliseconds();
	timer_ -= msElapsed;
	// If our timer has elapsed, reset it and spawn a meteor.
	if (timer_ <= 0)
	{
		timer_ = SPAWN_DELAY;
		sf::Vector2u size = GAME.getRenderWindow().getSize();
		// Spawn the meteor off the right side of the screen.
		// We're assuming the meteor isn't more than 100 pixels wide.
		float starX = (float)(size.x + 100);
		// Spawn the meteor somewhere along the height of window, randomly.
		float starY = (float)(rand() % size.y);
		// Create a meteor and add it to the scene
		StarsPtr stars = std::make_shared<Stars>(sf::Vector2f(starX, starY));
		GAME.getCurrentScene().addGameObject(stars);
	}
}