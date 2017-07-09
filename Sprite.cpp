#include "Sprite.h"
#include "Graphics.h"

#include <SDL_image.h>




Sprite::Sprite()
{
}

Sprite::Sprite(Graphics &Graphics, const std::string &FilePath, int SourceX, int SourceY, int Width, int Height,
	float PosX, float PosY) :
	_X(PosX),
	_Y(PosY)
{
	this->_SourceRect.x = SourceX;
	this->_SourceRect.y = SourceY;
	this->_SourceRect.w = Width;
	this->_SourceRect.h = Height;

	SDL_Surface* Surface = Graphics.LoadImage(FilePath);

	this->_SpriteSheet = SDL_CreateTextureFromSurface(Graphics.GetRenderer(), Surface);

	printf(IMG_GetError(),"\n");
	
	if(this->_SpriteSheet == NULL)
	{
		printf("\nError: Unable to load image\n");
	}
}

Sprite::~Sprite()
{
}

void Sprite::update()
{
}

void Sprite::Draw(Graphics &Graphics, int X, int Y)
{
	SDL_Rect DestinationRectangle = { X,Y,this->_SourceRect.w,this->_SourceRect.h};
	Graphics.BlitSurface(this->_SpriteSheet, &this->_SourceRect, &DestinationRectangle);
}

bool Sprite::HasTexture()
{
	if (this->_SpriteSheet == NULL)
	{
		return false;
	}
	else { return true; }
	
}
