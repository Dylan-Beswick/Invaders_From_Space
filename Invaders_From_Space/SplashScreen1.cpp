#include "SplashScreen1.h"

SplashScreen1::SplashScreen1()
{
	DBColour = { 5, 5, 5, 255 };
	Splash1Title = nullptr;
	SFX_Enter = nullptr;
}

void SplashScreen1::Draw(SDL_Renderer* Renderer)
{
	GameState::Draw(Renderer);

	if (Splash1Title != nullptr) {
		// draw the menu title if it exists
		Splash1Title->Draw(Renderer);
	}
}

bool SplashScreen1::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	SDL_Log("SplashScreen1 Entered...");

	// define a window width and height
	int WWidth, WHeight;
	SDL_GetWindowSize(Window, &WWidth, &WHeight);

	// find the half width and height to get the center of the screen
	int HalfWWidth = SDL_max(WWidth, 1) / 2;
	int HalfWHeight = SDL_max(WHeight, 1) / 2;

	// create the text as an object
	Splash1Title = new Text();
	// define a colour for the title
	SDL_Colour TitleColour = { 255, 255, 255, 255 };
	// Initialise the font
	if (!Splash1Title->InitialiseFont(Renderer, "Assets/VT323-Regular.ttf", 42,
		"Group Dylan Presents", TitleColour, Vector2(HalfWWidth, HalfWHeight))) {
		delete Splash1Title;
		Splash1Title = nullptr;
	}
	else {
		Splash1Title->CenterText(true);
	}

	// define the sound effect
	SFX_Enter = Mix_LoadWAV("Assets/EntryAudio.wav");

	// play the sound effect
	if (SFX_Enter != nullptr) {
		Mix_PlayChannel(-1, SFX_Enter, 0);
	}

	return true;
}

bool SplashScreen1::OnExit()
{
	SDL_Log("Exited SplashScreen1...");

	// deallocate the menu title from memory
	if (Splash1Title != nullptr) {
		delete Splash1Title;
		Splash1Title = nullptr;
	}

	// deallocate from memory
	if (SFX_Enter != nullptr) {
		Mix_FreeChunk(SFX_Enter);
		SFX_Enter = nullptr;
	}

	return true;
}
