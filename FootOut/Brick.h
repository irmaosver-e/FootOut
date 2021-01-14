#ifndef BRICK_H
#define BRICK_H
#include "GameObj.h"
#include "Vec2.h"
#include "SDLSystem.h"
#include "TextureSheet.h"
#include <string>

class Brick : public GameObj
{
public:
	Brick();
	void Draw();
	void Load();
	void Update();
	void SetBRcellsize();
	void SetBrickSize();
	void SetBrickVel(float x);
	void SetBrickAcc(float x);
	void SetBrickPos(Vec2f x);
	void SetBrickTex(int t);
	void SetBrickCol(int c);
	void SetBRframe();
	const float GetPosBrickMid() const;
	const float GetPosBrickTop() const;
	const float GetPosBrickButtom() const;
	const float GetPosBrickLeft() const;
	const float GetPosBrickRight() const;
	const int GetBrickCol() const;
	void BrickBondaries();

private:

	TextureSheet m_bricktex[2];
	Vec2f m_BRcellsize;
	Vec2f m_buttomright;
	Vec2f m_topleft;
	int m_BRcell;
	float m_BRtime;
	Vec2f m_BRvel;
	Vec2f m_BRpos;
	int m_collision;
};

#endif