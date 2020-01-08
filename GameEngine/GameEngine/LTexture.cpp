#include "LTexture.h"
#include "GameObject2D.h"

LTexture::LTexture(GameObject2D * owner)
{
	Sprite = NULL;
	Owner = owner;
	Width = 0;
	Height = 0;
}


LTexture::~LTexture()
{
	//Dealocate
	Free();
}

bool LTexture::LoadFromFile(std::string path)
{
	//Get rid of pre-existing texture, if any
	Free();

	//Pointer to the texture to be created
	SDL_Texture * newTexture = NULL;

	//Create new surface and load the image to it
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable load image to SDL_surface, cannot create Texture! SDL_Error: %s!\n", SDL_GetError());
		return false;
	}

	//Set Color to be ignored (transparent color)
	SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 255, 255));// (0,255,255) is Cyan in RGB mapping

	//Create a texture from the loaded surface
	newTexture = SDL_CreateTextureFromSurface(Renderer, loadedSurface);
	if (newTexture == NULL)
	{
		printf("Unable to create Texture! SDL_Error: %s!\n", SDL_GetError());
		return false;
	}

	// Get image dimensions
	Width = loadedSurface->w;
	Height = loadedSurface->h;

	//Get rid of the loadedSurface
	SDL_FreeSurface(loadedSurface);

	//Set mTexture and return success
	Sprite = newTexture;
	return Sprite != NULL;
}

void LTexture::Free()
{
	//Free texture if it exists
	if (Sprite != NULL)
	{
		SDL_DestroyTexture(Sprite);
		Sprite = NULL;
		Width = 0;
		Height = 0;
	}
}

int LTexture::GetWidth()
{
	return Width;
}

int LTexture::GetHeight()
{
	return Height;
}

SDL_Texture * LTexture::GetSprite()
{
	return Sprite;
}

void LTexture::SetWindow(SDL_Window * window)
{
	Window = window;
}

void LTexture::SetRenderer(SDL_Renderer * renderer)
{
	Renderer = renderer;
}

SDL_Renderer * LTexture::GetRenderer()
{
	return Renderer;
}

void LTexture::SetGameToWindowRatio(int gameSize)
{
	GameToWindowRatio = gameSize;
}

void LTexture::Render(int x, int y, double angle, SDL_Rect * clipRect, SDL_Point * center, SDL_RendererFlip flip)
{
	if (Sprite == NULL)
	{
		printf("Unable to render texture, Sprite is NULL!\n");
		return;
	}

	PositionX = x;
	PositionY = y;

	SetRenderParameters(PositionX, PositionY);

	//Create Rect espace to pass to the renderer
	SDL_Rect positionRect;
	if (clipRect == NULL) positionRect = {PositionX, PositionY, int(trunc(Width * Owner->GetTransform().Scale.x)), int(trunc(Height*Owner->GetTransform().Scale.y))};
	else positionRect = { x, y, clipRect->w, clipRect->h };

	//Render the texture
	SDL_RenderCopyEx(Renderer, Sprite, clipRect, &positionRect, angle, center, flip);
}

void LTexture::SetColorModulatio(Uint8 red, Uint8 green, Uint8 blue)
{
	//Modulate texture
	SDL_SetTextureColorMod(Sprite, red, green, blue);
}

void LTexture::SetBlendMode(SDL_BlendMode blend)
{
	//Set blending mode
	SDL_SetTextureBlendMode(Sprite, blend);
}

void LTexture::SetAlpha(Uint8 alpha)
{
	//Set Alpha Blending
	SDL_SetTextureAlphaMod(Sprite, alpha);
}

void LTexture::SetRenderParameters(int &positionX, int &positionY)
{
	int windowHeight;
	int windowWidth;

	SDL_GetWindowSize(Window, &windowWidth, &windowHeight);

	positionY = windowHeight - positionY;

	positionX -= Width*Owner->GetTransform().Scale.x / 2;
	positionY -= Height * Owner->GetTransform().Scale.y / 2;
}
