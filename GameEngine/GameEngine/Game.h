#ifndef GAME_
#define GAME_

#include "GameObject.h"
#include "LWindow.h"

#include <SDL.h>

#include <vector>

enum eGameState
{
	RUNNING,
	PAUSED,
	GAME_STATES_TOTAL //Used as a reference for how many game states there are, must aways be the last state on the enum declaration
};

class Game
{
protected:
	//Flag used to stop the game loop
	bool QuitFlag;

	//Flag used to pause the game loop
	bool PauseFlag;

	//List of all game objects on the game
	std::vector<GameObject*> GameObjectList;

	//Window where the game is being rendered
	LWindow * GameWindow;

	//Initializes the game
	void OnCreate();

	//Delocates memory when the game ends, to avoid memory loss
	void Close();

	void ToogleBool(bool &boolian);

public:
	Game();
	~Game();

	bool Quit();
	void SetQuit(bool quit);
	bool Paused();

	virtual void AddToGameObjectList(GameObject * gameObject);
};

#endif

