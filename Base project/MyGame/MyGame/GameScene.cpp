#include "GameScene.h"
#include "Ship.h"
#include "MeteorSpawner.h"
#include "Score.h"
#include "GameOverScene.h"
#include "FileUtility.h"
#include "Background.h"
#include "Starspawner.h"

GameScene::GameScene()
{

	this->score_ = score_;

	BackgroundPtr background = std::make_shared<Background>();
	addGameObject(background);

	StarspawnerPtr starspawner = std::make_shared<Starspawner>();
	addGameObject(starspawner);

	MeteorSpawnerPtr meteorSpawner = std::make_shared<MeteorSpawner>();
	addGameObject(meteorSpawner);

	ScorePtr score = std::make_shared<Score>(sf::Vector2f(10.0f, 10.0f));
	addGameObject(score);

	ShipPtr ship = std::make_shared<Ship>();
	addGameObject(ship);
}

int GameScene::getScore()
{
	return score_;
}

void GameScene::increaseScore()
{
	score_ += 1;
}

int GameScene::getLives()
{
	return lives_;
}

void GameScene::decreaseLives()
{
	--lives_;
	if (lives_ == 0)
	{
		FileUtility f1("score_record.txt");
		
		f1.DecryptContents(24);
		string con = f1.GetContents();
		if (con == "" || con == "\n")
		{
			con = "0";
		}
		hscore = std::stoi(con);
		if (score_ > hscore)
		{
			f1.SetContents(to_string(score_));
		}
		f1.EncryptContents(24);
		GameOverScenePtr gameOverScene = std::make_shared<GameOverScene>(score_, hscore);
		GAME.setScene(gameOverScene);
	}
}
