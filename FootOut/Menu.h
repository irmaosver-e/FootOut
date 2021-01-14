#ifndef MENU_H
#define MENU_H
#include "Game.h"
#include "SDL.h"
#include "EventHandler.h"
#include "SoundSys.h"
#include "SDLText.h"
#include "SDLSystem.h"

class Menu : public EventHandler
{
public:
	void MenuLoad();
	void MenuDraw();
	bool MenuRun();
	void MenuUpdate();

	virtual ~Menu(){}
	virtual void OnJoystickButtonEvent(const SDL_JoyButtonEvent&){}
	virtual void OnKeyboardEvent(const SDL_KeyboardEvent&);

	static Menu* instance();

private:
	Menu();
	Menu(const Menu&);
	int m_menuopt;
	float m_scrtime;
	SDLImageLoad m_menuscr;
	SoundSys m_menusound;
	SDLText m_menutext;
};

#endif