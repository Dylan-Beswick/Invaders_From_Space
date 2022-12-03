#include "SplashScreen2.h"

SplashScreen2::SplashScreen2()
{
	DBColour = { 5, 5, 5, 255 };
	Splash2Title = nullptr;
	SFX_Enter = nullptr;
}

void SplashScreen2::Draw(SDL_Renderer* Renderer)
{
	GameState::Draw(Renderer);

	if (Splash2Title != nullptr) {
		// draw the menu title if it exists
		Splash2Title->Draw(Renderer);
	}
}

bool SplashScreen2::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	SDL_Log("SplashScreen2 Entered...");

	// define a window width and height
	int WWidth, WHeight;
	SDL_GetWindowSize(Window, &WWidth, &WHeight);

	// find the half width and height to get the center of the screen
	int HalfWWidth = SDL_max(WWidth, 1) / 2;
	int HalfWHeight = SDL_max(WHeight, 1) / 2;

	// create the text as an object
	Splash2Title = new Text();
	// define a colour for the title
	SDL_Colour TitleColour = { 255, 255, 255, 255 };
	// Initialise the font
	if (!Splash2Title->InitialiseFont(Renderer, "Assets/VT323-Regular.ttf", 42,
		"In association with TheGeekDuo and Last Minute Games", TitleColour, Vector2(HalfWWidth, HalfWHeight))) {
		delete Splash2Title;
		Splash2Title = nullptr;
	}
	else {
		Splash2Title->CenterText(true);
	}

	// define the sound effect
	SFX_Enter = Mix_LoadWAV("Assets/EntryAudio.wav");

	// play the sound effect
	if (SFX_Enter != nullptr) {
		Mix_PlayChannel(-1, SFX_Enter, 0);
	}

	return true;
}

bool SplashScreen2::OnExit()
{
	SDL_Log("SplashScreen2 BufferState...");

	// deallocate the menu title from memory
	if (Splash2Title != nullptr) {
		delete Splash2Title;
		Splash2Title = nullptr;
	}

	// deallocate from memory
	if (SFX_Enter != nullptr) {
		Mix_FreeChunk(SFX_Enter);
		SFX_Enter = nullptr;
	}

	return true;
}
