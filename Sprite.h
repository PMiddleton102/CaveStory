#pragma once
#include "Graphics.h"
#include <SDL.h>
#include <string>
/*Sprite Class
Holds all information about individual sprites
*/

class Sprite
{
public:
	Sprite();
	Sprite(Graphics &Graphics, const std::string &FilePath, int SourceX, int SourceY, int Width, int Height, float PosX, float PosY);
	
	virtual ~Sprite();
	virtual void update();
	void Draw(Graphics &Graphics, int X, int Y);
	bool HasTexture();
private:
	SDL_Rect _SourceRect;
	SDL_Texture* _SpriteSheet;

	float _X, _Y;

};
