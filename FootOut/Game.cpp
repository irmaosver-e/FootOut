#include "SDL_Image.h"
#include "SDLSystem.h"
#include "TextureSheet.h"
#include "Game.h"
#include <string>
#include "Vec2.h"
#include "EventHandler.h"

void Game::Update()
{
	SDLSystem::Instance()->Update();

	EventHandler::Update();

	float dt = (float)SDLSystem::Instance()->GetDTSecs();
	m_scrtime += dt;
	
	m_ball.BallBondaries(m_paddle);
	m_paddle.PadBondaries();
	m_brick[15].BrickBondaries();

	for(int i = 0; i < 15; i++)
	{
		m_brick[i].BrickBondaries();
		m_ball.CollideWBrick(&m_brick[i]);
	}

	m_ball.CollideWPad(m_paddle);
	m_ball.CollideWBrick(&m_brick[15]);
	
	m_ball.Update();	
	m_paddle.Update();
	m_brick[15].Update();
	
	for (int i = 0; i < 15; i++)
	{
		m_brick[i].Update();
	}

	if(m_ball.GetBallPos().y <= -10)
	{
		//u win
		m_winlose = 1;
	}

	if(m_ball.GetBallPos().y >= 490)
	{
		//u lose
		m_winlose = 2;
		m_lives--;
	}
}

void Game::OnJoystickAxisEvent(const SDL_JoyAxisEvent& Axis)
{
}

void Game::OnJoystickBallEvent(const SDL_JoyBallEvent&)
{
}

void Game::OnJoystickHatEvent(const SDL_JoyHatEvent&)
{
}

//BONGO CONTROLS

void Game::OnJoystickButtonEvent(const SDL_JoyButtonEvent& Button)
{
	if(Button.button == 7 && Vec2f(0.0f,0.0f) == m_ball.GetBallVel())
	{
		m_ball.SetBallVel(-200.00f);
		m_ball.SetBallAcc(Vec2f(0.0f,-2.0f));

	}

	if(Button.button == 1 && Button.button == 3)
	{
		if(Button.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(-700.00f);
			m_paddle.SetPaddleAcc(1500.00f);
		}
	}

	if(Button.button == 1)
	{
		if(Button.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(-200.00f);
			m_paddle.SetPaddleAcc(500.00f);
		}
	}

	if(Button.button == 3)
	{
		if(Button.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(-500.00f);
			m_paddle.SetPaddleAcc(1000.00f);
		}
	}

	if(Button.button == 0 && Button.button == 2)
	{
		if(Button.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(700.00f);
			m_paddle.SetPaddleAcc(-1500.00f);
		}
	}

	if(Button.button == 0)
	{
		if(Button.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(200.00f);
			m_paddle.SetPaddleAcc(-500.00f);
		}
	}

	if(Button.button == 2)
	{
		if(Button.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(500.00f);
			m_paddle.SetPaddleAcc(-1000.00f);
		}
	}
}

//KEYBOARD CONTROLS

void Game::OnKeyboardEvent(const SDL_KeyboardEvent& Key)
{
	if(Key.keysym.sym == SDLK_ESCAPE && Key.state == SDL_PRESSED)
	{
		SDLSystem::Instance()->FlipFullScr();
	}

	if(Key.keysym.sym == SDLK_UP && Vec2f(0.0f,0.0f) == m_ball.GetBallVel())
	{	
		switch(m_level)
		{
		case 1:
			m_ball.SetBallVel(-200.00f);
			m_ball.SetBallAcc(Vec2f(0.0f,-2.0f));
			break;

		case 2:
			m_ball.SetBallVel(-250.00f);
			m_ball.SetBallAcc(Vec2f(0.0f,-2.5f));
			break;

		case 3:
			m_ball.SetBallVel(-300.00f);
			m_ball.SetBallAcc(Vec2f(0.0f,-3.0f));
			break;

		case 4:
			m_ball.SetBallVel(-400.00f);
			m_ball.SetBallAcc(Vec2f(0.0f,-4.0f));
			break;

		case 5:
			m_ball.SetBallVel(-500.00f);
			m_ball.SetBallAcc(Vec2f(0.0f,-5.0f));
			break;
		}
	}

	if(Key.keysym.sym == SDLK_RIGHT)
	{
		if(Key.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(300.00f);
		}
		if(Key.state == SDL_RELEASED)
		{
			m_paddle.SetPaddleVel(0.00f);
		}
	}

	if(Key.keysym.sym == SDLK_LEFT)
	{
		if(Key.state == SDL_PRESSED)
		{
			m_paddle.SetPaddleVel(-300.00f);
		}
		if(Key.state == SDL_RELEASED)
		{
			m_paddle.SetPaddleVel(0.00f);
		}
	}
}

void Game::SetScore(int s)
{
	m_score += s;

	if (m_score%500 == 0)
	{
		m_extlifecounter++;

		if(m_score >= 500 * m_extlifecounter)
		{
			m_lives++;
			m_sound.SetSound("bell.wav");
		}
	}

}

