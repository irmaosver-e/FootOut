#include "Paddle.h"

void Paddle::ResetPadPos()
{
	float Center = (640.00f - m_buttomright.x)/2;
	float Buttom = 480.00f - m_buttomright.y;

	m_sprite.SetPosition(Vec2f(Center, Buttom));
}

void Paddle::SetPcellsize()
{
	m_Pcellsize = m_texture.GetCellSize();
}

void Paddle::SetPaddleSize()
{
	SetPcellsize();
	
	m_buttomright.x = m_Pcellsize.x;
	m_buttomright.y = m_Pcellsize.y - (m_Pcellsize.y /4);
	m_topleft.x = 0;
	m_topleft.y = (m_Pcellsize.y /4);
}

void Paddle::Draw()
{
	GameObj::Draw();
}

void Paddle::Update()
{
	SetPframe();
	GameObj::Update();
	//the frames will be drawn here based on velocity !=0
	//SetPaddleVel();
	if(m_Pvel.x != 0) 
	{
		if(m_Ptime >= 0.025f)
		{
			m_Pcell++;
			if(m_Pcell > 24)
			{
				m_Pcell = 0;
			}
			m_sprite.SetCell(m_Pcell);
			m_Ptime = 0.00f;
		}
	}


	Vec2f getvel = m_sprite.GetVelocity();
	Vec2f getacc = m_sprite.GetAccel();

	if((getvel.x > 0 && getacc.x > 0) || (getvel.x < 0 && getacc.x < 0))
	{
		SetPaddleVel(0.00f);
		SetPaddleAcc(0.00f);
	}
}

void Paddle::Load()
{
	m_texture.Load("paddle.png");
	m_texture.SetColourK(0,0,0);
	m_texture.SetNumberofCells(5, 5);

	SetPaddleSize();
	float Center = (640.00f - m_buttomright.x)/2;
	float Buttom = 480.00f - m_buttomright.y;

	m_sprite.SetTextureSheet(&m_texture);
	m_sprite.SetVelocity(Vec2f(00.0f,00.0f));
	m_sprite.SetPosition(Vec2f(Center, Buttom));
	m_sprite.SetAccel(Vec2f(0.0f,0.0f));
	
}

void Paddle::SetPaddleVel(float x)
{
	Vec2f getvel = m_sprite.GetVelocity();
	getvel.x = x;
	getvel.y = 0.00f;
	m_sprite.SetVelocity(getvel);
}

void Paddle::SetPaddleAcc(float x)
{
	Vec2f getacc = m_sprite.GetAccel();
	getacc.x = x;
	getacc.y = 0.00f;
	m_sprite.SetAccel(getacc);
}

void Paddle::SetPframe()
{
	float dt = (float)SDLSystem::Instance()->GetDTSecs();
	m_Pcell = m_sprite.GetCell();
	m_Pvel = m_sprite.GetVelocity();
	m_Ptime += dt;
}

void Paddle::PadBondaries()
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

const float Paddle::GetPosPadMid() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.x + (m_buttomright.x / 2);
	return pos;
}

const float Paddle::GetPosPadTop() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.y;
	return pos;
}

const float Paddle::GetPosPadButtom() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.y + m_buttomright.y;
	return pos;
}

const float Paddle::GetPosPadLeft() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.x;
	return pos;
}

const float Paddle::GetPosPadRight() const
{
	Vec2f getpos = m_sprite.GetPosition();
	float pos = getpos.x + m_buttomright.x;
	return pos;
}