#include "Game2D.h"
#include "PhysicsBody2D.h"
#include "Star2D.h"
#include <iostream>


void Game2D::OnCreate()
{
	GameWindow = new LWindow();
}

void Game2D::Close()
{
	if (GameObject2DList.size() > 0)
	{
		for (int i = 0; i < GameObject2DList.size(); i++)
		{
			delete(GameObject2DList[i]);
		}
	}

	delete(GameWindow);
}

void Game2D::AddToGameObjectList(GameObject * gameObject)
{
	Game::AddToGameObjectList(gameObject);

	if (dynamic_cast<GameObject2D*>(gameObject))
	{
		GameObject2DList.push_back(dynamic_cast<GameObject2D*>(gameObject));
		dynamic_cast<GameObject2D*>(gameObject)->GetSprite()->SetWindow(GameWindow->GetWindow());
		dynamic_cast<GameObject2D*>(gameObject)->GetSprite()->SetRenderer(GameWindow->GetRenderer());
		dynamic_cast<GameObject2D*>(gameObject)->GetSprite()->SetGameToWindowRatio(GameSize);
	}
}

Game2D::Game2D()
{
		OnCreate();
}


Game2D::~Game2D()
{
	Close();
}

void Game2D::HandleEvents()
{
	if (SDL_PollEvent(&GameEvent) != 0)
	{
		if (GameEvent.type == SDL_QUIT)
		{
			QuitFlag = true;
		}
		if (GameEvent.type == SDL_KEYDOWN)
		{
			switch (GameEvent.key.keysym.sym)
			{
			case SDLK_SPACE:
				ToogleBool(PauseFlag);
				break;

			default:
				break;
			}
		}
	}
}

void Game2D::Update(float deltaTime)
{

	GameObject2D CurrentObject;
	for (int i = 0; i < GameObject2DList.size(); i++)
	{
		GameObject2DList[i]->Update(deltaTime);
	}
}

void Game2D::Render()
{
	SDL_RenderClear(GameWindow->GetRenderer());

	for (int i = 0; i < GameObject2DList.size(); i++)
	{
		if(GameObject2DList[i] != NULL) GameObject2DList[i]->Render();
	}

	SDL_RenderPresent(GameWindow->GetRenderer());
}

void Game2D::RenderDebug(PhysicsBody2D * target, Star2D * star)
{
	DrawVelocity(target);
	DrawAcceleration(target);
	DrawForceDebug(star);

	SDL_RenderPresent(GameWindow->GetRenderer());
}

void Game2D::DrawVelocity(PhysicsBody2D * target)
{
	int cS[2];
	int cE[2];

	cS[0] = target->GetTransform().Position.x;
	cS[1] = (1200 - target->GetTransform().Position.y);

	cE[0] = (target->GetTransform().Position.x + target->GetVelocity().x);
	cE[1] = 1200 - (target->GetTransform().Position.y + target->GetVelocity().y);

	SDL_SetRenderDrawColor(target->GetSprite()->GetRenderer(), 255, 255, 255, 255);
	SDL_RenderDrawLine(target->GetSprite()->GetRenderer(), cS[0], cS[1], cE[0], cE[1]);
	SDL_SetRenderDrawColor(target->GetSprite()->GetRenderer(), 0, 0, 0, 255);
}

void Game2D::DrawAcceleration(PhysicsBody2D * target)
{
	int cS[2];
	int cE[2];

	cS[0] = target->GetTransform().Position.x;
	cS[1] = (1200 - target->GetTransform().Position.y);

	cE[0] = (target->GetTransform().Position.x + target->GetAcceleration().x/5);
	cE[1] = 1200 - (target->GetTransform().Position.y + target->GetAcceleration().y/5);

	SDL_SetRenderDrawColor(target->GetSprite()->GetRenderer(), 0, 255, 0, 255);
	SDL_RenderDrawLine(target->GetSprite()->GetRenderer(), cS[0], cS[1], cE[0], cE[1]);
	SDL_SetRenderDrawColor(target->GetSprite()->GetRenderer(), 0, 0, 0, 255);
}

void Game2D::DrawForceDebug(Star2D * star)
{
	int cS[2];
	int cE[2];

	cS[0] = star->Planet->GetTransform().Position.x;
	cS[1] = (1200 - star->Planet->GetTransform().Position.y);

	cE[0] = (star->Planet->GetTransform().Position.x + star->ForceDebug.x);
	cE[1] = 1200 - (star->Planet->GetTransform().Position.y + star->ForceDebug.y);

	SDL_SetRenderDrawColor(star->GetSprite()->GetRenderer(), 0, 255, 225, 255);
	SDL_RenderDrawLine(star->GetSprite()->GetRenderer(), cS[0], cS[1], cE[0], cE[1]);
	SDL_SetRenderDrawColor(star->GetSprite()->GetRenderer(), 0, 0, 0, 255);
}

std::vector<GameObject2D*> Game2D::GetGameObject2DList()
{
	return GameObject2DList;
}
