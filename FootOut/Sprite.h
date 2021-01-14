#ifndef SPRITE_H
#define SPRITE_H

#include "TextureSheet.h"
#include "Vec2.h"
#include <string>

class Sprite
{
public:
	Sprite();

	void SetTextureSheet(TextureSheet* sheet);
	void SetVelocity(const Vec2f& v);
	void SetPosition(const Vec2f& p);
	void SetAccel(const Vec2f& a);
	void SetCell(int c);

	const Vec2f& GetVelocity() const;
	const Vec2f& GetPosition() const;
	const Vec2f& GetAccel() const;
	TextureSheet* GetTexture();

	const int& GetCell() const;
	const float& GetTime() const;

	void Draw();
	void Update();

private:
	TextureSheet* m_textureSheet;
	int m_cell;
	float m_time;
	Vec2f m_position;
	Vec2f m_velocity;
	Vec2f m_accel;
};

#endif