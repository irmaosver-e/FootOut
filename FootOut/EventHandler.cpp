#include "EventHandler.h"

void EventHandler::OnQuitEvent()
{
	exit(0);
}

void EventHandler::Update()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			OnQuitEvent();
			break;

		case SDL_JOYAXISMOTION:
			OnJoystickAxisEvent(event.jaxis);
			break;

		case SDL_JOYBALLMOTION:
			OnJoystickBallEvent(event.jball);
			break;

		case SDL_JOYHATMOTION:
			OnJoystickHatEvent(event.jhat);
			break;

		case SDL_JOYBUTTONDOWN:
		case SDL_JOYBUTTONUP:
			OnJoystickButtonEvent(event.jbutton);
			break;

		case SDL_KEYDOWN:
		case SDL_KEYUP:
			OnKeyboardEvent(event.key);
			break;
		}
	}
}