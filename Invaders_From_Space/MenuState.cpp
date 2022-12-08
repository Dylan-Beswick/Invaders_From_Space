#include "MenuState.h"
#include "Game.h"
#include "PlayState.h"
#include "Character.h"

MenuState::MenuState()
{
	DBColour = { 0, 0, 50, 255 };
	MenuTitle = nullptr;
	SFX_Enter = nullptr;
}

void MenuState::Draw(SDL_Renderer* Renderer)
{
	GameState::Draw(Renderer);

	if (MenuTitle != nullptr) {
		// draw the menu title if it exists
		MenuTitle->Draw(Renderer);
	}
}

void MenuState::ProcessInput(Input* UserInput)
{
	GameState::ProcessInput(UserInput);

	// On Space move to the play state
	if (UserInput->IsKeyDown(SDL_SCANCODE_SPACE)) {
		PlayState* NewState = new PlayState;
		Game::GetGameInstance()->ChangeGameState(NewState, 8);
	}
}

bool MenuState::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	SDL_Log("MenuState Entered...");

	//initiallised the Background texture
	Texture* BackgroundImage = new Texture();
	// load the Background texture
	BackgroundImage->LoadImageFromFile("Assets/background.png", Renderer);
	// construct the Background as a character
	Character* Background = new Character(BackgroundImage, Vector2(-2, -2), 1);
	GameObjectStack.push_back(Background);

	// define a window width and height
	int WWidth, WHeight;
	SDL_GetWindowSize(Window, &WWidth, &WHeight);

	// find the half width and height to get the center of the screen
	int HalfWWidth = SDL_max(WWidth, 1) / 2;
	int HalfWHeight = (SDL_max(WHeight, 1) / 2) + 4;

	// create the text as an object
	MenuTitle = new Text();
	// define a colour for the title
	SDL_Colour TitleColour = { 255, 255, 255, 255 };
	// Initialise the font
	if (!MenuTitle->InitialiseFont(Renderer, "Assets/VT323-Regular.ttf", 42,
		"Invaders From Space", TitleColour, Vector2(HalfWWidth, HalfWHeight))) {
		delete MenuTitle;
		MenuTitle = nullptr;
	}
	else {
		MenuTitle->CenterText(true);
	}

	// define the sound effect
	SFX_Enter = Mix_LoadWAV("Assets/EntryAudio.wav");

	// play the sound effect
	if (SFX_Enter != nullptr) {
		Mix_PlayChannel(-1, SFX_Enter, 0);
	}

	return true;
}

bool MenuState::OnExit()
{
	SDL_Log("Exited MenuState...");

	// deallocate the menu title from memory
	if (MenuTitle != nullptr) {
		delete MenuTitle;
		MenuTitle = nullptr;
	}

	// deallocate from memory
	if (SFX_Enter != nullptr) {
		Mix_FreeChunk(SFX_Enter);
		SFX_Enter = nullptr;
	}

	return true;
}
