#include "SDLText.h"
#include "SDLSystem.h"

void SDLText::DisplayText(const std::string &text, int x, int y, int size, int fR, int fG, int fB, int bR, int bG, int bB)
{
	// Open the font and set to a given parameter
	TTF_Font* font = TTF_OpenFont("impact.ttf", size);

	SDL_Color foreground = {fR, fG, fB}; //Text colour
	SDL_Color background = {bR, bG, bB}; // colour of what's behind the text.

	//this renders the text to a temp surface. there are
	//other text functions, but this one will do fine
	SDL_Surface* temp = TTF_RenderText_Shaded(font, text.c_str(), foreground, background);

	//A struct storing the dest of the text
	SDL_Rect destination = {x, y, 0, 0};

	//Blit the text surface to our window surface, the null specifies the hole surface.
	SDL_BlitSurface(temp, NULL, SDLSystem::Instance()->Getscreen(), &destination);

	//free memory
	SDL_FreeSurface(temp);

	//close the font
	TTF_CloseFont(font);
}
