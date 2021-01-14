#include "Brick.h"

Brick::Brick()
{
	m_collision = 0;
}

void Brick::SetBRcellsize()
{
	m_BRcellsize = m_texture.GetCellSize();
}

void Brick::SetBrickSize()
{
	SetBRcellsize();
	
	m_buttomright.x = m_BRcellsize.x;
	m_buttomright.y = m_BRcellsize.y - (m_BRcellsize.y /4);
	m_topleft.x = 0;
	m_topleft.y = (m_BRcellsize.y /4);
}

void Brick::SetBrickCol(int c)
{
	m_collision = c;
}

void Brick::Draw()
{
	if (m_collision < 3)
	{
		GameObj::Draw();
	}
}

void Brick::Update()
{
	SetBRframe();
	GameObj::Update();
	//the frames will be drawn here based on velocity !=0
	//SetPaddleVel();
	
		if(m_BRtime >= 0.025f)
		{
			m_BRcell++;
			if(m_BRcell > 24)
			{
				m_BRcell = 0;
			}
			m_sprite.SetCell(m_BRcell);
			m_BRtime = 0.00f;
		}

	Vec2f getvel = m_sprite.GetVelocity();
	Vec2f getacc = m_sprite.GetAccel();
}

void Brick::Load()
{
	m_bricktex[0].Load("brick2.png");
	m_bricktex[0].SetColourK(0,0,0);
	m_bricktex[0].SetNumberofCells(5, 5);

	m_bricktex[1].Load("brick3.png");
	m_bricktex[1].SetColourK(0,0,0);
	m_bricktex[1].SetNumberofCells(5, 5);

	m_texture.Load("brick1.png");
	m_texture.SetColourK(0,0,0);
	m_texture.SetNumberofCells(5, 5);

	SetBrickSize();
	float Center = (640.00f - m_buttomright.x)/2;
	//float Buttom = 480.00f - m_buttomright.y;

	m_sprite.SetTextureSheet(&m_texture);
	m_sprite.SetVelocity(Vec2f(00.0f,00.0f));
	m_sprite.SetPosition(Vec2f(Center , 0.00f)); /*Buttom*/
	m_sprite.SetAccel(Vec2f(0.0f,0.0f));
}

void Brick::SetBrickVel(float x)
{
	Vec2f getvel = m_sprite.GetVelocity();
	getvel.x = x;
	getvel.y = 0.00f;
	m_sprite.SetVelocity(getvel);
}

void Brick::SetBrickAcc(float x)
{
	Vec2f getacc = m_sprite.GetAccel();
	getacc.x = x;
	getacc.y = 0.00f;
	m_sprite.SetAccel(getacc);
}

void Brick::SetBrickPos(Vec2f x)
{
	m_sprite.SetPosition(x);
}

void Brick::SetBRframe()
{
	float dt = (float)SDLSystem::Instance()->GetDTSecs();
	m_BRcell = m_sprite.GetCell();
	m_BRvel = m_sprite.GetVelocity();
	m_BRtime += dt;
}

void Brick::SetBrickTex(int t)
{
	switch(t)
	{
	case 1:
		m_sprite.SetTextureSheet (&m_bricktex[0]);
		break;

	case 2:
		m_sprite.SetTextureSheet (&m_bricktex[1]);
		break;
	}
}

void Brick::BrickBondaries()
{

	Vec2f getpos = m_sprite.GetPosition();

	if(getpos.x <= 0)
	{
		getpos.x = 1 - m_topleft.x;
	}

	if(getpos.x >= 640.0f - m_buttomright.x)
	{
		getpos.x = 639.0f - m_buttomright.x;
	}

	
	m_sprite.SetPosition(getpos);
}

const float Brick::GetPosBrickMid() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.x + (m_buttomright.x / 2);
	return pos;
}

const float Brick::GetPosBrickTop() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.y;
	return pos;
}

const float Brick::GetPosBrickButtom() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.y + m_buttomright.y;
	return pos;
}

const float Brick::GetPosBrickLeft() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.x;
	return pos;
}

const float Brick::GetPosBrickRight() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.x + m_buttomright.x;
	return pos;
}

const int Brick::GetBrickCol() const
{
	return m_collision;
}