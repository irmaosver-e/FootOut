#ifndef SDLTEXT_H
#define SDLTEXT_H
#include "SDL.h"
#include "SDL_ttf.h"
#include <string>

class SDLText
{
public:
	void DisplayText(const std::string& text, int x, int y, int size, int fR,
					int fG, int fB, int bR, int bG, int bB);
};
#endif
