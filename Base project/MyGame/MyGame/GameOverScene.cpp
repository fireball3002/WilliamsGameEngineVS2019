#include "GameOverScene.h"
#include "GameOverMessage.h"
GameOverScene::GameOverScene(int score, int hscore)
{
	GameOverMessagePtr gameOverMessage = std::make_shared<GameOverMessage>(score, hscore);
	addGameObject(gameOverMessage);
}