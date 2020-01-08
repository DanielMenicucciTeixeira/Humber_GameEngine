#include "LWindow.h"



LWindow::LWindow(int width, int height)
{
	Height = height;
	Width = width;

	OnCreate();
}

LWindow::~LWindow()
{
	Close();
}

void LWindow::OnCreate()
{
	//Create window
	Window = SDL_CreateWindow("SDL_Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Width, Height, SDL_WINDOW_SHOWN);
	if (Window == NULL)//If can't create the window, get out and print the error
	{
		printf("Unable to create window! SDL_Error: %s!\n", SDL_GetError());
		return;
	}

	//Create Renderer
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	if (Renderer == NULL)//If can't create the renderer, get out and print the error
	{
		printf("Unable to create renderer! SDL_Error: %s!\n", SDL_GetError());
		return;
	}

	//Set the renderer color
	SDL_SetRenderDrawColor(Renderer, 0, 0, 0, 0);//Currently set to black
	SDL_RenderClear(Renderer);
	SDL_RenderPresent(Renderer); 
}

void LWindow::Close()
{
	//Destroy window and Renderer
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Window = NULL;
	Renderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Renderer * LWindow::GetRenderer()
{
	return Renderer;
}

SDL_Window * LWindow::GetWindow()
{
	return Window;
}
