#ifndef PADDLE_H
#define PADDLE_H
#include "GameObj.h"
#include "Vec2.h"
#include "SDLSystem.h"

class Paddle : public GameObj
{
public:
	void Draw();
	void Load();
	void Update();
	void ResetPadPos();
	void SetPcellsize();
	void SetPaddleSize();
	void SetPaddleVel(float x);
	void SetPaddleAcc(float x);
	const float GetPosPadMid() const;
	const float GetPosPadTop() const;
	const float GetPosPadButtom() const;
	const float GetPosPadLeft() const;
	const float GetPosPadRight() const;
	void SetPframe();
	void PadBondaries();

private:
	Vec2f m_Pcellsize;
	Vec2f m_buttomright;
	Vec2f m_topleft;
	int m_Pcell;
	float m_Ptime;
	Vec2f m_Pvel;
	Vec2f m_Ppos;
};

#endif