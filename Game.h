#pragma once
#include "Graphics.h"
#include "Sprite.h"

class Game
{
public:
	Game();
	~Game();
private:
	void GameLoop();
	void Draw(Graphics &Graphics);
	void Update(float ElapsedTime);

	Sprite _Player;
};





