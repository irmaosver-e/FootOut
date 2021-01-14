#include "SDLSystem.h"
#include "Game.h"
#include "Menu.h"
#include "SoundSys.h"
#include "SDL_ttf.h"

int main(int,char**)
{

	SDLSystem::Instance()->Init(false); //change to true for fullscreen
	SoundSys::Instance()->Init();
	TTF_Init();
	while(true)
	{
		if(Menu::instance()->MenuRun() == false)
		{
			break;
		}
		if(Game::Instance()->Run() == false)
		{
			break;
		}
	}
	
	
	return 0;
}


/*
int audio_rate = 22050;
Uint16 audio_format = AUDIO*/