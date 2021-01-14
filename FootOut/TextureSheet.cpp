#include "SDL.h"
#include "SDLSystem.h"
#include "TextureSheet.h"

void TextureSheet::SetNumberofCells(int x, int y)
{
	m_cellsX = x;
	m_cellsY = y;	
	m_cellsize.x = m_image ->w / (float)m_cellsX;
	m_cellsize.y = m_image ->h / (float)m_cellsY;
}

const Vec2f& TextureSheet::GetCellSize() const
{
	return m_cellsize;
}

void TextureSheet::Draw(int cell, int x, int y)
{
	SDL_Rect src;
	src.h = m_image ->h / m_cellsY;
	src.w = m_image ->w / m_cellsX;
	src.x = (cell % m_cellsX) * src.w;
	src.y = (cell / m_cellsY) * src.h;


	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_BlitSurface(m_image, &src, SDLSystem::Instance()->Getscreen(), &dest);
}

TextureSheet::TextureSheet()
{
	m_cellsX = 1;
	m_cellsY = 1;
}

