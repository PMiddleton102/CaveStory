#include "Game.h"
#include <algorithm>
#include <SDL.h>
#include "Graphics.h"
#include "Input.h"
#include <string>


/*
Game Class
This class holds all the information for the MAIN game loop
*/

namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;

}


Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	this->GameLoop();

}

Game::~Game()
{

}

void Game::GameLoop()
{

	Graphics Graphics;
	Input Input;
	SDL_Event Event;
	
	
	//this->_Player = Sprite(Graphics, "MyChar.bpm", 0, 0, 16, 16, 100, 100);
	//this->_Player = Sprite(Graphics, "Content\\Sprite\\MyChar.bmp", 0, 0, 16, 16, 100, 100);
	this->_Player = Sprite(Graphics, "c:\\pm102\\documents\\visual studio 2017\\Projects\\Remake CaveStory\\Content\\Sprite\\MyChar.bmp", 0, 0, 16, 16, 100, 100);

	if (this->_Player.HasTexture() == false)
	{
		printf("NoTexture");
		return;
	}

	

	int LastUpdateTime = SDL_GetTicks();

	//Start the game loop
	while(true)
	{
		Input.BeginNewFrame();

		if (SDL_PollEvent(&Event))
		{
			if (Event.type ==  SDL_KEYDOWN)
			{
				if (Event.key.repeat == 0)
				{
					Input.KeyDownEvent(Event);
				}
				else if (Event.type == SDL_KEYUP)
				{
					Input.KeyUpEvent(Event);
				}
				else if (Event.type == SDL_QUIT)
				{
					return;
				}
			}
			if (Input.WasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
			{
				return;
			}
		}
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ElapsedTimeMS = CURRENT_TIME_MS - LastUpdateTime;
		this->Update(std::min(ElapsedTimeMS, MAX_FRAME_TIME));
		LastUpdateTime = CURRENT_TIME_MS;
	
		this->Draw(Graphics);
	}
}

void Game::Draw(Graphics &Graphics)
{
	Graphics.Clear();

	this->_Player.Draw(Graphics, 100, 100);

	Graphics.Flip();
}

void Game::Update(float ElapsedTime)
{
}
