#include "Game.h"



void Game::OnCreate()
{
	QuitFlag = false;
	PauseFlag = false;
}

void Game::Close()
{
	if (GameObjectList.size() > 0)
	{
		for (int i = 0; i < GameObjectList.size(); i++)
		{
			delete(GameObjectList[i]);
		}
	}

	delete(GameWindow);
}

void Game::ToogleBool(bool &boolian)
{
	boolian = !boolian;
}

Game::Game()
{
	OnCreate();
}


Game::~Game()
{
	Close();
}

bool Game::Quit()
{
	return QuitFlag;
}

void Game::SetQuit(bool quit)
{
	QuitFlag = quit;
}

bool Game::Paused()
{
	return PauseFlag;
}

void Game::AddToGameObjectList(GameObject * gameObject)
{
	GameObjectList.push_back(gameObject);
}
