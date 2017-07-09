#include "Input.h"

/* Input Class
Keeps track of keyboard state
*/
//This function gets called atthe begining of each new frame
//to reset the keys that are no longer relevent
void Input::BeginNewFrame()
{
	this->_PressedKeys.clear();
	this->_RealeasedKEys.clear();

}


//this gets called when a key has been pressed
void Input::KeyDownEvent(const SDL_Event & Event)
{
	this->_PressedKeys[Event.key.keysym.scancode] = true;
	this->_HeldKeys[Event.key.keysym.scancode] = true;
}

//this gets called when a key is released
void Input::KeyUpEvent(const SDL_Event & Event)
{
	this->_RealeasedKEys[Event.key.keysym.scancode] = true;
	this->_HeldKeys[Event.key.keysym.scancode] = false;
}

//this checks if a certain key was pressed during the current frame
bool Input::WasKeyPressed(SDL_Scancode Key)
{
	return this->_PressedKeys[Key];
}

//check if a certain key was released during the current frame
bool Input::WasKeyReleased(SDL_Scancode Key)
{
	return this->_RealeasedKEys[Key];
}

//check if a certain key is currently being held
bool Input::WasKeyHeld(SDL_Scancode Key)
{
	return this->_HeldKeys[Key];
}
