#ifndef GAMEOBJ_H
#define GAMEOBJ_H

#include "Sprite.h"
#include "TextureSheet.h"
#include "Rectangle.h"

class GameObj
{
public:
	void Load();
	void Update();
	void Draw();
	Rectangle GetRectangle() const;

protected:
	Sprite m_sprite;
	TextureSheet m_texture;

private:

};

#endif