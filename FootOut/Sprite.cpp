#include "Sprite.h"
#include "SDLSystem.h"

Sprite::Sprite()
{
	m_textureSheet = 0;
	m_cell = 0;
	m_time = 0;
}

void Sprite::SetAccel(const Vec2f& a)
{
	m_accel = a;
}

void Sprite::SetVelocity(const Vec2f& v)
{
	m_velocity = v;
}

void Sprite::SetPosition(const Vec2f& p)
{
	m_position = p;
}

void Sprite::SetTextureSheet(TextureSheet* sheet)
{
	m_textureSheet = sheet;
}

void Sprite::SetCell(int c)
{
	m_cell = c;
}

const Vec2f& Sprite::GetVelocity() const
{
	return m_velocity;
}

const Vec2f& Sprite::GetPosition() const
{
	return m_position;
}

const Vec2f& Sprite::GetAccel() const
{
	return m_accel;
}

const int& Sprite::GetCell() const
{
	return m_cell;
}

const float& Sprite::GetTime() const
{
	return m_time;
}

TextureSheet* Sprite::GetTexture()
{
	return m_textureSheet;
}

void Sprite::Draw()
{
	m_textureSheet->Draw(m_cell, (int)m_position.x, (int)m_position.y);
}


void Sprite::Update()
{
	float dt = (float)SDLSystem::Instance()->GetDTSecs();
	
	m_velocity += m_accel * dt;
	m_position += m_velocity * dt;
	m_time += dt;

}