#ifndef BALL_H
#define BALL_H
#include "GameObj.h"
#include "Paddle.h"
#include "Brick.h"
#include "SDL_mixer.h"
#include "SoundSys.h"

class Ball : public GameObj
{
public:
	void SetBallSize();
	void SetBallPos();
	void SetBcellsize();
	void SetBframe();
	void SetBallVel(float y);
	void SetBallAcc(Vec2f acc);
	
	const Vec2f& GetBallVel() const;
	const Vec2f& GetBallPos() const;

	void BallBondaries(const Paddle& pad);
	void CollideWPad(const Paddle& pad);
	void CollideWBrick(Brick* brick);

	void Update();
	void Draw();
	void Load();

private:

	Vec2f m_buttomright;
	Vec2f m_topleft;
	Vec2f m_Bcellsize;
	int m_Bcell;
	float m_Btime;
};

#endif
