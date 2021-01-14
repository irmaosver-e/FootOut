#include "Menu.h"
#include "SoundSys.h"

bool Menu::MenuRun()
{
	MenuLoad();

	while(true)
	{
		MenuUpdate();
		MenuDraw();
		SDL_Flip(SDLSystem::Instance()->Getscreen());
		
		switch(m_menuopt)
		{
		case 0:
			m_scrtime = 0.0f;
			break;

		case 1:
			if(m_scrtime >= 0.5f)
			{
				m_menuopt = 0;
				return true;
			}
			
		case 2:
			if(m_scrtime >= 0.5f)
			{
				SDLSystem::Instance()->FlipFullScr();
				m_menuopt = 0;
				break;
			}

		case 3:
			if(m_scrtime >= 0.5f)
			{
				return false;
			}

		}
	}
}

void Menu::MenuDraw()
{
	m_menuscr.Drawimage(0,0);
	m_menutext.DisplayText("FootOut", 210 , 160, 65 , 0, 0, 0, 255, 255, 255);
	m_menutext.DisplayText("Press ENTER to Start", 255 , 235, 12 , 0, 0, 0, 255, 255, 255);
	m_menutext.DisplayText("Press ESC for fullscreen", 255 , 250, 12 , 0, 0, 0, 255, 255, 255);
	m_menutext.DisplayText("Press Q to Quit", 255 , 265, 12 , 0, 0, 0, 255, 255, 255);
	
	switch(m_menuopt)
	{
	case 1:
		m_menutext.DisplayText("Press ENTER to Start", 255 , 235, 12 , 100, 0, 0, 255, 255, 255);
		break;

	case 2:
		m_menutext.DisplayText("Press ESC for fullscreen", 255 , 250, 12 , 100, 0, 0, 255, 255, 255);
		break;

	case 3:
		m_menutext.DisplayText("Press Q to Quit", 255 , 265, 12 , 100, 0, 0, 255, 255, 255);
		break;
	}
}

void Menu::MenuLoad()
{
	m_menuscr.Load("Menu.jpg");
	m_menuscr.Caption("FootOut Menu");
	m_menusound.PlayMusic("menu.mp3",-1);
}

void Menu::MenuUpdate()
{
	SDLSystem::Instance()->Update();
	EventHandler::Update();

	float dt = (float)SDLSystem::Instance()->GetDTSecs();
	m_scrtime += dt;
}

void Menu::OnKeyboardEvent(const SDL_KeyboardEvent& Key)
{
	if(Key.keysym.sym == SDLK_KP_ENTER || Key.keysym.sym == SDLK_RETURN)
	{
		if(Key.state == SDL_PRESSED)
		{
			m_menusound.SetSound("select.wav");
			m_menuopt = 1;
		}
	}

	if(Key.keysym.sym == SDLK_ESCAPE && Key.state == SDL_PRESSED)
	{
		m_menusound.SetSound("select.wav");
		m_menuopt = 2;
	}

	if(Key.keysym.sym == SDLK_q && Key.state == SDL_PRESSED)
	{
		m_menusound.SetSound("select.wav");
		m_menuopt = 3;
	}
}


Menu* Menu::instance()
{
	static Menu s;
	return &s;
}

Menu::Menu()
{
	m_menuopt = 0;
}