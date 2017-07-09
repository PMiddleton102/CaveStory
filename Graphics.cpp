
#include "Graphics.h"
#include <SDL.h>
#include <SDL_image.h>
#include <string>


/* Graphics class
Holds all information dealing with graphics for the game

*/

Graphics::Graphics() 
{
	SDL_CreateWindowAndRenderer(640, 480, 0, &this->_window, &this->_renderer);
	SDL_SetWindowTitle(this->_window, "CaveStory");
}

Graphics::~Graphics() 
{
	SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::LoadImage(const std::string &FilePath)
{
	if(this->_SpriteSheets.count(FilePath) == 0)
	{
		this->_SpriteSheets[FilePath] = IMG_Load(FilePath.c_str());
	}
	if (this->_SpriteSheets[FilePath] == NULL) 
	{
		printf("Unable to load file\n");
	}

	return this->_SpriteSheets[FilePath];
}

void Graphics::BlitSurface(SDL_Texture* Texture, SDL_Rect* SourceRectangle, SDL_Rect* DestinationRectangle)
{
	SDL_RenderCopy(this->_renderer, Texture, SourceRectangle, DestinationRectangle);
}

void Graphics::Flip()
{
	SDL_RenderPresent(this->_renderer);
}

void Graphics::Clear()
{
	SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::GetRenderer() const
{
	return this->_renderer;
}
