#include "GameObj.h"
#include "Ball.h"
#include "Rectangle.h"

void GameObj::Load()
{
}

void GameObj::Update()
{
	m_sprite.Update();
}

void GameObj::Draw()
{
	m_sprite.Draw();
}

Rectangle GameObj::GetRectangle() const
{
	Rectangle r;

	r.bottomLeft = m_sprite.GetPosition();
	r.bottomLeft.y += m_texture.GetCellSize().y;
	r.topRight = m_sprite.GetPosition();
	r.topRight.x += m_texture.GetCellSize().x;

	return r;
}