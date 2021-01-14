#include "Ball.h"
#include "SDLSystem.h"
#include "Rectangle.h"
#include "Game.h"
//#include "Paddle.h"

void Ball::SetBcellsize()
{
	m_Bcellsize = m_texture.GetCellSize();
}

void Ball::SetBframe()
{
	float dt = (float)SDLSystem::Instance()->GetDTSecs();
	m_Bcell = m_sprite.GetCell();
	m_Btime += dt;
}

void Ball::SetBallSize()
{
	SetBcellsize();
	// the ball texture size is 320 x 240
	m_buttomright.x = m_Bcellsize.x;
	m_buttomright.y = m_Bcellsize.y;
	m_topleft.x = 0;
	m_topleft.y = 0;
	
}

void Ball::SetBallPos()
{

	float Center = (640.00f - m_buttomright.x)/2;
	float Buttom = 445.00f - m_buttomright.y;

	m_sprite.SetPosition(Vec2f(Center,Buttom));

}

void Ball::SetBallVel(float y)
{
	Vec2f getvel = m_sprite.GetVelocity();
	getvel.x = 0.00f;
	getvel.y = y;
	m_sprite.SetVelocity(getvel);
}

void Ball::SetBallAcc(Vec2f acc)
{
	Vec2f getacc = m_sprite.GetAccel();
	getacc.x = acc.x;
	getacc.y = acc.y;
	m_sprite.SetAccel(getacc);	
}

void Ball::BallBondaries(const Paddle& pad)
{
	int topbyfive = 640/40;
	int goalleft = topbyfive * 15;
	int goalright = topbyfive * 23;

	Vec2f getpos = m_sprite.GetPosition();
	Vec2f getvel = m_sprite.GetVelocity();
	Vec2f getacc = m_sprite.GetAccel();

	float PosMidPad = pad.GetPosPadMid();
	SetBallSize();

	//if ballvel = 0 follow he paddle pos
	if (getvel == (0.0f,0.0f))
	{
		getpos.x = PosMidPad - (m_buttomright.x /2);
	}

	if (getpos.y <= 0 && getpos.y >= -20)
	{
		if(getpos.x <= goalleft || getpos.x >= goalright)
		{
			SoundSys::Instance()->SetSound("bounce.wav");
			getpos.y = 1;
			getvel.y = -getvel.y;
			getacc.y = -getacc.y;
		}
	}
	
	// 480 is the height of the window
	/*if(getpos.y >= 480 - m_buttomright.y)
	{
		getpos.y = 479 - m_buttomright.y;
		getvel.y = -getvel.y;
		getacc.y = -getacc.y;
	}*/

	if(getpos.x <= 0)
	{
		SoundSys::Instance()->SetSound("bounce.wav");
		getpos.x = 1;
		getvel.x = -getvel.x;
		getacc.x = -getacc.x;
	}

	if(getpos.x >= 640.0f - m_buttomright.x)
	{
		SoundSys::Instance()->SetSound("bounce.wav");
		getpos.x = 639.0f - m_buttomright.x;
		getvel.x = -getvel.x;
		getacc.x = -getacc.x;
	}

	m_sprite.SetPosition(getpos);
	m_sprite.SetVelocity(getvel);
	m_sprite.SetAccel(getacc);
}

void Ball::Draw()
{
	m_sprite.Draw();
}

void Ball::Load()
{
	m_texture.Load("Ball.png");
	m_texture.SetColourK(0,0,0);
	m_texture.SetNumberofCells(5, 5);

	SetBallSize();
	float Center = (640.00f - m_buttomright.x)/2;
	float Buttom = 445.00f - m_buttomright.y;

	//initial vel 300 accel 2.0
	m_sprite.SetTextureSheet(&m_texture);
	m_sprite.SetVelocity(Vec2f(00.0f, 00.0f));
	m_sprite.SetPosition(Vec2f(Center, Buttom));
	m_sprite.SetAccel(Vec2f(0.0f,0.0f));

	SetBallSize();
}

void Ball::Update()
{
	SetBframe();
	m_sprite.Update();
	
	if(m_Btime >= 0.025f)
	{
		m_Bcell++;

		if(m_Bcell > 24)
		{
			m_Bcell = 0;
		}
		m_sprite.SetCell(m_Bcell);
		m_Btime = 0.00f;
	}
}

