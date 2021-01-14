#include "SoundSys.h"

void SoundSys::Init()
{

	int audio_rate = 22050;
	Uint16 audio_format = AUDIO_S16SYS;
	int audio_channels = 2;
	int audio_buffers = 1096;

	if(Mix_OpenAudio(audio_rate, audio_format, audio_channels, 
	audio_buffers) != 0) 
	{
		fprintf(stderr, "Unable to initialize audio: %s\n", 

		Mix_GetError());
		exit(1);
	}

}

void SoundSys::SetSound(const std::string &file)
{

	Mix_Chunk *sound = NULL;

	sound = Mix_LoadWAV(file.c_str());
	if(sound == NULL) 
	{
	fprintf(stderr, "Unable to load WAV file: %s\n", 

	Mix_GetError());
	return ;
	}

	int channel;

	channel = Mix_PlayChannel(-1, sound, 0);
}

bool SoundSys :: PlayMusic (const std::string &filename, int loop)
{
	static Mix_Music *music = 0;

	if(music)
	{

		Mix_HaltMusic();
		Mix_FreeMusic(music);
	}

	music = Mix_LoadMUS(filename.c_str());

	if(music == NULL)
	{

		printf("Unable to load Ogg file: %s\n", Mix_GetError());
		return false;

	}

	if(Mix_PlayMusic(music,loop) == -1)
	{

		printf("Unable to load Ogg file: %s\n", Mix_GetError());
		return false;

	}

	return true;
}

SoundSys* SoundSys::Instance()
{
	static SoundSys s;
	return &s;
}

SoundSys::SoundSys()
{
}