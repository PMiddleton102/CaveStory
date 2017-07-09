#pragma once
#include <map>
#include <SDL.h>


class Input
{
public:
	void BeginNewFrame();
	void KeyUpEvent(const SDL_Event& Event);
	void KeyDownEvent(const SDL_Event& Event);

	bool WasKeyPressed(SDL_Scancode Key);
	bool WasKeyReleased(SDL_Scancode Key);
	bool WasKeyHeld(SDL_Scancode Key);

private:
	std::map<SDL_Scancode, bool> _HeldKeys;
	std::map<SDL_Scancode, bool> _PressedKeys;
	std::map<SDL_Scancode, bool> _RealeasedKEys;
	

};