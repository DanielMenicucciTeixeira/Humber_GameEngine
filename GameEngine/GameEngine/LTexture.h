#ifndef LTEXTURE_
#define LTEXTURE_

#include <SDL.h>
#include <SDL_image.h>
#include <string>

class GameObject2D;

class LTexture
{
public:
	//Initializes variables
	LTexture(GameObject2D * owner = NULL);

	//Deloacates memory
	~LTexture();

	//Loads image from specified path
	bool LoadFromFile(std::string path);

	//Delocates texture
	void Free();

	//Gets Image Dimensions
	int GetWidth();
	int GetHeight();

	//Get the hardware texture
	SDL_Texture * GetSprite();

	//Set the game window
	void SetWindow(SDL_Window * window);
	
	//Set the game renderer
	void SetRenderer(SDL_Renderer * renderer);

	//Gets the renderer
	SDL_Renderer * GetRenderer();

	//Recieves how big the game scree is
	void SetGameToWindowRatio(int gameSize);

	//Renders the texture
	void Render(int x, int y, double angle = 0.0, SDL_Rect * clipRect = NULL, SDL_Point * center = NULL, SDL_RendererFlip = SDL_FLIP_NONE);

	//Set color modulation
	void SetColorModulatio(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void SetBlendMode(SDL_BlendMode blend);

	//Sets transparency
	void SetAlpha(Uint8 alpha);

	//Translates game coordinates and sacale to SDL standard and window size
	void SetRenderParameters(int &positionX, int &posixionY);

private:
	//GameObject2D to whom this LTexture belongs
	GameObject2D * Owner;

	//The Actual hardware texture
	SDL_Texture * Sprite;

	//GameWindow
	SDL_Window * Window;
	
	//Game Renderer
	SDL_Renderer * Renderer;

	//Virual game size
	int GameToWindowRatio;

	//Image Dimensions
	int Width;
	int Height;
	int PositionX;
	int PositionY;

};

#endif



