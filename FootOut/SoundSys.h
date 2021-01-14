#ifndef SOUNDSYS_H
#define SOUNDSYS_H

#include "SDL.h"
#include "SDL_mixer.h"
#include <string>

class SoundSys
{
public:

	SoundSys();

	void Init();
	void SetSound(const std::string& file);
	bool PlayMusic (const std::string& filename, int loop);

	static SoundSys* Instance();

private:
	
	SoundSys(const SoundSys&);

};
#endif

