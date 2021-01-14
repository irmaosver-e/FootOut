#include "SDL.h"
#include "SDLSystem.h"
#ifdef WIN32
#include <windows.h>
#endif

SDL_Surface* SDLSystem::Getscreen()
{
	return m_screen;
}

int SDLSystem::GetWidth() const
{
	return m_screen -> w;
}

int SDLSystem::GetHeight() const
{
	return m_screen -> h;
}

SDLSystem* SDLSystem::Instance()
{
	static SDLSystem s;
	return &s;
}

bool SDLSystem::Init(bool fullscreen)
{
	SDL_Init(SDL_INIT_EVERYTHING);

	if (fullscreen)
	{
		m_screen = SDL_SetVideoMode(640, 480, 0, SDL_HWSURFACE | SDL_FULLSCREEN | SDL_DOUBLEBUF);
	}
	else
	{
		m_screen = SDL_SetVideoMode(640, 480, 0, SDL_HWSURFACE | SDL_DOUBLEBUF);
	}

	//Count Joysticks
	int NumJs = SDL_NumJoysticks();
	// Check Joysticks
	for (int i = 0; i < NumJs; i++)
	{
		SDL_Joystick* joy = SDL_JoystickOpen(i);

		if(joy)
		{
			SDL_JoystickEventState(SDL_ENABLE);
		}
	}
	m_fullscr = fullscreen;
	return true;
}

void SDLSystem::ReportError(const std::string& ErrorMessage)
{
#ifdef WIN32
	MessageBoxA(0, ErrorMessage.c_str(), "ERROR", MB_ICONSTOP);
#endif
}

float SDLSystem::GetDTSecs()
{
	return m_dt;
}

void SDLSystem::Update()
{
	static int lastTime = SDL_GetTicks();
	int thisTime = SDL_GetTicks();
	m_dt = (float)(thisTime - lastTime)/1000.0f;
	lastTime = thisTime;

	static const float MAX_DT = 0.02f;
	if(m_dt > MAX_DT)
	{
		m_dt = MAX_DT;
	}
}

void SDLSystem::FlipFullScr()
{
	m_fullscr = !m_fullscr;
		Init(m_fullscr);
}

SDLSystem::SDLSystem()
{
	m_screen = 0;
}

SDLSystem::~SDLSystem()
{
	SDL_Quit();
}