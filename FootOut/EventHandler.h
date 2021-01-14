#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "SDL.H"

class EventHandler
{
public:
	virtual ~EventHandler(){}
	void Update();

protected:
	
	virtual void OnJoystickAxisEvent(const SDL_JoyAxisEvent&) {}
	virtual void OnJoystickButtonEvent(const SDL_JoyButtonEvent&) {}
	virtual void OnJoystickBallEvent(const SDL_JoyBallEvent&) {}
	virtual void OnJoystickHatEvent(const SDL_JoyHatEvent&) {}
	virtual void OnKeyboardEvent(const SDL_KeyboardEvent&) {}
	virtual void OnQuitEvent();


};
#endif