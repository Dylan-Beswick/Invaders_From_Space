#pragma once
#include "GameState.h"
#include "Player.h"
#include "Text.h"
#include "Enemy.h"
#include "Barrier.h"
#include "SDL_mixer.h"

class PlayState :
	public GameState
{
public:
	PlayState();

	virtual void Update(float DeltaTime, SDL_Renderer* Renderer);
	virtual void Draw(SDL_Renderer* Renderer) override;
	virtual void ProcessInput(Input* UserInput) override;

	virtual bool OnEnter(SDL_Renderer* Renderer, SDL_Window* Window) override;
	virtual bool OnExit() override;

protected:
	// store a pointer to the player game character
	Player* PChar;
	// store a pointer to the enemy game character
	Enemy* EChar;
	// store a pointer to the barrier entity
	Barrier* BChar;

	// store the text for the players position
	Text* TXT_PPosition;
	// read the score to the screen
	Text* TXT_Score;

	// background music
	Mix_Music* Music_BG;
};

