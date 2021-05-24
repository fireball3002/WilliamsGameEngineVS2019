#pragma once
#include "Engine/GameEngine.h"
#include "Stars.h"
class Starspawner : public GameObject
{
public:
	void update(sf::Time& elapsed);
private:
	int timer_ = 0;
};
typedef std::shared_ptr<Starspawner> StarspawnerPtr;