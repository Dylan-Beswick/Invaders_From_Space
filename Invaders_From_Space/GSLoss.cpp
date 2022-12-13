#include "GSLoss.h"
#include "Game.h"

bool GSLoss::OnEnter(SDL_Renderer* Renderer, SDL_Window* Window)
{
	MenuState::OnEnter(Renderer, Window);
	SDL_Log("LossState Entered...");

	//initiallised the Background texture
	Texture* BackgroundImage = new Texture();
	// load the Background texture
	BackgroundImage->LoadImageFromFile("Assets/LossBackground.png", Renderer);
	// construct the Background as a character
	Character* Background = new Character(BackgroundImage, Vector2(0, 0), 1);
	GameObjectStack.push_back(Background);

	// create a score message and add current score value to end
	string NewText = "Your Final Score Was " + to_string(Game::GetGameInstance()->Score);

	// display the new message to screen
	MenuTitle->ChangeText(NewText);

	return false;
}

void GSLoss::ProcessInput(Input* UserInput)
{
	GameState::ProcessInput(UserInput);

	// go to the main menu screen
	if (UserInput->IsKeyDown(SDL_SCANCODE_RETURN)) {
		MenuState* NewState = new MenuState;
		Game::GetGameInstance()->ChangeGameState(NewState, 7);
	}
}
