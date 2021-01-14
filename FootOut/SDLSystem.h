#ifndef SDLSYSTEM_H
#define SDLSYSTEM_H
#include "SDL.h"
#include <string>

class SDLSystem
{
public:
	static SDLSystem* Instance();
	bool Init(bool fullscreen);
	void ReportError(const std::string& ErrorMessage);
	float GetDTSecs();
	void Update();
	int GetWidth() const;
	int GetHeight() const;
	void FlipFullScr();

	~SDLSystem();

	SDL_Surface* Getscreen();
private:
	SDLSystem();
	SDLSystem(const SDLSystem&);
	SDL_Surface* m_screen;
	float m_dt;
	bool m_fullscr;
};
#endif