#include "SDL_Image.h"
#include "SDLImageLoad.h"
#include "SDLSystem.h"
#include <string>
#include <assert.h>

bool SDLImageLoad::Load(const std::string &filename)
{
		m_image = IMG_Load(filename.c_str());
		if(!m_image)
		{
			SDLSystem::Instance()->ReportError(SDL_GetError());
		}
		return (m_image !=0);
}


void SDLImageLoad::Caption(const std::string &caption)
{
	SDL_WM_SetCaption(caption.c_str(),0);
}

void SDLImageLoad::Drawimage(int x, int y)
{
	assert(m_image);

	SDL_Rect src;
	src.x = 0;
	src.y = 0;
	src.h = m_image ->h;
	src.w = m_image ->w;

	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_BlitSurface(m_image, &src, SDLSystem::Instance()->Getscreen(), &dest);

}

void SDLImageLoad::SetColourK(unsigned char r, unsigned char g, unsigned char b)
{
	assert(m_image);

	SDL_SetColorKey(m_image, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(m_image-> format, r, g, b));
}

SDLImageLoad::SDLImageLoad()
{
	m_image = 0;
}