void Game::Reset()
{
	ResetBricks();

	m_winlose = 0;
	m_lives = 3;
	m_level = 1;
	m_score = 0;
	m_extlifecounter = 0;
	m_scrtime = 0.0f;
	
}

void Game::ResetPadBall()
{
	m_ball.SetBallPos();
	m_paddle.ResetPadPos();
	m_ball.SetBallVel(0.0f);
	m_ball.SetBallAcc(Vec2f (0.0f,0.0f));
	m_winlose = 0;
}

void Game::ResetBricks()
{
	for(int i = 0; i < 16; i++)
	{
		m_brick[i].SetBrickCol(0);
	}
}

void Game::Draw()
{
	m_bg[0].Drawimage(0,0);
	m_ball.Draw();
	m_paddle.Draw();

	for (int i = 0; i < 16; i++)
	{
		m_brick[i].Draw();
	}
	GameTxt();

}

void Game::GameTxt()
{
	char buffer[256];

	std::string lives = "Lives: ";
	_itoa_s(m_lives, buffer, 10);
	lives.append(buffer);

	std::string level = "Level: ";
	_itoa_s(m_level, buffer, 10);
	level.append(buffer);

	std::string score = "Score: ";
	_itoa_s(m_score, buffer, 10);
	score.append(buffer);

	m_gametxt.DisplayText(score, 20 , 0, 18 , 255, 255, 0, 0, 128, 0);
	m_gametxt.DisplayText(lives, 20 , 20, 18 , 255, 255, 0, 0, 128, 0);
	m_gametxt.DisplayText(level, 560 , 0, 18 , 255, 255, 0, 0, 128, 0);
}

void Game::LoadWin()
{
	m_musiccount++;
	m_bg[1].Load("win.jpg");
	m_bg[1].Caption("You Rock!!");
	m_bg[1].Drawimage(0,0);
}

void Game::LoadChamp()
{
	m_musiccount++;
	m_bg[1].Load("champion.jpg");
	m_bg[1].Caption("You are the Champion!!");
	m_bg[1].Drawimage(0,0);
}

void Game::LoadLose()
{
	m_musiccount++;
	m_bg[2].Load("lose.jpg");
	m_bg[2].Caption("You Suck!!");
	m_bg[2].Drawimage(0,0);
}

void Game::Load()
{
	m_sound.PlayMusic("game.mp3", -1);
	m_bg[0].Load("Pitch.png");
	m_bg[0].Caption("FootOut");

	m_ball.Load();
	m_paddle.Load();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int b = i * 5 + j;
			m_brick[b].Load();
			m_brick[b].SetBrickPos(Vec2f(j * 125.0f, 60.0f + i * 60.0f));
		}
	}
	m_brick[15].Load();

}

bool Game::Run()
{
	Load();

	while(true)
	{
		Update();

		if(m_winlose == 0)
		{
			Draw();
			m_scrtime = 0.0f;
			m_musiccount = 0;
		}
		
		if(m_winlose == 1)
		{
			if(m_level <= 4)
			{
				LoadWin();
				m_gametxt.DisplayText("NEXT STAGE!", 180 , 0, 50 , 255, 255, 0, 220, 220, 220);

			}
			else
			{
				LoadChamp();
				m_gametxt.DisplayText("Congratulations!", 120 , 400, 60 , 255, 255, 0, 220, 220, 220);
				m_gametxt.DisplayText("By: Ernani da S. Costa", 0 , 0, 16 , 255, 255, 0, 220, 220, 220);

			}

			if(m_musiccount == 1)
			{
				m_score += 100;
				if(m_level <= 4)
				{
					m_sound.PlayMusic("win.mp3", 0);
					m_sound.SetSound("goal.wav");
				}
				else
				{
					m_sound.PlayMusic("champ.mp3", 0);
					m_sound.SetSound("oh_yeah.wav");
				}
			}

			if(m_scrtime >= 3.0f)
			{
				if(m_level > 4)
				{
					Reset();
					return true;
				}
				else
				{
					m_level++;
					Load();
					ResetBricks();
					ResetPadBall();
				}
			}
		}

		if(m_winlose == 2 && m_lives <= 0)
		{
			LoadLose();

			if(m_musiccount == 1)
			{
				m_sound.PlayMusic("lose.mp3", 0);
				m_sound.SetSound("ohh.wav");
			}
			
			if(m_scrtime >= 2.0f)
			{
				Reset();
				return true;
			}		
		}
		
		if(m_winlose == 2 && m_lives > 0)
		{
			ResetPadBall();
		}

		SDL_Flip(SDLSystem::Instance()->Getscreen());
	}
}

Game* Game::Instance()
{
	static Game s;
	return &s;
}

Game::Game()
{
	m_level = 1;
	m_lives = 3;
	m_score = 0;
	m_extlifecounter = 0;
	m_winlose = 0;
	m_scrtime = 0.0f;
	m_musiccount = 0;
}