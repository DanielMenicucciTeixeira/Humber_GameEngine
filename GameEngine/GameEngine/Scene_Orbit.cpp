#include "Scene_Orbit.h"
#include <SDL.h>
#include <SDL_image.h>

#include "Game2D.h"
#include "Star2D.h"
#include "PhysicsBody2D.h"


void Scene_Orbit::OnCreate()
{
	// Create Game
		Game2D * StarGame = new Game2D();
	float gravityForce = 1000000;

	//Create Game Objects
	Star2D * Star1 = new Star2D(FVector3(600, 600, 0), 50, 50, gravityForce);
	Star2D * Star2 = new Star2D(FVector3(1400, 600, 0), 50, 50, gravityForce);
	PhysicsBody2D * Planet = new PhysicsBody2D(FVector3(900, 1000, 0), 1, FVector3(200, -200, 0));
	
	//Add to the StarGame ObjectList
	StarGame->AddToGameObjectList(Star1);
	StarGame->AddToGameObjectList(Star2);
	StarGame->AddToGameObjectList(Planet);
	
	//Load Textures
	Star1->GetSprite()->LoadFromFile("Textures/starSprite.png");
	Star2->GetSprite()->LoadFromFile("Textures/starSprite.png");
	Planet->GetSprite()->LoadFromFile("Textures/planetSprite.png");

	float deltaTime = 0.001f;

	while (!StarGame->Quit())
	{
		StarGame->HandleEvents();

		if (!StarGame->Paused())
		{
			Star1->GravityPull(Planet);
			Star2->GravityPull(Planet);
			StarGame->Update(deltaTime);
			StarGame->Render();
			//StarGame->RenderDebug(Planet, Star1);
			SDL_Delay(deltaTime * 1000);
		}
	}

	delete(StarGame);

	printf("Press Enter to end...");
	getchar();
}

Scene_Orbit::Scene_Orbit()
{
	OnCreate();
}


Scene_Orbit::~Scene_Orbit()
{
}
