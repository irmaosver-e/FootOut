#ifndef GAME_H
#define GAME_H
#include "SDL.h"
#include "EventHandler.h"
#include "SDLImageLoad.h"
#include "Ball.h"
#include "Paddle.h"
#include "Brick.h"
#include "SoundSys.h"
#include "SDLText.h"

class Game : public EventHandler
{
public:
	void Update();
	void Draw();
	void GameTxt();
	void Load();
	void LoadWin();
	void LoadLose();
	void LoadChamp();
	void Reset();
	void ResetPadBall();
	void ResetBricks();
	void SetScore(int s);

	virtual ~Game(){}
	virtual void OnJoystickAxisEvent(const SDL_JoyAxisEvent&);
	virtual void OnJoystickButtonEvent(const SDL_JoyButtonEvent&);
	virtual void OnJoystickBallEvent(const SDL_JoyBallEvent&);
	virtual void OnJoystickHatEvent(const SDL_JoyHatEvent&);
	virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);

	bool Run();
	static Game* Instance();

private:
	Game();
	Game(const Game&);
	int m_level;
	int m_lives;
	int m_score;
	int m_extlifecounter;
	int m_musiccount;
	int m_winlose;
	SDLText m_gametxt;
	Ball m_ball;
	Paddle m_paddle;
	Brick m_brick[16];
	SDLImageLoad m_bg[3];
	float m_scrtime;
	SoundSys m_sound;

};
#endif