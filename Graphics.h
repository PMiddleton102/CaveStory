#pragma once

#include <SDL.h>
#include <map>
#include <string>

/* Graphics class
Holds all information dealing with graphics for the game

*/

class Graphics 
{

public:
	Graphics();
	~Graphics();

	/* Sdl_Surface* LoadImage
	Loads an image into the _SpriteSheets map if it doesnt already exist
	As a result, each image will only ever be loaded once
	Returns the image from the map regardless or whether or not it was just loaded
	*/
	SDL_Surface* LoadImage(const std::string &FilePath);
	
	/*void BlitSurface
	Draws a texture to a certain part of the screen
	*/
	void BlitSurface(SDL_Texture* Texture, SDL_Rect* SourceRectangle, SDL_Rect* DestinationRectangle);
	
	/*void Fip
	Renders everything to the screen
	*/
	void Flip();

	/*void Clear
	Clears the screen
	*/

	void Clear();

	/*SDL_Renderer8 GetRenderer
	Returns the renderer
	*/
	SDL_Renderer* GetRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	
	std::map < std::string, SDL_Surface*> _SpriteSheets;

};