void Ball::CollideWPad(const Paddle& pad)
{

	Rectangle B = GetRectangle();
	Rectangle P = pad.GetRectangle();
	
	float PosTopPad = pad.GetPosPadTop();
	float PosButtomPad = pad.GetPosPadButtom(); 
	float PosLeftPad = pad.GetPosPadLeft();
	float PosRightPad = pad.GetPosPadRight();
	float PosMidPad = pad.GetPosPadMid();

	float PosPadMidLeft = PosMidPad - 0;
	float PosPadMidRight = PosMidPad + 0;
	float PosPadMidY = PosTopPad + (m_buttomright.y/2);

	bool theyCollide = RectanglesIntersect(B,P);

	Vec2f getpos = m_sprite.GetPosition();
	Vec2f getvel = m_sprite.GetVelocity();
	Vec2f getacc = m_sprite.GetAccel();

	float PosTopBall = getpos.y;
	float PosButtomBall = getpos.y + m_buttomright.y;
	float PosLeftBall = getpos.x;
	float PosRightBall = getpos.x + m_buttomright.x;


	if (theyCollide)
	{
		if(PosButtomBall > PosPadMidY)
		{
			if(PosRightBall < PosMidPad)
			{
				getpos.x = (P.bottomLeft.x - 1)- m_buttomright.x;
			}

			if(PosLeftBall > PosMidPad)
			{
				getpos.x = (P.topRight.x +1);
			}

			getvel.x = -getvel.x;
			getacc.x = -getacc.x;
		}

		else if (PosRightBall < PosPadMidLeft || PosLeftBall > PosPadMidRight)
		{
			if(PosRightBall < PosPadMidLeft /*getvel.x >= 0*/)
			{
				getpos.y = (P.topRight.y -1)- m_buttomright.y;
				getvel.y = -getvel.y;
				getvel.x -= 100;
				getacc.y = -getacc.y;
			}

			if(PosLeftBall > PosPadMidRight/*getvel.x < 0*/)
			{
				getpos.y = (P.topRight.y -1)-m_buttomright.y;
				getvel.y = -getvel.y;
				getvel.x += 100;
				getacc.y = -getacc.y;
			}
		}

		else
		{
			getpos.y = (P.topRight.y -1)-m_buttomright.y;
			getvel.y = -getvel.y;
			getacc.y = -getacc.y;
		}

		if(getvel != (0.0f,0.0f))
		{
			SoundSys::Instance()->SetSound("ballkick2.wav");
		}
	}

	m_sprite.SetPosition(getpos);
	m_sprite.SetVelocity(getvel);
	m_sprite.SetAccel(getacc);
}

void Ball::CollideWBrick(Brick* brick)
{

	if(brick->GetBrickCol() >= 3)
	{
		return;
	}

	Rectangle B = GetRectangle();
	Rectangle BR = brick->GetRectangle();
	
	float PosTopBrick = brick->GetPosBrickTop();
	float PosButtomBrick = brick->GetPosBrickButtom(); 
	float PosLeftBrick = brick->GetPosBrickLeft();
	float PosRightBrick = brick->GetPosBrickRight();
	float PosMidBrick = brick->GetPosBrickMid();

	float PosBrickMidLeft = PosMidBrick - 0;
	float PosBrickMidRight = PosMidBrick + 0;
	float PosBrickMidY = PosTopBrick + (m_buttomright.y/2);

	bool theyCollide = RectanglesIntersect(B,BR);

	Vec2f getpos = m_sprite.GetPosition();
	Vec2f getvel = m_sprite.GetVelocity();
	Vec2f getacc = m_sprite.GetAccel();

	float PosTopBall = getpos.y;
	float PosButtomBall = getpos.y + m_buttomright.y;
	float PosLeftBall = getpos.x;
	float PosRightBall = getpos.x + m_buttomright.x;


	if (theyCollide)
	{
		if(PosButtomBall > PosTopBrick)
		{

			if(PosTopBall < PosBrickMidY)
			{
				if(PosRightBall < PosMidBrick)
				{
					getpos.x = (BR.bottomLeft.x - 1)- m_buttomright.x;
				}

				if(PosLeftBall > PosMidBrick)
				{
					getpos.x = (BR.topRight.x +1);
				}
				getvel.x = -getvel.x;
				getacc.x = -getacc.x;
			}

			else if (PosRightBall < PosBrickMidLeft || PosLeftBall > PosBrickMidRight)
			{
				if(PosRightBall < PosBrickMidLeft /*getvel.x >= 0*/)
				{
					getpos.y = (BR.bottomLeft.y +1);
					getvel.y = -getvel.y;
					getvel.x -= 100;
					getacc.y = -getacc.y;
				}

				if(PosLeftBall > PosBrickMidRight/*getvel.x < 0*/)
				{
					getpos.y = (BR.bottomLeft.y +1);
					getvel.y = -getvel.y;
					getvel.x += 100;
					getacc.y = -getacc.y;
				}
			}

			else
			{
				getpos.y = (BR.bottomLeft.y +1);
				getvel.y = -getvel.y;
				getvel.x +=(float)(rand()%150-75);
				getacc.y = -getacc.y;
			}
		}

		else
		{

			if (PosRightBall < PosBrickMidLeft || PosLeftBall > PosBrickMidRight)
			{
				if(PosRightBall < PosBrickMidLeft /*getvel.x >= 0*/)
				{
					getpos.y = (BR.topRight.y -1)- m_buttomright.y;
					getvel.y = -getvel.y;
					getvel.x -= 100;
					getacc.y = -getacc.y;
				}

				if(PosLeftBall > PosBrickMidRight/*getvel.x < 0*/)
				{
					getpos.y = (BR.topRight.y -1)- m_buttomright.y;
					getvel.y = -getvel.y;
					getvel.x += 100;
					getacc.y = -getacc.y;
				}
			}

			else
			{
				getpos.y = (BR.topRight.y -1)-m_buttomright.y;
				getvel.y = -getvel.y;
				getacc.y = -getacc.y;
			}
		}
		SoundSys::Instance()->SetSound("ballkick1.wav");
		int x = 0;
		x = brick->GetBrickCol();
		x++;
		brick->SetBrickTex(x);
		brick->SetBrickCol(x);

		if(x == 1 || x == 2)
		{
			Game::Instance()->SetScore(5);
		}
		if(x == 3)
		{
			Game::Instance()->SetScore(10);
		}
	}

	m_sprite.SetPosition(getpos);
	m_sprite.SetVelocity(getvel);
	m_sprite.SetAccel(getacc);
}

const Vec2f& Ball::GetBallVel() const
{
	return m_sprite.GetVelocity();
}

const Vec2f& Ball::GetBallPos() const
{
	return m_sprite.GetPosition();
}