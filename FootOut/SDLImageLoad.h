#ifndef SDLIMAGELOAD_H
#define SDLIMAGELOAD_H
#include "SDL_Image.h"
#include <string>

class SDLImageLoad
{
public:
	SDLImageLoad();
	bool Load(const std::string& filename);
	void Caption(const std::string& caption);
	void Drawimage(int x, int y);
	//void Drawimage(const Vec2& vec);
	void SetColourK(unsigned char r, unsigned char g, unsigned char b);

protected:
	SDL_Surface* m_image;
};

#endif