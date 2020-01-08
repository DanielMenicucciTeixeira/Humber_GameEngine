#ifndef GAME2D_
#define GAME2D_

#include "Game.h"
#include "GameObject2D.h"

#include <SDL_image.h>

class Star2D;
class PhysicsBody2D;
class Game2D: public Game
{
protected:

	//List of all 2D game objects
	std::vector<GameObject2D*> GameObject2DList;

	//Variable used to store game events captured by SDL
	SDL_Event GameEvent;

	//Game Size, scales with window size
	int GameSize = 50;

	void OnCreate();

public:
	Game2D();
	~Game2D();

	void Close();

	virtual void AddToGameObjectList(GameObject * gameObject) override;

	void HandleEvents();

	void Update(float deltaTime);

	void Render();

	void RenderDebug(PhysicsBody2D * target, Star2D * star);

	void DrawVelocity(PhysicsBody2D * target);

	void DrawAcceleration(PhysicsBody2D * target);

	void DrawForceDebug(Star2D * star);

	std::vector<GameObject2D*> GetGameObject2DList();
};
#endif

