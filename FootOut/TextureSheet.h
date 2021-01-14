#ifndef TEXTURESHEET_H
#define TEXTURESHEET_H

#include "SDLImageLoad.h"
#include "Vec2.h"

class TextureSheet : public SDLImageLoad
{
public:
	void SetNumberofCells(int x, int y);
	void Draw(int cell, int x, int y);
	const Vec2f& GetCellSize() const;
	TextureSheet();

private:
	int m_cellsX;
	int m_cellsY;
	Vec2f m_cellsize;
	
};


#endif