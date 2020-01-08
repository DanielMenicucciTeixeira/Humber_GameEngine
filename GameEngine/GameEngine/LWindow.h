#ifndef LWINDOW_
#define LWINDOW_

#include <SDL.h>
#include <SDL_image.h>

#include <stdio.h>

class LWindow
{
protected:

	int Width;//Horizontal dimension
	int Height;//Vertical dimension

	//The window itself
	SDL_Window * Window = NULL;

	//This window's SLD_Renderer
	SDL_Renderer * Renderer = NULL;

public:

	LWindow(int width = 1200, int height = 600);

	~LWindow();

	void OnCreate();

	void Close();

	SDL_Renderer * GetRenderer();
	SDL_Window * GetWindow();
};
#endif

